#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int frstchr;
int stk[256];
int i = 1;
int stklmnt;
int crctn;
int blck = 0;

int pop(void)
{
    return stk[--i];
};

int push(int stklmnt)
{
    stk[i++] = stklmnt;
};

int main()
{
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
                crctn = pop();
                push(pop() - crctn);
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
                push(pop() / crctn);
                break;
            }
            case('='):
            {
                blck = 1;
                printf("The result is %d", pop());
                break;
            }
            default:
            {
                ungetc(frstchr, stdin);
                scanf("%d", &stklmnt);
                push(stklmnt);
                break;
            }
        }
    }
    while
        (blck != 1);
    return 0;
}
