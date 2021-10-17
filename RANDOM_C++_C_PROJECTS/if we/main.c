#include <stdio.h>
#include <stdlib.h>





int main()

{
char operaciq;
double num1;
double num2;
printf("Vuvedi purva stoinost: ");
scanf ("%lf", &num1);
printf ("vuvedi operaciq: ");
scanf (" %c", &operaciq);
printf("Vuvedi vtora stoinost: ");
scanf ("%lf", &num2);
if (operaciq == '+')
{
    printf("%f", num1+num2);
}
else if(operaciq == '-')
{
    printf ("%f" ,num1-num2);

}


else if(operaciq == '*')
{
    printf ("%f" , num1*num2);

}
    else if(operaciq == '/')
    {
        printf ("%f", num1/num2);
    }
    else
    {
        printf ("Ne sushtestvuva takava operaciq");
    }


return 0;

}

