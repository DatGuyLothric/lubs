#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dd = 0, mm = 0, yyyy = 0, b = 0, d = 0, m = 0, y = 0, yy = 0;
    char c;
    printf("Enter the date (format: dd.mm.yyyy!):\n");
    while (b != 1)
    {
        c = getchar();
        if (c != '.')
        {
            ungetc(c, stdin);
            if (scanf("%d", &dd) != 1)
            {
                printf("Error! Wrong format of day");
                return -1;
            }
        }
        else
            b = 1;
    }
    b = 0;
    while (b != 1)
    {
        c = getchar();
        if (c != '.')
        {
            ungetc(c, stdin);
            if (scanf("%d", &mm) != 1)
            {
                printf("Error! Wrong format of month");
                return -1;
            }
        }
        else
            b = 1;
    }
    b = 0;
    while (b != 1)
    {
        c = getchar();
        if (c != '!')
        {
            ungetc(c, stdin);
            if (scanf("%d", &yyyy) != 1)
            {
                printf("Error! Wrong format of year");
                return -1;
            }
        }
        else
            b = 1;
    }
    if (mm < 0 && mm > 12)
    {
         printf("Error! Wrong format of month");
        return -1;
    }
    if (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12)
        if (dd < 0 || dd > 31)
    {
        printf("Error! Wrong format of day");
        return -1;
    }
    if (mm == 4 || mm == 6 || mm == 9 || mm == 11)
        if (dd < 0 || dd > 30)
    {
        printf("Error! Wrong format of day");
        return -1;
    }
    if (mm == 2)
        if (yyyy%4 == 0)
    {
        if (dd < 0 || dd > 28)
        {
            printf("Error! Wrong format of day");
        return -1;
        }
    } else if (dd < 0 || dd > 29)
    {
        printf("Error! Wrong format of day");
        return -1;
    }
    if (mm == 1 || mm == 10)
        m = 1;
    else if (mm == 5)
            m = 2;
    else if (mm == 8)
            m = 3;
    else if (mm == 2 || mm == 3 || mm == 11)
            m = 4;
    else if (mm == 6)
            m = 5;
    else if (mm == 9 || mm == 12)
            m = 6;
    else if (mm == 4 || mm == 7)
            m = 0;
    else
    {
        printf("Error! You entered wrong month!");
        return -1;
    }
    if ((yyyy/100)%4 == 0)
        {y = 6; yy = (y + yyyy%100 + (yyyy%100)/4)%7;}
    else if((yyyy/100)%4 == 1)
        {y = 4; yy = (y + yyyy%100 + (yyyy%100)/4)%7;}
    else if((yyyy/100)%4 == 2)
        {y = 2; yy = (y + yyyy%100 + (yyyy%100)/4)%7;}
    else if((yyyy/100)%4 == 3)
        {y = 0; yy = (y + yyyy%100 + (yyyy%100)/4)%7;}
    d = (dd + m + yy)%7;
    if (d == 0)
        printf("It is Saturday!");
    else if (d == 1)
        printf("It is Sunday!");
    else if (d == 2)
        printf("It is Monday!");
    else if (d == 3)
        printf("It is Tuesday!");
    else if (d == 4)
        printf("It is Wednesday!");
    else if (d == 5)
        printf("%It is Thursday!");
    else if (d == 6)
        printf("It is Friday!");
    return 0;
}
