#include <stdio.h>
int main()
{
    int n,i;
    int sum=1;
    int count=0;
   printf ("Vuvedi faktoriel:  ");
   scanf ("%d", &n);
   for (i=n;i>0;i--)
   {
       if(i%10==1)
       {
           count ++;
       }

   }
   printf ("%d", count);

}
