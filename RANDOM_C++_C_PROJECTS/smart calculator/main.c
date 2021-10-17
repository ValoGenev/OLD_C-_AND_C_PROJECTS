#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
int main()
{
    char calc[100];
    gets(calc);

    int a=0;
    int numb=0;
    int result1=0;
    int result2=0;
    int p=1;
    int b=0;
    int x=1;
    int i;
    int z=0;
    for(i=0;calc[i] != '\0'; i++)
    {

        if(ispunct(calc[i])) break;
    }
    b=i;
    while(calc[i+1] != '\0')
    {
     a++;
     i++;
    }


    i=0;
    z=b-1;
    x=z;
    int y=1;


    while(i<b)
    {
    if (calc[i]=='0') numb=0;
    if (calc[i]=='1') numb=1;
    if (calc[i]=='2') numb=2;
    if (calc[i]=='3') numb=3;
    if (calc[i]=='4') numb=4;
    if (calc[i]=='5') numb=5;
    if (calc[i]=='6') numb=6;
    if (calc[i]=='7') numb=7;
    if (calc[i]=='8') numb=8;
    if (calc[i]=='9') numb=9;
    i++;
    z--;
    while(x>0)
    {
        p=p*10;
        x--;
    }
    result1=result1+numb*(p/y);
    y=y*10;
    }
    printf ("First number: %d", result1);
    p=1;
    for(i=0;calc[i] != '\0'; )
    {
      i++;
    }

    int k=i-a;
    while(a>1)
    {
        p=p*10;
        a--;

    }

    while(k<i)
    {
    if (calc[k]=='0') numb=0;
    if (calc[k]=='1') numb=1;
    if (calc[k]=='2') numb=2;
    if (calc[k]=='3') numb=3;
    if (calc[k]=='4') numb=4;
    if (calc[k]=='5') numb=5;
    if (calc[k]=='6') numb=6;
    if (calc[k]=='7') numb=7;
    if (calc[k]=='8') numb=8;
    if (calc[k]=='9') numb=9;
    result2=result2+numb*p;
    p=p/10;
    k++;

    }
    printf ("\nSecond number: %d\n", result2);
    switch(calc[b])
    {
    case '+' : printf ("Result is : %d", result1+result2); break;
    case '*' : printf ("Result is : %d", result1*result2); break;
    case '/' : printf ("Result is : %d", result1/result2); break;
    case '-' : printf ("Result is : %d", result1-result2); break;
    default: printf ("Error!"); break;

    }

}
