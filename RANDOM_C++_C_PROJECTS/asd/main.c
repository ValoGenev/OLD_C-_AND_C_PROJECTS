#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a,b,n;
    int c=0;
      scanf ("%d", &a);
      scanf ("%d", &b);
      scanf ("%d", &n);

    while (a<=b)
    {
        for (c=2; c<100 ; c=c+2)
    {
      if (a*c==n)
        {
            if (a*a>n)
            {
                break;
            }
            printf ("%d e stepen\n", a);

        }

    }
    a++;


    }
    printf ("%lf", a);




}

