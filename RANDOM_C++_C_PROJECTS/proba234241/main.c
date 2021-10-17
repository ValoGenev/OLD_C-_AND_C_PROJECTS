#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    printf ("Vuvedi stoinost za x: ");
    scanf ("%d", &x);
    proba(x);
    return 0;
}

void proba(int x)
{
    printf ("x=%d", x);

}

