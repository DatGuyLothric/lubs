#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int frstchr;
float stk[256];
int i = 1;
float stkelmnt;
float crctn;
int blck = 0;
int errr = 0;
int chck = 0;

float pop(void) /* Stack function pop */
{
    --chck;
    if (chck < 0)   /* If there are no more elements in stack - Error! */
        errr = 1;
    return stk[--i];
};

float push(float stkelmnt)  /* Stack function push */
{
    stk[i++] = stkelmnt;
    chck++;
};

int main()
{
    printf("This is a reverse polish notation calculator.\nYou can use only: '=' '-' '+' '*' '/' and numbers.\nEnter '=' to get a result.\n");
    do
    {
        frstchr = getchar();
        switch(frstchr)
        {
            case('\n'):
            {
                break;
            }
            case(' '):
            {
                break;
            }
            case('+'):
            {
                push(pop() + pop());
                break;
            }
            case('-'):
            {
                ungetc(frstchr, stdin);
                if (scanf("%f", &stkelmnt) != 1)    /* Function checks if the '-' is arithmetic operation or part of number */
                {
                    crctn = pop();  /* Have to do a correction cause of stack logic */
                    push(pop() - crctn);
                }
                else
                    push(stkelmnt);
                break;
            }
            case('*'):
            {
                push(pop() * pop());
                break;
            }
            case('/'):
            {
                crctn = pop();
                if (crctn == 0) /* Function checks if divider is not 0 */
                {
                    printf("Something went wrong.\nx/0 is not allowed!\n");
                    return -1;
                }
                else
                push(pop() / crctn);
                break;
            }
            case('='):
            {
                blck = 1;
                if (chck > 1) /* Function checks if there are still some elements in stack */
                {
                    printf("Something went wrong.\nCount of arithmetic operations is less then numbers one or the order is wrong.\nCheck what you entered.\n");
                    return -1;
                }
                else
                    if (errr == 1) /* Print Error if there are no elements in stack */
                    {
                        printf("Something went wrong.\nCount of numbers is less then arithmetic operations one or the order is wrong.\nCheck what you entered.\n");
                        return -1;
                    }
                    else
                        printf("The result is %.2f", pop());
                break;
            }
            default:
            {
                ungetc(frstchr, stdin);
                if (scanf("%f", &stkelmnt) != 1)    /* Function checks if the element is number or not and push it in to stack if there are no Errors */
                {
                    printf("Something went wrong. Check what you entered.\n(Symbols that are not ['=' '-' '+' '*' '/' and numbers] are not allowed!)\nExample: 4 5 - =");
                    return -1;
                }
                push(stkelmnt);
                break;
            }
        }
    }
    while
        (blck != 1);
    return 0;
}
