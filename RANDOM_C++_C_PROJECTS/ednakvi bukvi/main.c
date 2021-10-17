#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char valo[100] = "zzbz";
    char dana[100] = "bbc";
    if (strpbrk(valo,dana))
    {
       printf ("ima ednakvi bukvi");
        printf ("%c", strpbrk(valo,dana));
    }

    else
        printf ("nqma ednakvi bukvi");
    return 0;
}



