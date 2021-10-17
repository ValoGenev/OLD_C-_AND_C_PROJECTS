#include <stdio.h>
#include <string.h>


int main()
{

    FILE * pFile;
int number;
pFile = fopen ("kontrolno.txt","r");
if (pFile!=NULL) {
fscanf(pFile, "%d", &number);
fclose (pFile);
}
printf("number: %i", number);
return 0;
}
