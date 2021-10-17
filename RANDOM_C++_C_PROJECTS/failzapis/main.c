#include <stdio.h>
#include <stdlib.h>

int main()
{
int n;
printf ("Kolko reda da chete: ");
scanf ("%d", &n);
printf ("nai golqmoto otricatelno chislo e %d", neg(n));
}

int neg(int n)
{
    FILE * pFile;
    int number;
    int maxNegative=0;
    pFile = fopen ("kontrolno.txt","r");
if (pFile!=NULL)
    {
        for(int i =0; i<n ;i++)
        {
            fscanf(pFile, "%d", &number);
            if (number < 0)
            {
               if(!maxNegative) maxNegative= number;
                else if (maxNegative<number) maxNegative=number;
            }
        }
}
   return maxNegative;

}
int cpy();
{
    char name[51];
    FILE * outp;
    int next;
 printf ("name of the new file: ");
 if(!fgets(name,50,stdin)){
 printf("Error in the new file name 1");
 return;
 }
 name[strlen(name)-1]=0; /* remove '\n' in the string */
 if(!(outp=fopen(name,"w"))){
 printf("Error in the new file name 2");
 return;
 }
 for(;(next=fgetc(inp))!= EOF;){
 if (next == '2') next = '4';
 if(fputc(next,outp)==EOF){
 printf("Error - in file writing");
 return;
 }
 }
 fclose(outp);
}





