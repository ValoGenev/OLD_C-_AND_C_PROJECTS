#include <stdio.h>
#include <stdlib.h>

int main()
{

int num, max, min, n;

    printf ("N=  ");
    scanf ("%d", &n);
    printf ("\nVuvedi chisla\n");
    scanf ("%d", &num);
    max = min = num;

    for (int i = 1; i < n; i++)
    {
        scanf ("%d", &num);
        if (min > num && num < 0)
        {
                min = num;
        }
    }
    if (min<0)
{
    printf ("Nai golqmoto otricatelno e e %d ", min);
}
    else
    {
        printf ("Nqma otricatelni stoinosti");
    }
    return 0;



}

