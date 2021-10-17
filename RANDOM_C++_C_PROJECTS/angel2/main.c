#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y;
    int result=0;
    printf ("vuvedi x: ");
    scanf ("%d", &x);
    printf ("vuvedi y: ");
    scanf ("%d", &y);
    x++;
    while (x<y)
    {

        printf ("%d", x);
        result=result+x;
        x++;

    }
    printf ("%d", result);
    return 0;
}
