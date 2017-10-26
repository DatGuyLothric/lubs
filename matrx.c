#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int minelmnt, mini = 0, minj = 0, i2 = 0, j2 = 0, i, j, brk = 0, frstchr, i3 = 0, j3 = 0, k2 = 0, k1 = 0, errr = 0, gl = 0, tp = 0, gp = 0, mp = 0;
    int matrxa[4][5], matrxu[256][256], matrxb[4][5], matrxc[3][4], endmatrxf[256][256], endmatrxs[256][256];

    printf("Random MatrX (A) is:\n");

    for(i = 0; i < 4; i++)  /* Creating random matrx */
    {
        for(j = 0; j < 5; j++)
        {
            matrxa[i][j] = rand();
            matrxb[i][j] = matrxa[i][j];
            printf("%d ", matrxa[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    printf("Changed MatrX (A) = MatrX (B) is:\n");

    for(j = 0; j < 5; j++)  /* Changing elements */
    {
        matrxb[0][j] = matrxa[3][4 - j];
    }

    for(j = 0; j < 5; j++)
    {
        matrxb[3][j] = matrxa[0][4 - j];
    }

    minelmnt = matrxb[0][0];

    for(i = 0; i < 4; i++)  /* Searching for min element */
    {
        for(j = 0; j < 5; j++)
        {
            if(minelmnt > matrxb[i][j])
            {
                minelmnt = matrxb[i][j];
                mini = i;
                minj = j;
            }
            printf("%d ", matrxb[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    printf("MatrX (B) without string and column with min element = MatrX (C) is:\n");

    for(i = 0; i < 3; i++)  /* Deleting string and column with min element */
    {
        for(j = 0; j < 4; j++)
        {
            if(i2 != mini && j2 != minj)
            {
                matrxc[i][j] = matrxb[i2][j2];
            }
            else
            {
                if(i2 != mini)
                {
                    j2++;
                    matrxc[i][j] = matrxb[i2][j2];
                }
                else
                {
                    i2++;
                    matrxc[i][j] = matrxb[i2][j2];
                }
            }
            j2++;
        }
        i2++;
        j2 = 0;
    }

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf("%d ", matrxc[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    printf("Rules of entering MatrX:\n' ' - end of the element\n',' - end of the string\n'.' - end of the MatrX\n");
    printf("\nExample:\nIf you enter:\n1 2 3 ,4 5 6 ,.\nYou will get:\n1 2 3\n4 5 6\n");

    printf("\n");
    printf("Enter your MatrX (U) defined on the set of integers:\n");

    i = 0;
    j = 0;
    i2 = 0;
    j2 = 0;

    do  /* Function for entering matrx */
    {
        frstchr = getchar();
        switch(frstchr)
        {
            case(' '):
            {
                if ((matrxu[i][j] == 0 && gl == 1) || matrxu[i][j] != 0)
                {
                    j++;
                    gl = 0;
                    tp = 1;
                }
                break;
            }
            case(','):
            {
                i++;
                if (i > 1)  /* Checking if the matrx is right */
                    if (j != j2)
                    {
                        errr = 2;
                        printf("\nMatrX is incorrect!");
                        return -1;
                    }
                j2 = j;
                j = 0;
                gp = 1;
                break;
            }
            case('.'):
            {
                if (gp == 1 && tp == 1 && mp == 1)
                {
                    brk = 1;
                    i2 = i;
                }
                else
                    if (mp != 1)
                    {
                        errr = 2;
                        printf("\nMatrX is incorrect!");
                        return -1;
                    }
                    else
                    {
                        errr = 1;
                        printf("\nYou made a mistake. Please check what you entered.\nMake sure that you followed all the next rules:\nRules of entering MatrX:\n' ' - end of the element\n',' - end of the string\n'.' - end of the MatrX\n\n");
                        brk = 1;
                        return -1;
                    }
                break;
            }
            case('0'):
            {
                ungetc(frstchr, stdin);
                if (scanf("%d", &matrxu[i][j]) != 1)    /* Function that checks if there are no letters in matrx */
                {
                    errr = 1;
                    printf("\nYou made a mistake. Please check what you entered.\nMake sure that you followed all the next rules:\nRules of entering MatrX:\n' ' - end of the element\n',' - end of the string\n'.' - end of the MatrX\n\n");
                    brk = 1;
                    return -1;
                }
                if (matrxu[i][j] == 0)
                    gl = 1;
                break;
            }
            default:
            {
                ungetc(frstchr, stdin);
                if (scanf("%d", &matrxu[i][j]) != 1)    /* Function that checks if there are no letters in matrx */
                {
                    errr = 1;
                    printf("\nYou made a mistake. Please check what you entered.\nMake sure that you followed all the next rules:\nRules of entering MatrX:\n' ' - end of the element\n',' - end of the string\n'.' - end of the MatrX\n\n");
                    brk = 1;
                    return -1;
                }
                mp = 1;
            }
        }
    }
    while(brk != 1);

    if (errr == 0)
    {
        printf("\n");
        printf("Your MatrX (U) is:\n");

        for(i = 0; i < i2 ; i++)
        {
            for(j = 0; j < j2; j++)
            {
                printf("%d ", matrxu[i][j]);
            }
            printf("\n");
        }

        printf("\n");
        printf("MatrX (C) * MatrX (U) = MatrX (E) is:\n");

        if(i2 == 4) /* Checking if we can do a multiplication */
        {
            do  /* Function for matrxs's C and U multiplication */
            {
                do
                {
                    for(i = 0; i < 4; i++)
                    {
                        endmatrxf[i3][j3] = endmatrxf[i3][j3] + matrxc[k1][i] * matrxu[i][k2];
                    }
                    j3++;
                    k2++;
                }
                while (j3 <= i2);
                j3 = 0;
                k1++;
                i3++;
                k2 = 0;
            }
            while(i3 < 3);

            for(i = 0; i < 3 ; i++)
            {
                for(j = 0; j < j2; j++)
                {
                    printf("%d ", endmatrxf[i][j]);
                }
                printf("\n");
            }
        }
        else
            printf("MatrX (E) does not exist cause multiplication is not allowed\n");

        printf("\n");
        printf("MatrX (U) * MatrX (C) = MatrX (F) is:\n");

        if(j2 == 3) /* Checking if we can do a multiplication */
        {
            j3 = 0;
            k1 = 0;
            i3 = 0;
            k2 = 0;

            do  /* Function for matrxs's U and C multiplication */
            {
                do
                {
                    for(i = 0; i < 4; i++)
                    {
                        endmatrxs[i3][j3] = endmatrxs[i3][j3] + matrxu[k1][i] * matrxc[i][k2];
                    }
                    j3++;
                    k2++;
                }
                while (j3 <= i2);
                j3 = 0;
                k1++;
                i3++;
                k2 = 0;
            }
            while(i3 < 3);

            for(i = 0; i < 3 ; i++)
            {
                for(j = 0; j < j2; j++)
                {
                    printf("%d ", endmatrxs[i][j]);
                }
                printf("\n");
            }
        }
        else
            printf("MatrX (F) does not exist cause multiplication is not allowed\n");
    }
    else
        return -1;

    return 0;
}
