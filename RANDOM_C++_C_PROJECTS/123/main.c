#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    int sum=1;
    int i=1;
    int c;
    printf ("Faktorial ot kolko iskate:   !");
    scanf ("%d", &a);

    for (i=a; i>0; i--)
    {
         sum=sum*i;


    }
     printf ("%d", sum);
    return 0;
}
