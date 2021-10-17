#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int randomNumber(int result);
int randomNumber2(int result2);
int main()
{
    int choice;
    time_t t;
    int result;
    int result2;



     //// srand (unsigned(time(&t))   randomNumber = rand() % 12
    printf ("\n\n");
    printf ("\t\t\t\t\t\tWELCOME TO BLACKJACK\n");
    printf ("\n\n");
    printf ("------------------------------------------------------------------------------------------------------------------------\n");
    printf ("\t\tTo enter the game press (1) \t\t\t\t");
    printf ("To exit the game press (2)");
    scanf ("%d", &choice);
    switch(choice)
    {
        case 1 :
            clearScrean();
        printf ("\n\n");
        printf ("\t\t\t\t\t\You entered the game!\n");
        printf ("------------------------------------------------------------------------------------------------------------------------\n");
        printf("Your card is %d\t\t\t\t", randomNumber(result));
        printf ("Dealers card is %d", randomNumber2(result2));
        getchar();
        printf("Your secondcard is %d\t\t\t\t", randomNumber(result));
        printf ("Dealers second card is %d", randomNumber2(result2));
        break;
        case 2 :
            clearScrean();
        printf ("\n\n");
        printf ("\t\t\t\t\t\You exited the game!\n");
        printf ("------------------------------------------------------------------------------------------------------------------------\n");
        break;
    }

    return 0;


    }

int randomNumber(int result)
    {
     time_t t;
      srand (time(&t));
      result = (rand() % 12);
      return result;
    }
    int randomNumber2(int result2)
    {
      time_t p;
      srand (time(&p));
      result2 = (rand() % 12);
      return result2;
    }

void clearScrean()
{
    system("cls");
}
