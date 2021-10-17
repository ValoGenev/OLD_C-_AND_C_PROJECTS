#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=1;
    int b=0;
    int c;
    int i;
    for (i=1;i<20;i++)
    {
    c=a+b;
    a=b;
    b=c;
    printf ("%d\n", c);
    }

    return 0;
}
