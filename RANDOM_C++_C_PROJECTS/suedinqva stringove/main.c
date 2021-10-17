#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char dana[100];
    char valo[] = "gei";
    printf ("napishi si tekst: ");
    scanf ("%s", dana);
    printf ("%s", strcat(dana,valo));
    return 0;
}
