#include <stdio.h>
#include <stdlib.h>


int main()
{
int secretNumber =5;
int quess;
int quessCount = 1;
int quessLimit = 3;
int outOfGuesses = 0;
while(quess != secretNumber)
{
 if(quessCount <= quessLimit)
 {

    printf ("Poznai chisloto: ");
    scanf ("%d", &quess);
    quessCount++;

}
    else
    {
        printf("svurshiha ti opitite");
        return 0;
    }


}



printf ("BRAVO WE");

return 0;


}
