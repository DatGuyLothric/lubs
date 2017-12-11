#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    int i, ii, ii1, bb, jp, iw = 0, jwl = 1000, jwr = 0, l[1000], ll[1000], kk[1000], j, c[100], p = 0, num = 0, num1 = 0, j1, jv;
    char f[1000][1000], k[5], m[5];
    char d[10][10], n = '\n', cc;
    if ((fp = fopen(/*argv[1]*/"c:/users/денис/desktop/workout.txt", "r")) == NULL)
    {
        printf("No file or incorrect path\n");
        return -1;
    }
    else
    {
        i = 0;
        j = 0;
        while (!feof(fp))
        {
            f[i][j] = getc(fp);
            if (f[i][j] == ' ')
            {
                c[i] = j;
                i++;
                j = 0;
            }
            else
            {
                j++;
            }
        }
    }
    for (i = 0; i < 1000; i++)
    {
        for (j = 0; j < 1000; j++)
            f[i][j] = ' ';
    }
    for (i = 0; i < 1001; i++)
    {
        ll[i] = 10;
    }
    for (i = 0; i < 1001; i++)
    {
        l[i] = 10;
    }
    printf("Command list :\n1. 'r_2' - add root 2\n2. 'n_10_to_p' - add node 10 to parent root\n3. 'n_12_to_10' - add node 12 to node 10\n4. 's_4_to_12' - add node 4 as sibling to node 10 (You can't use it for main root! Use n_X_to_p!)\n5. Enter to enter new command\n6. 'end!' - end of commands.\nExample:\nr_2\nn_10_to_p\nn_3_to_p\nn_12_to_3\ns_4_to_12\nend!\nResult:\n");
    printf("  2\n | |\n10 3\n   |  |\n   12 4\nYou can enter only numbers from 0 to 999! Numbers can't be similar!\n");
    printf("Enter commands:\n");
    while (p != 1)
    {
        cc = getchar();
        switch (cc)
        {
            case 'r':
            {
                i = 0;
                j = 500;
                cc = getchar();
                cc = getchar();
                while (cc != '\n')
                {
                    f[i][j] = cc;
                    cc = getchar();
                    j++;
                }
                f[1][499] = '/';
                f[1][j] = 92;
                jp = j;
                iw = 1;
                jwl = 499;
                jwr = j;
                break;
            }
            case 'n':
            {
                num = 0;
                num1 = 0;
                ii = 0;
                ii1 = 0;
                cc = getchar();
                cc = getchar();
                while (cc != '_')
                {
                    k[ii] = cc;
                    if (ii == 0)
                        num = num + (cc-48)*100;
                        else if (ii == 1)
                            num = num + (cc-48)*10;
                            else if (ii == 2)
                                num = num + (cc-48);
                    cc = getchar();
                    ii++;
                    bb = ii;
                }
                cc = getchar();
                cc = getchar();
                cc = getchar();
                cc = getchar();
                if (cc == 'p')
                {
                    iw = 2;
                    if (ll[1000] == 10)
                    {
                        j = 499;
                        jwl = j - bb;
                        while (ii > -1)
                        {
                            f[2][j] = k[ii];
                            --j;
                            --ii;
                        };
                        ll[1000] = 11;
                        l[num] = 10;
                        kk[num] = 2000 + 499;
                        ll[num] = 10;

                    }
                    else
                    {
                        j1 = jp;
                        while (ii > -1)
                        {
                            f[2][jp] = k[ii];
                            --ii;
                            jp++;
                        }
                        l[num] = 11;
                        kk[num] = 2000 + j1;
                        ll[num] = 10;
                        jwr = jp;
                    }
                }
                else
                {
                    num1 = 0;
                    ii1 = 0;
                    while (cc != '\n')
                    {
                        m[ii1] = cc;
                        if (ii1 == 0)
                                num1 = num1 + (cc-48)*100;
                            else if (ii1 == 1)
                                    num1 = num1 + (cc-48)*10;
                                 else if (ii1 == 2)
                                        num1 = num1 + (cc-48);
                        cc = getchar();
                        ii1++;
                    }
                    if (l[num1] == 10)
                    {
                        if (ll[num1] == 10)
                        {
                            jv = 4;
                            f[(kk[num1]/1000)+1][kk[num1]%1000-4] = '/';
                            while (ii > -1)
                            {
                            f[(kk[num1]/1000)+2][kk[num1]%1000-jv] = k[ii];
                            --ii;
                            jv++;
                            }
                            kk[num] = ((kk[num1]/1000)+2)*1000 + (kk[num1]%1000-4);
                            l[num] = 10;
                            ll[num] = 10;
                            ll[num1] = 11;
                            if (iw < ((kk[num1]/1000)+2))
                                iw = ((kk[num1]/1000)+2);
                            if (jwl > (kk[num1]%1000-jv))
                                jwl = (kk[num1]%1000-jv);
                        }
                        else
                        {
                            jv = 0;
                            f[(kk[num1]/1000)+1][kk[num1]%1000-1] = '|';
                            while (ii > -1)
                            {
                            f[(kk[num1]/1000)+2][kk[num1]%1000-jv] = k[ii];
                            --ii;
                            jv++;
                            }
                            kk[num] = ((kk[num1]/1000)+2)*1000 + (kk[num1]%1000);
                            l[num] = 10;
                            ll[num] = 10;
                            if (iw < ((kk[num1]/1000)+2))
                                iw = ((kk[num1]/1000)+2);
                            if (jwl > (kk[num1]%1000-jv))
                                jwl = (kk[num1]%1000-jv);
                        }
                    }
                    else
                    {
                        if (ll[num1] == 10)
                        {
                            jv = 0;
                            f[(kk[num1]/1000)+1][kk[num1]%1000+1] = '|';
                            while (ii > -1)
                            {
                            f[(kk[num1]/1000)+2][kk[num1]%1000+jv] = k[ii];
                            --ii;
                            jv++;
                            }
                            kk[num] = ((kk[num1]/1000)+2)*1000 + (kk[num1]%1000);
                            l[num] = 11;
                            ll[num] = 10;
                            ll[num1] = 11;
                            if (iw < ((kk[num1]/1000)+2))
                                iw = ((kk[num1]/1000)+2);
                            if (jwr < (kk[num1]%1000+jv))
                                jwr = (kk[num1]%1000+jv);
                        }
                        else
                        {
                            jv = 4;
                            f[(kk[num1]/1000)+1][kk[num1]%1000+4] = 92;
                            while (ii > -1)
                            {
                            f[(kk[num1]/1000)+2][kk[num1]%1000+jv] = k[ii];
                            --ii;
                            jv++;
                            }
                            kk[num] = ((kk[num1]/1000)+2)*1000 + (kk[num1]%1000+4);
                            l[num] = 11;
                            ll[num] = 10;
                            if (iw < ((kk[num1]/1000)+2))
                                iw = ((kk[num1]/1000)+2);
                            if (jwr < (kk[num1]%1000+jv))
                                jwr = (kk[num1]%1000+jv);
                        }
                    }
                }
                break;
            }
            case 's':
            {
                break;
            }
            case 'e':
            {
                p = 1;
                break;
            }
        }
    }
    /*for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
            d[i][j] = ' ';
    }
    /*for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
            printf("%c ", d[i][j]);
        printf("\n");
    }*/
    j = 0;
    if ((fp = fopen("c:/users/денис/desktop/workout.txt", "w")) == NULL)
        printf("error\n");
    else
    {
        for (i = 0; i <= iw; i++)
        {
            for (j = jwl; j <= jwr; j++)
            {
                fwrite (&f[i][j], sizeof(char), 1, fp);
            }
            fwrite (&n, sizeof(char), 1, fp);
        }
    }
    fclose(fp);
    printf("Tree was successfully written in file!\n");
    return 0;
}
