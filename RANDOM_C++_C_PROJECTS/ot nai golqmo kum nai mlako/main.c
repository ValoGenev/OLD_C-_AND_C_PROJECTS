#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c[100];
    int n;
    int i,j;
    int a,tmp;
    int min;
    int b[100];
    printf ("Vuvedi razmer na stringa: ");
        scanf ("%d", &n);
        printf ("imash %d cifri\n", n);
        for (i=0;i<n; i++)
        {
            printf ("Vuvedi chislo: ");
            scanf ("%d", &c[i]);
        }
 for(i=0; i<n; i++) // 3 2 1
    {
        for(j=i+1; j<n; j++)
        {
            if(c[j] <c[i])
            {
                tmp = c[i];  // temp = 3
                c[i] = c[j];   // ci=2
                c[j] = tmp;      //cj=3
            }
        }


        }
        printf("\nElements of array in sorted ascending order:\n");
    for(i=0; i<n; i++)
    {
        printf("%d  ", c[i]);
    }

    return 0;
}
