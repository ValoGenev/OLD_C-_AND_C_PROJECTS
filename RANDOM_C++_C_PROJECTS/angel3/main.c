#include <stdio.h>
#include <stdlib.h>

int main()
{

    int x;
    int result=0;
    int a=1;

    while (a!=0)
    {
        scanf ("%d", &x);
        if(x==0) {
                a==0;
                break;

                }
        result=result+x;
        }
    printf ("%d", result);
}
