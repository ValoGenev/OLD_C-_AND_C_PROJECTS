#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int stringLenght(const char string[]);

int main()
{
    const char word1[] = "jason";
    const char word2[] = "ok";
    const char word3[] = "whatever";
    printf ("%d   %d    %d\n", stringLenght(word1), stringLenght(word2), stringLenght(word3));
    return 0;
}

int stringLenght(const char string[])
{
    int count = 0;
    while (string[count] != '\n')
        ++count;

    return count;
}
