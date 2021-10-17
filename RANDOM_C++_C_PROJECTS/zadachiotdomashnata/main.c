#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char str[]= "Zdraveite";
    char *pointer = str;
    const char *lastAdress=pointer;
    while(*lastAdress)
        lastAdress++;
        printf ("adresa na pointera e %d", pointer);
        printf ("\nadresa na last adresa e %d", lastAdress);
        printf ("\nduljiatana na stringa e %d", lastAdress-pointer);



}

