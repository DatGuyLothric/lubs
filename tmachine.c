#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    FILE *fp;
    int i, j = 0, j2 = 0, j3 = 0, i2, char_el, check = 0, i3 = 0;
    char words[1000][50];
    char begin[1000][50];
    if ((fp = fopen(argv[1], "r")) == NULL) /* Checking if the file exists */
    {
        printf("No file or incorrect path\n");
        return -1;
    }
    else
    {
        for(i = 0; !feof(fp); i++)  /* Read commands */
        {
            fscanf(fp, "%s", &words[i][50]);
        }
    }
    fclose(fp);
    int size = i;
    int nummx = 10000, nummn = 10000;
    int num = 10000;
    int elem[num];
    elem[10000] = 0;
    elem[0] = 0;
    for(i = 0; i <= size; i++)
    {
        if (check != 0) /* Correction of begin func */
        {
            --check;
        }
        else
        if (strcmp(words[i], "inc") == 0)   /* Incr element */
        {
            elem[num]++;
            if (elem[num] > 255)
            {
                printf("Error! The value is more than 255!");
                elem[num] = 0;
            }
            else if (elem[num] < 0)
            {
                printf("Error! The value is less then 0!");
                elem[num] = 0;
            }
        }
        else
            if (strcmp(words[i], "dec") == 0)   /* Decr element */
            {
                --elem[num];
                if (elem[num] > 255)
                {
                    printf("Error! The value is more than 255!");
                    elem[num] = 0;
                }
                else if (elem[num] < 0)
                {
                    printf("Error! The value is less then 0!");
                    elem[num] = 0;
                }
            }
            else
                if (strcmp(words[i], "movl") == 0)  /* Checking left element and going to it */
                {
                    --num;
                    if (num < nummn)
                    {
                        nummn = num;
                        elem[num] = 0;
                    }
                }
                else
                    if (strcmp(words[i], "movr") == 0)  /* Checking right element and going to it */
                        {
                        num++;
                        if (num > nummx)
                            {
                                nummx = num;
                                elem[num] = 0;
                            }
                        }
                    else
                        if (strcmp(words[i], "print") == 0) /* Print element */
                            printf("%d\n", elem[num]);
                        else
                            if (strcmp(words[i], "begin") == 0) /* Begin func */
                            {
                                i3 = i;
                                j = j2++;
                                j3 = j;
                                while (strcmp(words[i3], "end") != 0)
                                {
                                    memcpy (begin[j], words[i3], sizeof(begin[j])); /* Copying begin end commands */
                                    j++;
                                    i3++;
                                    check++;
                                };
                                j2 = j;
                                while (elem[num] != 0)  /* Doing begin end commands */
                                {
                                    for (i2 = j3; i2 <= j2; i2++)
                                    {
                                        if (strcmp(begin[i2], "inc") == 0)
                                            elem[num]++;
                                        else
                                            if (strcmp(begin[i2], "dec") == 0)
                                                --elem[num];
                                    }
                                };
                            }
                            else
                                if (strcmp(words[i], "get") == 0)   /* Getting symbol element */
                                {
                                    printf("Enter symbol:");
                                    char_el = getchar();
                                    elem[num] = elem[num] + char_el;
                                    if (elem[num] > 255)
                                    {
                                        printf("Error! The value is more than 255!");
                                        elem[num] = 0;
                                    }
                                    else if (elem[num] < 0)
                                    {
                                        printf("Error! The value is less then 0!");
                                        elem[num] = 0;
                                    }
                                }
                                else
                                    if (strcmp(words[i], "printc") == 0)
                                        printf("%c\n", elem[num]);  /* Printing element as symbol */
    }
    return 0;
}
