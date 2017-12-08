#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    FILE *fp;
    int i, p = 0, pp = 0, ppp = 0, ii, mm;
    char words[1000][50];
    char begin[1000][50];
    if ((fp = fopen(argv[1], "r")) == NULL)
    {
        printf("No file or incorrect path\n");
        return -1;
    }
    else
    {
        for(i = 0; !feof(fp); i++)
        {
            fscanf(fp, "%s", &words[i]);
        }
    }
    fclose(fp);
    int r = i;
    int bbmx = 10000, bbmn = 10000;
    int bb = 10000;
    int ll[bb];
    ll[10000] = 0;
    ll[0] = 0;
    for(i = 0; i <= r; i++)
    {
        if (strcmp(words[i], "inc") == 0)
        {
            ll[bb]++;
            if (ll[bb] > 255)
            {
                printf("Error! The value is more than 255!");
                ll[bb] = 0;
            }
            else if (ll[bb] < 0)
            {
                printf("Error! The value is less then 0!");
                ll[bb] = 0;
            }
        }
        else
            if (strcmp(words[i], "dec") == 0)
            {
                --ll[bb];
                if (ll[bb] > 255)
                {
                    printf("Error! The value is more than 255!");
                    ll[bb] = 0;
                }
                else if (ll[bb] < 0)
                {
                    printf("Error! The value is less then 0!");
                    ll[bb] = 0;
                }
            }
            else
                if (strcmp(words[i], "movl") == 0)
                {
                    --bb;
                    if (bb < bbmn)
                    {
                        bbmn = bb;
                        ll[bb] = 0;
                    }
                }
                else
                    if (strcmp(words[i], "movr") == 0)
                        {
                        bb++;
                        if (bb > bbmx)
                            {
                                bbmx = bb;
                                ll[bb] = 0;
                            }
                        }
                    else
                        if (strcmp(words[i], "print") == 0)
                            printf("%d\n", ll[bb]);
                        else
                            if (strcmp(words[i], "begin") == 0)
                            {
                                p = pp++;
                                ppp = p;
                                while (strcmp(words[i], "end") != 0)
                                {
                                    memcpy (begin[p], words[i], sizeof(begin[p]));
                                    p++;
                                    i++;
                                };
                                pp = p;
                                while (ll[bb] != 0)
                                {
                                    for (ii = ppp; ii <= pp; ii++)
                                    {
                                        if (strcmp(begin[ii], "inc") == 0)
                                            ll[bb]++;
                                        else
                                            if (strcmp(begin[ii], "dec") == 0)
                                                --ll[bb];
                                    }
                                };
                            }
                            else
                                if (strcmp(words[i], "get") == 0)
                                {
                                    mm = getchar();
                                    ll[bb] = ll[bb] + mm;
                                    if (ll[bb] > 255)
                                    {
                                        printf("Error! The value is more than 255!");
                                        ll[bb] = 0;
                                    }
                                    else if (ll[bb] < 0)
                                    {
                                        printf("Error! The value is less then 0!");
                                        ll[bb] = 0;
                                    }
                                }
                                else
                                    if (strcmp(words[i], "printc") == 0)
                                        printf("%c\n", ll[bb]);
    }
    return 0;
}
