#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char a[100] = "Ko praish we shmeker";
    char b[2] = " ";
    int duma=0;
    char *token;
    token= strtok(a,b);
    while (token != 0)
    {
    printf ("%s\n", token);
    token=strtok(0, b); //// vurvi prez drugi znaci
    ++duma;
   }
   printf ("Ima %d dumi v izrechenieto", duma);
    return 0;
}
