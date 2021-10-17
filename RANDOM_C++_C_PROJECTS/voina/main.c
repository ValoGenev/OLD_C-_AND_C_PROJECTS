#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int cards();
int main()
{

    int cards[56] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,1,2,3,4,5,6,7,8,9,10,11,12,13,14,1,2,3,4,5,6,7,8,9,10,11,12,13,14,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    time_t t;
    int i;

    for (i=0;i<55;i++)
    {

    srand((unsigned) time(NULL));
    cards[i] = rand() % 14;
    printf ("%d", cards[i]);


    }
}




int cards ()
{

    int cards[56] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,1,2,3,4,5,6,7,8,9,10,11,12,13,14,1,2,3,4,5,6,7,8,9,10,11,12,13,14,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    time_t t;
    int i;

    for (i=0;i<55;i++)
    {

    srand((unsigned) time(NULL));
    cards[i] = rand() % 56;
    printf ("%d", cards[i]);


    }



}
