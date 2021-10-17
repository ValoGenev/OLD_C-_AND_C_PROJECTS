#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i=0;
    int size;
    int number=0;
    char uravnenie[50];
    int  numbers[]  = {1,2,3,4,5,6,7,8,9,10};
   printf ("Vuvedi uravnenie: ");
   gets(uravnenie);
   while(uravnenie[i] != '\0')
   {
       printf ("%c", uravnenie[i]);
       if (uravnenie[i-2] == 'x' && uravnenie[i-1] == '^' && uravnenie[i] == '2')
       {
           for(int a=0;a<10;a++)
           {
               if (uravnenie[i-3] == numbers[a])
                number=numbers[a];
           }

       }

       i++;
   }
   printf ("%d", number);











   }
