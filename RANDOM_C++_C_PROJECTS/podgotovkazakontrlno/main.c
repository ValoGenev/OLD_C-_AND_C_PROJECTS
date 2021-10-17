#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE * fpointer;
    if (fpointer=fopen("numbers.txt", "r")==0) printf ("Ne sushtestuva takuv fail");
    else printf ("max negative is %d\n",  maxNeg());
    cpy();
    fclose(fpointer);

}

int maxNeg()
{
    int number;
    int maxNegative=0;
    FILE * output= fopen("numbers.txt", "r");
    while(fscanf(output, "%d", &number) != EOF)
    {
       if(number < 0)
       {
           if (maxNegative==0)
            maxNegative=number;
           else if (number>maxNegative)
            maxNegative=number;
       }
    }

    return maxNegative;
}


void cpy()
{
    int number;
    int number2;
    FILE * fpointer;
    FILE * fpointer2;
    char name[51];
    printf ("Name the file: ");
    scanf("%s" , &name);
    strlen(name) -1;
    fpointer2=fopen(name, "w");
    fpointer=fopen("numbers.txt" , "r");
    while (fscanf(fpointer, "%d" , &number) != EOF)
    {
        if(number<0)
        {

            fprintf (fpointer2, "%d\n" , number*(-1));
        }
        else if (number > 0 )fprintf (fpointer2, "%d\n" , number*(-1));
    }


}

