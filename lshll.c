#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

char **enter(void);
int func(char **e_line);
int lsh_cd(char **e_line);
int lsh_help(char **e_line);
int lsh_exit(char **e_line);

int main(int argc, char *argv[])
{
    int s_func = 1;
    char **e_line;
    do /* Doing main func while command is not exit */
    {
        printf("> ");
        e_line = enter();
        s_func = func(e_line);
    }
    while (s_func != 0);
    return EXIT_SUCCESS;
}

char **enter(void) /* Function for getting commands and arguments from line */
{
    int c_end = 0;
    int size = 1024;
    int i = 0;
    char *c_line = malloc(sizeof(char) * size);
    int c;
    if(!c_line)
    {
        printf("Memory error!\n");
        exit(EXIT_FAILURE);
    }
    while (c_end != 1) /* Read line */
    {
        c = getchar();
        if (c == EOF || c == '\n')
        {
            c_line[i] = '\0';
            c_end = 1;
            i = 0;
        }
        else
        {
            c_line[i] = c;
        }
        i++;
        if (i >= size)
        {
            size += 1024;
            c_line = realloc(c_line, size);
            if (!c_line)
            {
                printf("Memory error!\n");
                exit(EXIT_FAILURE);
            }
        }
    }
    char **e_words = malloc(size * sizeof(char*));
    char *e_word;
    i = 0;
    if (!e_words)
    {
        printf("Memory error!\n");
        exit(EXIT_FAILURE);
    }
    e_word = strtok(c_line, " \t\r\n\a"); /* Getting commands and arguments from line */
    while (e_word != NULL)
    {
        e_words[i] = e_word;
        i++;
        if (i >= size)
        {
            size += 1024;
            c_line = realloc(e_words, size);
            if (!e_words)
            {
                printf("Memory error!\n");
                exit(EXIT_FAILURE);
            }
        }
        e_word = strtok(NULL, " \t\r\n\a");
    }
    e_words[i] = NULL;
    return e_words;
}

int func(char **e_line) /* Function for sending arguments to command functions */
{
    if (e_line[0] == NULL)
    {
        return 1;
    }
    if (strcmp(e_line[0], "cd") == 0)
    {
        return (lsh_cd)(e_line);
    }
    else if (strcmp(e_line[0], "help") == 0)
         {
             return (lsh_help)(e_line);
         }
         else if (strcmp(e_line[0], "exit") == 0)
              {
                  return (lsh_exit)(e_line);
              }
    return 1;
}

int lsh_cd(char **e_line) /* CD function */
{
    if (e_line[1] == NULL) /* Checking arguments */
    {
        printf("Expecting argument to \"cd\"!\n");
    }
    else
    {
        if (chdir(e_line[1]) != 0)
        {
            perror("lsh");
        }
    }
    return 1;
}

int lsh_help(char **e_line) /* Help function */
{
    printf("  You can use following commands:\n");
    printf("  cd\n  help\n  exit\n");
    return 1;
}

int lsh_exit(char **e_line) /* Exit function */
{
    return 0;
}
