#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dd = 0, mm = 0, yyyy = 0, cyc_end = 0, d_form = 0, m_form = 0, y_form = 0, y_form2 = 0;
    char c;
    printf("Enter the date (format: dd.mm.yyyy!):\n");
    while (cyc_end != 1) /* Cycle for getting day data */
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
            cyc_end = 1;
    }
    cyc_end = 0;
    while (cyc_end != 1)    /* Cycle for getting month data */
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
            cyc_end = 1;
    }
    cyc_end = 0;
    while (cyc_end != 1)    /* Cycle for getting month data */
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
            cyc_end = 1;
    }
    if (mm < 0 && mm > 12) /* Checking if the day/month exists */
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
    if (mm == 1 || mm == 10)    /* Getting m_form for our formula */
        m_form = 1;
    else if (mm == 5)
            m_form = 2;
         else if (mm == 8)
                m_form = 3;
              else if (mm == 2 || mm == 3 || mm == 11)
                        m_form = 4;
                   else if (mm == 6)
                            m_form = 5;
                        else if (mm == 9 || mm == 12)
                                m_form = 6;
                             else if (mm == 4 || mm == 7)
                                    m_form = 0;
                                  else
                                  {
                                      printf("Error! You entered wrong month!");
                                      return -1;
                                  }
    if ((yyyy/100)%4 == 0)  /* Getting y_form2 for our formula */
    {
        y_form = 6;
        y_form2 = (y_form + yyyy%100 + (yyyy%100)/4)%7;
    }
    else if((yyyy/100)%4 == 1)
         {
            y_form = 4;
            y_form2 = (y_form2 + yyyy%100 + (yyyy%100)/4)%7;
         }
         else if((yyyy/100)%4 == 2)
              {
                  y_form = 2;
                  y_form2 = (y_form2 + yyyy%100 + (yyyy%100)/4)%7;
              }
              else if((yyyy/100)%4 == 3)
                   {
                       y_form = 0;
                       y_form2 = (y_form + yyyy%100 + (yyyy%100)/4)%7;
                   }
    d_form = (dd + m_form + y_form2)%7; /* Formula for getting day we need */
    if (d_form == 0)
        printf("It is Saturday!");
    else if (d_form == 1)
            printf("It is Sunday!");
         else if (d_form == 2)
                printf("It is Monday!");
              else if (d_form == 3)
                    printf("It is Tuesday!");
                   else if (d_form == 4)
                            printf("It is Wednesday!");
                        else if (d_form == 5)
                                printf("%It is Thursday!");
                             else if (d_form == 6)
                                    printf("It is Friday!");
    return 0;
}
