#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    FILE *fp;
    char c;
    long s;
    if((fp = fopen(argv[1], "r")) != NULL) /* Checking if the file path is right */
    {
        while ((c = fgetc(fp)) != EOF) /* Display file symbols */
        {
            printf("%c", c);
        }
        fseek(fp, 0, SEEK_END); /* Counting file size */
        s = ftell(fp);
        printf("File size is %d bytes.", s);
    }
    else
    {
        printf("Error! File can not be open!");
        return -1;
    }
    fclose(fp);
    return 0;
}
