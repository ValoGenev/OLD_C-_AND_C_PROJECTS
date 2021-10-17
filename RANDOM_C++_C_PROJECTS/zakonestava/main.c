#include <stdio.h>
#include <stdlib.h>
void  a(FILE * f, int *a);

int main()
{
  int a;
   FILE * fpointer = fopen("da.txt", "r");
   fscanf(fpointer , "%d" , &a);
   a(fpointer, &a);
}


void  a(FILE * f, int *a)
{

    fscanf(f, "d" , &a);
    a+1;
    printf ("%d", a);
}
