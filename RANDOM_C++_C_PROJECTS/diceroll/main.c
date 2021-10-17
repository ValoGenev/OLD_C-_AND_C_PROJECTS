#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()


{


    srand(time(NULL));
    int lowerLimit = 1, upperLimit = 11;
    int r = lowerLimit + rand() % (upperLimit - lowerLimit);
    int z = lowerLimit + rand() % (upperLimit - lowerLimit);
    int x = lowerLimit + rand() % (upperLimit - lowerLimit);
    int y = lowerLimit + rand() % (upperLimit - lowerLimit);
    int t = lowerLimit + rand() % (upperLimit - lowerLimit);
    int n = lowerLimit + rand() % (upperLimit - lowerLimit);
    int o = lowerLimit + rand() % (upperLimit - lowerLimit);
    int HIT;
    int a;
    int b;
    printf ("Hit(1) or Stay(2):    ");
    scanf ("%d", &HIT);


        switch(HIT)
    {
        case 1:
        printf ("\n");
        printf("You have %d\n", r);
        printf ("Dealer has %d\n", t);


        break;

    }
        printf ("\n");
        printf ("Hit(1) or Stay(2):   ");
        scanf ("%d", &HIT);
        switch(HIT)
    {
        case 1:
        printf ("\n");
        printf("You have %d", z);
        printf ("(%d)\n",z+r);
        printf ("Dealer has %d", o);
        printf ("(%d)\n", o+t);
        break;



    }
        printf ("\n");
        printf ("Hit(1) or Stay(2):   ");
        scanf ("%d", &HIT);
        switch(HIT)
    {
        case 1:
        printf ("\n");
        printf ("You have %d", x);
        printf ("(%d)\n", x+z+r);
        printf ("Dealer has %d", n);
        printf ("(%d)", o+t+n);
        break;


        case 2:
        if (z+r > o+t)
        {
            printf ("\n");
            printf ("You win !!");
        }
        else if (z+r < o+t)
        {
            printf ("\n");
            printf ("You lose");
            return 0;
        }
        }








    return 0;
}
