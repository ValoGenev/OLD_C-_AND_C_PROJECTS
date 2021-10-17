#include <stdio.h>
#include <stdlib.h>

int main()
{
    int value=0;
    int *pvalue= &value;
    printf ("Input an integer: ");
    scanf ("%d", pvalue);
    printf ("You entetered %p.\n", &value);
    return 0;
}
