#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num[100];
    int i;
    int n;
    int sum=0;
    printf("Vuvedi broi na chisla\n");
    scanf ("%d", &n);
    for (i=0;i<n;i++)
    {
        printf ("Vuvedi chisla: ");
        scanf ("%d", &num[i]);
        sum+=num[i];
    }
    printf ("srednoto e %d", sum/n);
    return 0;
}
