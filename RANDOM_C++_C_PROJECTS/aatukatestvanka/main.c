#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * f;
    if(f=fopen("Valo.txt", "r")== NULL) printf ("NQMA TAKUV FILE");
    return 0;
}
