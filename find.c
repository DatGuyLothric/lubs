#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(/*int argc, char* argv[]*/)
{
    FILE *fp;
    int i = 0, b = 0, n = 1, s = 1, p = 2, t, g = 0, l = 0, k = 0;
    char c, w[1000], f[999999];
    printf("Enter word for search: ");
    while ((c = getchar()) != '\n')
    {
        w[b] = c;
        b++;
    }
    if ((fp = fopen(/*argv[1]*/"c:/users/денис/desktop/3.txt", "r")) == NULL)
    {
        printf("No file or incorrect path\n");
        return -1;
    }
    else
    {
        while (!feof(fp))
        {
            f[i] = getc(fp);
            i++;
        }
        t = i;
    }
    while ((g <= t) && (p != 1))
    {
        p = 2;
        if (f[g] == '\n')
        {
            s++;
            n = 0;
        }
        else if (f[g] == ' ')
        {
            n++;
        }
        else
        {l = 0; while (((g - k) <= b - 1) && (p != 0))
        {
            if (w[l] == f[g])
            {
                p = 1;
                l++;
                g++;
            }
            else
                p = 0;
        }}
        k++;
        g = k;
    }
    fclose(fp);
    if (p == 1)
        printf("Line is %d, Number in line is %d", s, n);
    else
        printf("There is no such word in this file!");
    return 0;
}
