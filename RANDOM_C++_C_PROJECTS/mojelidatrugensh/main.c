#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f;
    char line[100];
    f=fopen("test.txt", "r");

    while (fgets(line,100,f) != EOF)
    {
        puts(line);
    }

    return 0;
}
