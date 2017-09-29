#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    printf("\n");
    if (argc == 2)
    {
        printf("%.2f C:\n", atof(argv[1]));
        if (atof(argv[1]) >= -273.15)
        {
            printf("%.2f F\n", atof(argv[1]) * 1.8 + 32);
            printf("%.2f K\n", atof(argv[1]) + 273.15);
        }
        else
            printf("Error: the result is less then the absolute zero!\n");
        printf("\n");
        printf("%.2f F:\n", atof(argv[1]));
        if (atof(argv[1]) >= -459.67)
        {
        printf("%.2f C\n", (atof(argv[1]) - 32) / 1.8);
        printf("%.2f K\n", (atof(argv[1]) + 459.67) * 5 / 9);
        }
        else
            printf("Error: the result is less then the absolute zero!\n");
        printf("\n");
        printf("%.2f K:\n", atof(argv[1]));
        if (atof(argv[1]) >= 0)
        {
        printf("%.2f C\n", atof(argv[1]) - 273.15);
        printf("%.2f F\n", atof(argv[1]) * 9 / 5 - 459.67);
        }
        else
            printf("Error: the result is less then the absolute zero!\n");
        printf("\n");
    }
    else
    {
        if (argc == 3)
        {
            if (strcmp(argv[2], "C") == 0 || strcmp(argv[2], "c") == 0)
            {
                printf("%.2f C:\n", atof(argv[1]));
                if (atof(argv[1]) >= -273.15)
                {
                    printf("%.2f F\n", atof(argv[1]) * 1.8 + 32);
                    printf("%.2f K\n", atof(argv[1]) + 273.15);
                }
                else
                    printf("Error: the result is less then the absolute zero!\n");
                printf("\n");
            }
            else
            {
                if (strcmp(argv[2], "F") == 0 || strcmp(argv[2], "f") == 0)
                {
                    printf("%.2f F:\n", atof(argv[1]));
                    if (atof(argv[1]) >= -459.67)
                    {
                    printf("%.2f C\n", (atof(argv[1]) - 32) / 1.8);
                    printf("%.2f K\n", (atof(argv[1]) + 459.67) * 5 / 9);
                    }
                    else
                        printf("Error: the result is less then the absolute zero!\n");
                    printf("\n");
                }
                else
                {
                    if (strcmp(argv[2], "K") == 0 || strcmp(argv[2], "k") == 0)
                    {
                        printf("%.2f K:\n", atof(argv[1]));
                        if (atof(argv[1]) >= 0)
                        {
                            printf("%.2f C\n", atof(argv[1]) - 273.15);
                            printf("%.2f F\n", atof(argv[1]) * 9 / 5 - 459.67);
                        }
                        else
                            printf("Error: the result is less then the absolute zero!\n");
                        printf("\n");
                    }
                }
            }
        }
        else
        {
            printf("You entered wrong data!\nEnter temperature you want to convert.\nExample: 36 C\n");
            printf("\n");
        }
        }
    return 0;
}
