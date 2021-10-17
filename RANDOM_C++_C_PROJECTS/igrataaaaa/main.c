#include <stdio.h>
#include <stdlib.h>

int main()
{

   int quess;
    int secretNumber=5;
    int quessCount=0;
    int quessLimit=4;
    int exit;
    printf("Poznai za kakvo chislo si misli Valo\n");
    printf ("Za nachalo napishete 1\n");
    printf ("Za izhod napishete 2\n");


    switch(exit)
    {

        case 1 :
        printf ("POCHVASH\n");
        printf ("Poznai koe e chisloto: \n");
        while (quess != secretNumber)
{

        quessCount ++;

        if (quessCount < quessLimit)
        {
            printf("Poznai chisloto: ");
            scanf ("%d", &quess);

        }
        else if (quessCount = quessLimit)
        {
            printf ("Zagubi");
            return 0;
        }




}
        printf ("ti specheli");





        break;

        case 2 :
        printf ("KRAI NA IGRATA");
        break;


}




        return 0;
    }
