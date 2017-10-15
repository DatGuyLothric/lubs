#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int a, b, c, d = 0, e = 0, f = 0, i, j, aa = 0, bb, cc = 0, dd = 0, ee = 0, frstchr;
    int g[4][5], h[256][256], l[4][5], m[3][4];

    printf("MatrX is:\n");

    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 5; j++)
        {
            g[i][j] = rand();
            l[i][j] = g[i][j];
            printf("%d ", g[i][j]);
        }
        printf("\n");
    }

    printf("New MatrX is:\n");

    for(j = 0; j < 5; j++)
    {
        l[0][j] = g[3][4 - j];
    }

    for(j = 0; j < 5; j++)
    {
        l[3][j] = g[0][4 - j];
    }

    a = l[0][0];

    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 5; j++)
        {
            if(a > l[i][j] & d != 1)
            {
                a = l[i][j];
                b = i;
                c = j;
                if(l[i][j] == 0)
                {
                    d = 1;
                }
            }
            printf("%d ", l[i][j]);
        }
        printf("\n");
    }

    printf("New new MatrX is:\n");

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 4; j++)
        {
            if(e != b & f != c)
            {
                m[i][j] = l[e][f];
            }
            else
            {
                if(e != b)
                {
                    f++;
                    m[i][j] = l[e][f];
                }
                else
                {
                    e++;
                    m[i][j] = l[e][f];
                }
            }
            f++;
        }
        e++;
        f = 0;
    }

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    printf("Enter MatrX:\n");

    i = 0;
    j = 0;

    do
    {
        frstchr = getchar();
        switch(frstchr)
        {
            case(' '):
            {
                j++;
                break;
            }
            case(','):
            {
                i++;
                cc = j;
                j = 0;
                break;
            }
            case('.'):
            {
                aa = 1;
                bb = i;
                break;
            }
            default:
            {
                ungetc(frstchr, stdin);
                scanf("%d", &h[i][j]);
            }
        }
    } while(aa != 1);

    printf("Your MatrX is:\n");

    for(i = 0; i < bb ; i++)
    {
        for(j = 0; j < cc; j++)
        {
            printf("%d ", h[i][j]);
        }
        printf("\n");
    }

    return 0;
}
