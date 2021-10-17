#include <stdio.h>
#include <stdlib.h>
int main ()
{
 int i,n;
 int * stations;
 i=7;
 stations = (int*) malloc (i*4);

 if (stations==NULL) exit (1);

 for (n=0; n<i; n++)
 stations[n]=n;


for(n=0;n<7;n++)
printf("%d",stations[n]);
int *ptrToStations;
ptrToStations = stations;
stations = (int*) malloc (++i*4);
 for(n=0;n<8;n++)
stations[n]=ptrToStations[n];
stations[i-1]=i;
printf("\n");
for(n=0;n<8;n++)
printf("%d",stations[n]);
printf("\n");
return 0;


}

