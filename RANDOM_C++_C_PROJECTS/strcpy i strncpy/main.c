#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char hello[40];
    char da[10] = "pedal";
    strncpy(hello,da,100);
    printf ("%s", hello);
    return 0;
}
