#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()


{


    srand(time(NULL));
    int lowerLimit = 1, upperLimit = 11;
    int r = lowerLimit + rand() % (upperLimit - lowerLimit);
    int z = lowerLimit + rand() % (upperLimit - lowerLimit);
    int HIT;
    int a;
    int b;
    printf ("Hit(1) or Stay(2):    ");
    scanf ("%d", &HIT);


        switch(HIT)
    {
        case 1:
        printf("%d\n", r);
        r=a;
        break;

    }
        printf ("Hit(1) or Stay(2):   ");
        scanf ("%d", &HIT);
        switch(HIT)
    {
        case 1:
        printf("%d\n", z);
        r=b;
        break;

    }

        printf("%d", a=b);






    return 0;
}
