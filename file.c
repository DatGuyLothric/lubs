#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    printf("\n");
    char* p;    /* This function checks if the string is not like "217863ghjg786dg" */
    strtol(argv[1], &p, 10);
        if (*p != '\0' && *p != '.')
        {
            printf("Error! You entered wrong data or entered nothing!\nEnter temperature you want to convert.\nExample: 36 C\n");
            printf("\n");
            return -1;
        }
    if (argc == 2)  /* This function checks if there is only 1 argument (value of temp) */
    {
        if (atof(argv[1]) != 0 || strcmp(argv[1], "0") == 0)    /* This function checks if the string is not like "hgfghj" */
        {
            printf("%.2f C:\n", atof(argv[1]));
            if (atof(argv[1]) >= -273.15)   /* This function checks if the value of temp is not less then absolute zero */
            {
                printf("%.2f F\n", atof(argv[1]) * 1.8 + 32);   /* Convert our temp */
                printf("%.2f K\n", atof(argv[1]) + 273.15);
            }
            else
                printf("The result is less then the absolute zero!\n");
            printf("\n");
            printf("%.2f F:\n", atof(argv[1]));
            if (atof(argv[1]) >= -459.67)
            {
                printf("%.2f C\n", (atof(argv[1]) - 32) / 1.8);
                printf("%.2f K\n", (atof(argv[1]) + 459.67) * 5 / 9);
            }
            else
                printf("The result is less then the absolute zero!\n");
            printf("\n");
            printf("%.2f K:\n", atof(argv[1]));
            if (atof(argv[1]) >= 0)
            {
                printf("%.2f C\n", atof(argv[1]) - 273.15);
                printf("%.2f F\n", atof(argv[1]) * 9 / 5 - 459.67);
            }
            else
                printf("The result is less then the absolute zero!\n");
            printf("\n");
        }
        else    /* If the string is like "hgfghj" - Error!*/
        {
            printf("Error! You entered wrong data or entered nothing!\nEnter temperature you want to convert.\nExample: 36 C\n");
            printf("\n");
            return -1;
        }
    }
    else
    {
        if (argc == 3)  /* This function checks if there are only 2 arguments (value of temp and C, F or K) */
        {
            if (atof(argv[1]) != 0 || strcmp(argv[1], "0") == 0)    /* This function checks if the string is not like "hgfghj" */
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
                        printf("The result is less then the absolute zero!\n");
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
                            printf("The result is less then the absolute zero!\n");
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
                                printf("The result is less then the absolute zero!\n");
                            printf("\n");
                        }
                        else
                        {
                            printf("Error! You entered wrong data or entered nothing!\nEnter temperature you want to convert.\nExample: 36 C\n");
                            printf("\n");
                            return -1;
                        }
                    }
                }
            }
            else    /* If the string is like "hgfghj" - Error! */
            {
                printf("Error! You entered wrong data or entered nothing!\nEnter temperature you want to convert.\nExample: 36 C\n");
                printf("\n");
                return -1;
            }
        }
        else    /* If there are more then 2 arguments or there are no arguments - Error! */
        {
            printf("Error! You entered wrong data or entered nothing!\nEnter temperature you want to convert.\nExample: 36 C\n");
            printf("\n");
            return -1;
        }
    }
    return 0;
}
