#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char *town[6]={"Burgas", "Plovdiv", "Pleven", "Sofiq", "Montana"};
    int distance[5][5] = {
      {0,1,2,3,4},
      {0,0,5,6,7},
      {0,0,0,8,9},
      {0,0,0,0,10}
    };

   char townStart[10];
   char townFinal[10];
   int i=0;
   int j=0;
   printf ("Select a town for a start point: ");
   gets(townStart);


   printf ("Select a town for a final distination: ");
   gets(townFinal);
   while (strncmp(town[i],townStart,strlen(townStart))!=0) i++;
   while (strncmp(town[j],townFinal,strlen(townFinal))!=0) j++;


  if (i>j) printf ("\nDistance between %s and %s is: %d kilometers\n", townStart,townFinal,distance[j][i]);
  else printf ("\nDistance between %s and %s is: %d kilometers\n", townStart,townFinal,distance[i][j]);



}


