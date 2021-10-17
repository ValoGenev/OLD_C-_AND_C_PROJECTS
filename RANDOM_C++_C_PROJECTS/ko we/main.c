#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,i;
    printf ("Vuvedi a: ");
    scanf ("%d", &a);
    for (i=1;i!=2;)
    {
    b=izvajdane(b);
    a=a-b;
    printf ("%d", a);
    printf ("\nIskate li da produljite");
    scanf ("%d", &i);
    }
    return 0;
}
int izvajdane(int b)
{
    printf("s kolko iskash da go izvadish");
    scanf ("%d", &b);
    return b;
}
