#include <stdio.h>
#include <stdlib.h>

int main(){
    float num;
    char sp;
    char val;
    printf("$ tconvert ");
    scanf("%f%c%c", &num, &sp, &val);
    switch (val) {
        case 'C':
            printf("%.2f F\n", num * 1.8 + 32);
            printf("%.2f K\n", num + 273.15);
        break;
        case 'F':
            printf("%.2f C\n", (num - 32) / 1.8);
            printf("%.2f K\n", (num + 459.67) * 5 / 9);
        break;
        case 'K':
            printf("%.2f C\n", num - 273.15);
            printf("%.2f F\n", num * 9 / 5 - 459.67);
        break;
        default:
            printf("%.2f C:\n", num);
            printf("%.2f F\n", num * 1.8 + 32);
            printf("%.2f K\n", num + 273.15);
            printf("\n");
            printf("%.2f F:\n", num);
            printf("%.2f C\n", (num - 32) / 1.8);
            printf("%.2f K\n", (num + 459.67) * 5 / 9);
            printf("\n");
            printf("%.2f K:\n", num);
            printf("%.2f C\n", num - 273.15);
            printf("%.2f F\n", num * 9 / 5 - 459.67);
        break;
    }
    return 0;
}
