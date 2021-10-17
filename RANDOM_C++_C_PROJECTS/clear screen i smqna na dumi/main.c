#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


int main()

{

   int i=0;
   int player=1;
   char name[20] = "Valo";
   int age=18;


   do
   {
    ekran();
    printf ("Kazvam se  %s i sum na %d\n", name, age);

      player = (player % 2)? 1 : 2;


      printf("Player %d, enter a age and name:  \n", player);
      scanf("%d %s", &age, &name);

      i++;
      player++;
   }while (i<100);





    return 0;
}

void ekran()
{

    system ("cls");


}
