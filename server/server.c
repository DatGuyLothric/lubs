#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <err.h>

int main()
{
    FILE *fp;
    fp = fopen("cfg.txt", "r"); /* Getting data from config file */
    char *rport = malloc(1024 * sizeof(char));
    char *rindex = malloc(1024 * sizeof(char));
    char *p403 = malloc(1024 * sizeof(char));
    char *p404 = malloc(1024 * sizeof(char));
    int i = 0;
    int count = 7;
    char c;
    while (count != 0)
    {
        c = fgetc(fp);
        --count;
    }
    c = fgetc(fp);
    while (c != ';')
    {
        rport[i] = c;
        i++;
        c = fgetc(fp);
    }
    c = fgetc(fp);
    i = 0;
    count = 12;
    c;
    while (count != 0)
    {
        c = fgetc(fp);
        --count;
    }
    c = fgetc(fp);
    c = fgetc(fp);
    while (c != ';')
    {
        rindex[i] = c;
        i++;
        c = fgetc(fp);
    }
    c = fgetc(fp);
    i = 0;
    count = 11;
    c;
    while (count != 0)
    {
        c = fgetc(fp);
        --count;
    }
    c = fgetc(fp);
    c = fgetc(fp);
    while (c != ';')
    {
        p403[i] = c;
        i++;
        c = fgetc(fp);
    }
    c = fgetc(fp);
    i = 0;
    count = 11;
    c;
    while (count != 0)
    {
        c = fgetc(fp);
        --count;
    }
    c = fgetc(fp);
    c = fgetc(fp);
    while (c != ';')
    {
        p404[i] = c;
        i++;
        c = fgetc(fp);
    }
    FILE *wp;
    FILE *lg;
    lg = fopen("log.txt", "w");
    char page[1024];
    char page3[1024];
    char page4[1024];
    char wpage[4096];
    char header200[2048] = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n";
    char header403[2048] = "HTTP/1.1 403 READ ERROR\r\nContent-Type: text/html\r\n";
    char header404[2048] = "HTTP/1.1 404 OPEN ERROR\r\nContent-Type: text/html\r\n";
    int rerror = 0;
    if((wp = fopen(rindex, "r")) != NULL) /* Checking if the main page exists and returning it or error page */
    {
        i = 0;
        while ((c = fgetc(wp)) != EOF)
        {
            if (c == EOF)
            {
                if (feof(fp) == 0)
                {
                    rerror = 1;
                    break;
                }
            }
            i++;
        }
        fgets(page, 1024, wp);
        strcat(header200, page);
        strcat(wpage, header200);
    }
    else
    {
        wp = fopen(p404, "r");
        fgets(page4, 1024, wp);
        strcat(header404, page4);
        strcat(wpage, header404);
    }
    if (rerror == 1)
    {
        wp = fopen(p403, "r");
        fgets(page3, 1024, wp);
        strcat(header403, page3);
        strcat(wpage, header403);
    }
    struct sockaddr_in serv_addr;   /* Setting up socket */
    int serv_sock;
    int client_sock;
    serv_sock = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons (atof(rport));
    char ber[] = "Binding error!\n";
    char ler[] = "Listening error!\n";
    char cnf[] = "Connection failed!\n";
    char cns[] = "Connection succeeded!\n";
    if (bind(serv_sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0); /* Setting up stuff and writing data in log file */
    {
        fwrite(&ber, sizeof(char), 15, lg);
        printf("Binding error!");
        exit(EXIT_FAILURE);
    }
    if (listen(serv_sock, 10) == -1);
    {
        fwrite(&ler, sizeof(char), 17, lg);
        printf("Listening error!");
        exit(EXIT_FAILURE);
    }
    while (1)
    {
        client_sock = accept(serv_sock, NULL, NULL);
        if (client_sock == -1)
        {
            fwrite(&cnf, sizeof(char), 19, lg);
            printf("Connection failed!");
            continue;
        }
        fwrite(&cns, sizeof(char), 22, lg);
        printf("Connection succeeded!");
        send(client_sock, wpage, sizeof(wpage), 0);
    }
    close(client_sock);
    fclose(wp);
    fclose(lg);
    fclose(fp);
    return 0;
}
