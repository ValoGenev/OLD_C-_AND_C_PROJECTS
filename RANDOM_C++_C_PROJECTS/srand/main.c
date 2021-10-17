#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int randomNumber;
    int quess = 0;
    int maximumNumberOfQuesses = 20;
    time_t t;
    int a;
    srand (time (&t));
    randomNumber= rand() % 10;
    printf ("%d", randomNumber);

    while (quess < maximumNumberOfQuesses)
    {



        printf ("Poznai koe e chisloto: ");
        scanf ("%d", &a);
        quess++;
        if (a==randomNumber)
        {
            printf ("Specheli");
            break;
        }
        else ("Zagubi");

    }


    return 0;
}
