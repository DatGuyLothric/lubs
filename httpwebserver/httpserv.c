#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>

int lis_soc;

typedef struct /* holding return code and filepath to client */
{
	int returncode;
	char *filename;
} httpRequest;

typedef struct /* holding variables in shared memory */
{
	pthread_mutex_t mutexlock;
	int totalbytes;
} sharedVariables;

char *header200 = "HTTP/1.0 200 OK\nContent-Type: text/html\nCharset = UTF-8\n\n";
char *header400 = "HTTP/1.0 400 Bad Request\nContent-Type: text/html\nCharset = UTF-8\n\n";
char *header404 = "HTTP/1.0 404 Not Found\nContent-Type: text/html\nCharset = UTF-8\n\n";

char *getMessage(int fd) /* message from socket */
{
    FILE *sstream;
    if((sstream = fdopen(fd, "r")) == NULL)
    {
        fprintf(stderr, "Error opening file descriptor in getMessage()\n");
        exit(EXIT_FAILURE);
    }
    size_t size = 1;
    char *block;
    if((block = malloc(sizeof(char) * size)) == NULL )
    {
        fprintf(stderr, "Error allocating memory to block in getMessage\n");
        exit(EXIT_FAILURE);
    }
    *block = '\0';
    char *tmp;
    if((tmp = malloc(sizeof(char) * size)) == NULL )
    {
        fprintf(stderr, "Error allocating memory to tmp in getMessage\n");
        exit(EXIT_FAILURE);
    }
    *tmp = '\0';
    int end;
    int oldsize = 1;
    while((end = getline(&tmp, &size, sstream)) > 0)
    {
        if( strcmp(tmp, "\r\n") == 0)
        {
            break;
        }
        block = realloc(block, size + oldsize);
        oldsize += size;
        strcat(block, tmp);
    }
    free(tmp);
    return block;
}

int sendMessage(int fd, char *msg) /* send mess to socket*/
{
    return write(fd, msg, strlen(msg));
}

char *getFileName(char* msg)
{
    char * file;
    if((file = malloc(sizeof(char) * strlen(msg))) == NULL)
    {
        fprintf(stderr, "Error allocating memory to file in getFileName()\n");
        exit(EXIT_FAILURE);
    }
    sscanf(msg, "GET %s HTTP/1.1", file); /* get filename from header */
    char *base;
    if((base = malloc(sizeof(char) * (strlen(file) + 18))) == NULL)
    {
        fprintf(stderr, "Error allocating memory to base in getFileName()\n");
        exit(EXIT_FAILURE);
    }
    char* ph = "public_html";
    strcpy(base, ph);
    strcat(base, file);
    free(file);
    return base;
}

httpRequest parseRequest(char *msg)
{
    httpRequest ret;
    char* filename;
    if((filename = malloc(sizeof(char) * strlen(msg))) == NULL)
    {
        fprintf(stderr, "Error allocating memory to filename in parseRequest()\n");
        exit(EXIT_FAILURE);
    }
    filename = getFileName(msg);
    char *badstring = "..";
    char *test = strstr(filename, badstring);
    int test2 = strcmp(filename, "public_html/");
    FILE *exists = fopen(filename, "r" );
    if(test != NULL )
    {
        ret.returncode = 400;
        ret.filename = "400.html";
    }
    else if(test2 == 0)
    {
        ret.returncode = 200;
        ret.filename = "public_html/index.html";
    }
    else if(exists != NULL )
    {
        ret.returncode = 200;
        ret.filename = filename;
        fclose(exists);
    }
    else
    {
        ret.returncode = 404;
        ret.filename = "404.html";
    }
    return ret;
}

int printFile(int fd, char *filename) /* printout in socket */
{
    FILE *read;
    if((read = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "Error opening file in printFile()\n");
        exit(EXIT_FAILURE);
    }
    int totalsize;
    struct stat st;
    stat(filename, &st);
    totalsize = st.st_size;
    size_t size = 1;
    char *temp;
    if( (temp = malloc(sizeof(char) * size)) == NULL )
    {
        fprintf(stderr, "Error allocating memory to temp in printFile()\n");
        exit(EXIT_FAILURE);
    }
    int end;
    while((end = getline(&temp, &size, read)) > 0)
    {
        sendMessage(fd, temp);
    }
    sendMessage(fd, "\n");
    free(temp);
    return totalsize;
}

void cleanup(int sig) /* cleanup list soc */
{

    printf("Cleaning up connections and exiting.\n");
    if (close(lis_soc) < 0) {
        fprintf(stderr, "Error calling close()\n");
        exit(EXIT_FAILURE);
    }
    shm_unlink("/sharedmem");
    exit(EXIT_SUCCESS);
}

int printHeader(int fd, int returncode)
{
    switch (returncode)
    {
        case 200:
        sendMessage(fd, header200);
        return strlen(header200);
        break;

        case 400:
        sendMessage(fd, header400);
        return strlen(header400);
        break;

        case 404:
        sendMessage(fd, header404);
        return strlen(header404);
        break;
    }
}

int recordTotalBytes(int bytes_sent, sharedVariables *mempointer)
{
    pthread_mutex_lock(&(*mempointer).mutexlock);
    (*mempointer).totalbytes += bytes_sent;
    pthread_mutex_unlock(&(*mempointer).mutexlock);
    return (*mempointer).totalbytes;
}

int main(int argc, char *argv[])
{
    int con_soc; /* Connection socket */
    int port_n = argv[1]; /* Port number */
    struct sockaddr_in server_addr; /* Socket address structure */
    (void) signal(SIGINT, cleanup);
    if ((lis_soc = socket(AF_INET, SOCK_STREAM, 0)) < 0 ) /* Creating listening socket */
    {
        fprintf(stderr, "Error of creating listening socket!\n");
        exit(EXIT_FAILURE);
    }
    memset(&server_addr, 0, sizeof(server_addr)); /* Zeroing server struct and filling in relevant data */
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port_n);
    if (bind(lis_soc, (struct socket_addr *) &server_addr, sizeof(server_addr)) < 0 ) /* Bind to the socket addr */
    {
        fprintf(stderr, "Error calling bind()!\n");
        exit(EXIT_FAILURE);
    }
    if((listen(lis_soc, 10)) == -1) /* Listening */
    {
        fprintf(stderr, "Error Listening\n");
        exit(EXIT_FAILURE);
    }
    shm_unlink("/sharedmem");
    int sharedmem;
    if( (sharedmem = shm_open("/sharedmem", O_RDWR | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR)) == -1)
    {
        fprintf(stderr, "Error opening sharedmem in main() errno is: %s ", strerror(errno));
        exit(EXIT_FAILURE);
    }
    ftruncate(sharedmem, sizeof(sharedVariables) );
    sharedVariables *mempointer;
    mempointer = mmap(NULL, sizeof(sharedVariables), PROT_READ | PROT_WRITE, MAP_SHARED, sharedmem, 0);
    if( mempointer == MAP_FAILED )
    {
        fprintf(stderr, "Error setting shared memory for sharedVariables in recordTotalBytes() error is %d \n ", errno);
        exit(EXIT_FAILURE);
    }
    pthread_mutex_init(&(*mempointer).mutexlock, NULL);
    (*mempointer).totalbytes = 0;
    int addr_size = sizeof(server_addr); /* Addr size */
    int headersize;
    int pagesize;
    int totaldata;
    pid_t pid;
    int chld = 0;
    while(1) /*Loop serv requests*/
    {
        if(chld <= 10)  /*If we can run add process*/
        {
            pid = fork();
            children++;
        }
        if(pid == -1) /*Error*/
        {
            fprintf(stderr, "Fork Error %d\n", errno);
            exit(1);
        }
        if (pid == 0) /*Using chld process*/
        {
            while(1)
            {
                con_soc = accept(lis_soc, (struct socket_addr *) &server_addr, &addr_size); /*Accept conn*/
                if(con_soc == -1) /*Accepting error*/
                {
                    fprintf(stderr, "Error accepting connection \n");
                    exit (1);
                }
                char * header = getMessage(conn_s);
                httpRequest details = parseRequest(header);
                free(header);
                headersize = printHeader(conn_s, details.returncode);
                pagesize = printFile(conn_s, details.filename);
                totaldata = recordTotalBytes(headersize+pagesize, mempointer);
                printf("Process %d served a request of %d bytes. Total bytes sent %d  \n", getpid(), headersize+pagesize, totaldata);
                close(con_soc);
            }
        }
    }
    return EXIT_SUCCESS;
}
