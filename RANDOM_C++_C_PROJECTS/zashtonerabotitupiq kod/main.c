#include <stdio.h>
#include <stdlib.h>

int main()
{
    char line[200];
    char ch;
    int number=0;
    int k=0;
    FILE * fpointer = fopen("da.txt", "r");
    fscanf(fpointer, "%c", &ch);
    rewind(fpointer);
    while (fscanf(fpointer, "%c", &ch) != EOF)
    {
        if (ch=='\n') number++;
    }
    printf ("%d", number);
}
