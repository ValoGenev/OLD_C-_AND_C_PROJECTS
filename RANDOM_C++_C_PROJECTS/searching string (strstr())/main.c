#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char text[30] ="imam kuche";
    char word[30] ="kuche";
    char *pFound;
    int i;

    printf ("%s", strstr(text,word));

    return 0;
}
