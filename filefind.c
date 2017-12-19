#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    FILE *fp;
    int i = 0, j = 0, s_num = 1, str = 1, check = 2, f_sym_c, ii = 0, jj = 0, extr = 0;
    char c, s_word[1000], f_sym[999999];
    printf("Enter word for search: ");
    while ((c = getchar()) != '\n') /* Getting word for search */
    {
        s_word[j] = c;
        j++;
    }
    if ((fp = fopen(argv[1], "r")) == NULL) /* Checking if the file exists */
    {
        printf("No file or incorrect path\n");
        return -1;
    }
    else
    {
        while (!feof(fp))   /* Getting file symbols */
        {
            f_sym[i] = getc(fp);
            i++;
        }
        f_sym_c = i;
    }
    while ((ii <= f_sym_c) && (check != 1))
    {
        check = 2;
        if (f_sym[ii] == '\n')  /* Incr line or number of element if needed */
        {
            str++;
            s_num = 0;
        }
        else if (f_sym[ii] == ' ')
        {
            s_num++;
        }
        else
        {
            jj = 0;
            while (((ii - extr) <= j - 1) && (check != 0))  /* Checking if it is the word we need */
            {
                if (s_word[jj] == f_sym[ii])
                {
                    check = 1;
                    jj++;
                    ii++;
                }
                else
                    check = 0;
            }
        }
        extr++;
        ii = extr;
    }
    fclose(fp);
    if (check == 1)
        printf("Line is %d, Number in line is %d", str, s_num++);
    else
        printf("There is no such word in this file!");
    return 0;
}
