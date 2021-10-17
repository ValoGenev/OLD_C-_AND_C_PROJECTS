#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=2;
    int b=4;
    printf ("Before swaping:\na=%d\nb=%d", a,b);
    swap(&a, &b);
    printf ("\nAfter swaping:\na=%d\nb=%d", a,b);




    return 0;
}
void swap(int *x, int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
    return;

}
