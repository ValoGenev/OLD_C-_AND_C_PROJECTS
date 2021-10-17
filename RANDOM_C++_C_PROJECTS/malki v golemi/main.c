#include <stdio.h>
#include <stdlib.h>

int main()
{
    char text[100];
    int i;
    scanf ("%s", text);
    for (i=0;(text[i]=(char)toupper(text[i])) != '\0'; i++);
    printf ("%s", text);
    return 0;
}
