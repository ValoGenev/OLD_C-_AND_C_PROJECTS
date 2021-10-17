#include <stdio.h>
#include <stdlib.h>

int main()
{
   int x=5;

    char buf[x];
    fgets(buf, x, stdin);


    printf("size of char is %s",  buf);
    return 0;
}
