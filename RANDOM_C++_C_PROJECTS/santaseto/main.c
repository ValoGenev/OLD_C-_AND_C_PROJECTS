#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>


int main()
{

 cards();


  return 0;
}


void cards()
{
    int i =0,k=0,count=0;
    time_t t;
	int randomNumbers[24];
	srand(time(0));
	char cardsShuffled[24][20];
    char cards[24][20] =
                {

                 "Queen of Diamonds",
                 "Queen of Clubs" ,
                 "Queen of Spades",
                 "Queen of Hearts",

                 "King of Diamonds",
                 "King of Clubs" ,
                 "King of Spades",
                 "King of Hearts",

                 "Jack of Diamonds",
                 "Jack of Clubs" ,
                 "Jack of Spades",
                 "Jack of Hearts",

                 "10 of Diamonds",
                 "10 of Clubs" ,
                 "10 of Spades",
                 "10 of Hearts",

                 "Ace of Diamonds",
                 "Ace of Clubs" ,
                 "Ace of Spades",
                 "Ace of Hearts",

                 "9 of Diamonds",
                 "9 of Clubs" ,
                 "9 of Spades",
                 "9 of Hearts",
                };

     while(count <24)

    {
		int randNum =rand() % 24;
		bool found =false;
		for (i=0; i < 24; i++) {
			if(randomNumbers[i] ==randNum)
            {
				found =true;
				break;
			}
		}

        if(!found)
         {
			randomNumbers[k] =randNum;
			count++;
			k++;
		 }

	}


    printf ("%s\n\n",cardsShuffled[i]);


	deck(randomNumbers,cards);

	}





	void deck (int randomNumbers[24], char cards[24][20])
{
    int choice=1;
    printf ("Player's cards: \t\t\t Computers cards: \n\n");
    for(int i=0;i<12;)
    {
        printf ("[%d]%s\t\t\t\t", choice,cards[randomNumbers[i]]);

        i++;
        printf ("%s\n", cards[randomNumbers[i]]);
        i++;
        choice++;
    }

    printf ("\n\n\t\t      KOZ: %s\n\n\n\n\n", cards[randomNumbers[13]]);
    game();


}
void game(int randomNumbers[24], char cards[24][20])
{
    int choice;
    printf ("\n Enter option: ");
    scanf ("%d", &choice);
    printf ("%s", cards[randomNumbers[choice]]);

}

