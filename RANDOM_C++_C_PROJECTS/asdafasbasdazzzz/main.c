#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b=1,i,j;
    int k=1;
    printf ("Kolko redici: ");
    scanf ("%d", &a);
    for(i=0;i<=a;i++)
    {
        for (j=1;j<=i;j++)
        {
            printf ("%d", k++);
        }

            printf ("\n");
            b++;
    }
    return 0;
}
