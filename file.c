#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc == 2)
    {
        printf("%.2f C:\n", atof(argv[1]));
        printf("%.2f F\n", atof(argv[1]) * 1.8 + 32);
        printf("%.2f K\n", atof(argv[1]) + 273.15);
        printf("\n");
        printf("%.2f F:\n", atof(argv[1]));
        printf("%.2f C\n", (atof(argv[1]) - 32) / 1.8);
        printf("%.2f K\n", (atof(argv[1]) + 459.67) * 5 / 9);
        printf("\n");
        printf("%.2f K:\n", atof(argv[1]));
        printf("%.2f C\n", atof(argv[1]) - 273.15);
        printf("%.2f F\n", atof(argv[1]) * 9 / 5 - 459.67);
    }
    else
    {
        if (strcmp(argv[2], "C") == 0 || strcmp(argv[2], "c") == 0)
        {
            printf("%.2f C:\n", atof(argv[1]));
            printf("%.2f F\n", atof(argv[1]) * 1.8 + 32);
            printf("%.2f K\n", atof(argv[1]) + 273.15);
        }
        else
        {
            if (strcmp(argv[2], "F") == 0 || strcmp(argv[2], "f") == 0)
            {
                printf("%.2f F:\n", atof(argv[1]));
                printf("%.2f C\n", (atof(argv[1]) - 32) / 1.8);
                printf("%.2f K\n", (atof(argv[1]) + 459.67) * 5 / 9);
            }
            else
            {
                if (strcmp(argv[2], "K") == 0 || strcmp(argv[2], "k") == 0)
                {
                    printf("%.2f K:\n", atof(argv[1]));
                    printf("%.2f C\n", atof(argv[1]) - 273.15);
                    printf("%.2f F\n", atof(argv[1]) * 9 / 5 - 459.67);
                }
            }
        }
    }
    return 0;
}
