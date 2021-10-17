#include <stdio.h>
#include <stdlib.h>
void suma(int a, int b);
int main ()
 {

   int a;
   int c=50;
   int d=120;
   suma(c,d);

   printf ("%d", a);

   return 0;
}


void suma(int a, int b)
{

    int result;
    result = a+b;
    printf ("%d", result);
    return 0;
}

int izvajdane(int x,int y)
{
    int result;
    result = x-y;
    return result;

}
