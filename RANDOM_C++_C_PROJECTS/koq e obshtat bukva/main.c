#include <stdio.h>
#include <stdlib.h>

int main()
{
    char valo[] = "da";
    char dana[] = "dazz";
    char *ret;
   ret = strpbrk(valo,dana);

   if (ret)
    printf ("bukvata e: %c\n", *ret);
    return 0;
}
