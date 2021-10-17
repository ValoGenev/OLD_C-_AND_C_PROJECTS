#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    printf ("Napishi chislo: ");
    scanf ("%d", &x);
    int y=1;
    while (y<=x)
    {
        for(int i=0;i<y;i++)     printf ("%d", y);
        printf ("\n");
        y++;

    }
    return 0;
}
