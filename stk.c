#include <stdio.h>

int main()
{
    int i;
    int m;
    int stk[256];
    int l = 1;
    printf("Enter Stack elements:\n(Enter '00' if there are no more elements in your stack)\n");
    for(i = 0; l != 0; i++)
    {
        scanf("%d", &stk[i]);
        if (stk[i] == 00)
        {
            l = 0;
            m = i;
        }
    }
    m--;
    printf("Stack elements are:\n");
    for(i = m; i >= 0; i--)
    {
        printf("%d\n", stk[i]);
    }
  return 0;
}
