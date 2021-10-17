#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    int i;
    int j;
    printf ("KOlko koloni: ");
    scanf ("%d", &a);
    for(i=1; i<=a; ++i)
    {
        for(j=1; j<=i; ++j)
        {
            printf("%d ",j);
        }
        printf("\n");
    }
    return 0;
}
