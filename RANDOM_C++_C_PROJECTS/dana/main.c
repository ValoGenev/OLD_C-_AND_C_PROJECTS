#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, num, min;
    printf("Vuvedi N: ");
    scanf ("%d", &n);
    printf ("Vuvedi chislo:  \n");
    scanf ("%d", &num);
    min=num;
    for (int i=1; i<n; i++)
    {
        scanf ("%d", &num);
        if (num>min || num<0 )
        {
            if(min>num)
           min=num;
        }
    }
    if (min<0)
    printf ("min e %d", min);
    else
        printf ("nqma otricatelni chisla");
    return 0;
}
