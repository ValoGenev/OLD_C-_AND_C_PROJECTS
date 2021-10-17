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
			//printf ("%s\n", cards[randomNumbers[k]]);
			k++;


		 }

	}


	deck(0,0,randomNumbers,cards,13);

	}




	void deck (int firstPlayerPoints,int secondPlayerPoints,int randomNumbers[24], char cards[24][20],int x, int firstPlayerChoice, int secondPlayerchoice)
{
    int choice1=1;
    int choice2=1;
    int k=6;

    printf ("\n\nPlayer 1 points: %d\t\t\t Player 2 points: %d \n", firstPlayerPoints, secondPlayerPoints);
     printf ("Player 2 cards: \t\t\t Player 2 cards: \n\n");
    for(int i=0;i<k;)
    {

        printf ("[%d]%s\t\t\t\t[%d]%s\n", choice1,cards[randomNumbers[i]],choice2,cards[randomNumbers[i+6]] );

        i++;
        choice1++;
        choice2++;
    }

    printf ("\n\n\t\t      KOZ: %s\n\n\n\n\n", cards[randomNumbers[12]]);



    game(randomNumbers,cards,x);


}
void game(int randomNumbers[24], char cards[24][20], int x)

{

    int player=1;
    int choice;
    int firstPlayerPoints;
    int secondPlayerPoints;
    char firstPlayerColor[10];
    char secondPlayerColor[10];
    int countWhileLoop=0;
    int size;
    int firstPlayerChoice;
    int secondPlayerChoice;
    char koz[10];
    strcpy(koz,cards[randomNumbers[12]]);

    size=strlen(koz) - 2;



        if(koz[size] == 'b')
        strcpy(koz,"Clubs");

        if(koz[size] == 't')
        strcpy(koz,"Heart");

        if(koz[size] == 'd')
        strcpy(koz,"Diamonds");

        if(koz[size] == 'e')
        strcpy(koz,"Spades");



    while (countWhileLoop!=2)
    {

    firstPlayerPoints,secondPlayerPoints=0;
    player=(player % 2) ? 1 : 2;
    printf ("\nPlayer %d enter option: ", player);

    if (player==1)
    scanf ("%d", &firstPlayerChoice);

    if (player==2)
    scanf ("%d", &secondPlayerChoice);

    if(player==2)
    {

    secondPlayerChoice+=6;

    printf ("%s\n", cards[randomNumbers[ secondPlayerChoice-1]]);

    size=strlen(cards[randomNumbers[ secondPlayerChoice-1]]) - 2;



        if(cards[randomNumbers[ secondPlayerChoice-1]][0]== '9')
        secondPlayerPoints=0;

        if(cards[randomNumbers[ secondPlayerChoice-1]][0]== 'J')
        secondPlayerPoints=2;

        if(cards[randomNumbers[ secondPlayerChoice-1]][0]== 'Q')
        secondPlayerPoints=3;

        if(cards[randomNumbers[ secondPlayerChoice-1]][0]== 'K')
        secondPlayerPoints=4;

        if(cards[randomNumbers[ secondPlayerChoice-1]][0]== '1')
        secondPlayerPoints=10;

        if(cards[randomNumbers[ secondPlayerChoice-1]][0]== 'A')
        secondPlayerPoints=11;



        if(cards[randomNumbers[ secondPlayerChoice-1]][size] == 'b')
        strcpy(secondPlayerColor,"Clubs");

        if(cards[randomNumbers[ secondPlayerChoice-1]][size] == 't')
        strcpy(secondPlayerColor,"Heart");

        if(cards[randomNumbers[ secondPlayerChoice-1]][size] == 'd')
        strcpy(secondPlayerColor,"Diamonds");

        if(cards[randomNumbers[ secondPlayerChoice-1]][size] == 'e')
        strcpy(secondPlayerColor,"Spades");



        strcpy(cards[randomNumbers[secondPlayerChoice-1]], "NEXT");



    }

    else
    {
        printf ("%s\n", cards[randomNumbers[firstPlayerChoice-1]]);

        size=strlen(cards[randomNumbers[firstPlayerChoice-1]]) - 2;

        if(cards[randomNumbers[firstPlayerChoice-1]][0]== '9')
        firstPlayerPoints=0;

        if(cards[randomNumbers[firstPlayerChoice-1]][0]== 'J')
        firstPlayerPoints=2;

        if(cards[randomNumbers[firstPlayerChoice-1]][0]== 'Q')
        firstPlayerPoints=3;

        if(cards[randomNumbers[firstPlayerChoice-1]][0]== 'K')
        firstPlayerPoints=4;

        if(cards[randomNumbers[firstPlayerChoice-1]][0]== '1')
        firstPlayerPoints=10;

        if(cards[randomNumbers[firstPlayerChoice-1]][0]== 'A')
        firstPlayerPoints=11;



        if(cards[randomNumbers[firstPlayerChoice-1]][size] == 'b')
        strcpy(firstPlayerColor,"Clubs");

        if(cards[randomNumbers[firstPlayerChoice-1]][size] == 't')
        strcpy(firstPlayerColor,"Heart");

        if(cards[randomNumbers[firstPlayerChoice-1]][size] == 'd')
        strcpy(firstPlayerColor,"Diamonds");

        if(cards[randomNumbers[firstPlayerChoice-1]][size] == 'e')
        strcpy(firstPlayerColor,"Spades");




        strcpy(cards[randomNumbers[firstPlayerChoice-1]], "NEXT");



    }

    countWhileLoop++;
    player++;

}

    if(player==3)
    {
        if (strcmp(firstPlayerColor,secondPlayerColor)!= 0 && strcmp(koz,secondPlayerColor)!=0 ||
        player==3 && strcmp(firstPlayerColor,secondPlayerColor)== 0 && firstPlayerPoints>secondPlayerPoints)
        {
            firstPlayerPoints+=secondPlayerPoints;
            secondPlayerPoints=0;
            printf ("\nPlayer 1 wins the hand! ");
        }

        else
        {
            secondPlayerPoints+=firstPlayerPoints;
            firstPlayerPoints=0;
            printf ("\nPlayer 2 wins the hand!");

        }
    }


    if(player==2)
    {
        if(strcmp(firstPlayerColor,secondPlayerColor)!= 0 && strcmp(koz,firstPlayerColor)!=0 ||
        player==2 && strcmp(firstPlayerColor,secondPlayerColor)== 0 && firstPlayerPoints<secondPlayerPoints )
        {
            secondPlayerPoints+=firstPlayerPoints;
             firstPlayerPoints=0;
            printf ("\nPlayer 2 wins the hand!");
        }

        else
        {
            firstPlayerPoints+=secondPlayerPoints;
            secondPlayerPoints=0;
            printf ("\nPlayer 1 wins the hand!");
        }

    }


    newDrawCard(firstPlayerPoints,secondPlayerPoints,randomNumbers,cards,firstPlayerChoice,secondPlayerChoice,x);


}

void  newDrawCard(int firstPlayerPoints, int secondPlayerPoints, int randomNumbers[24],char cards[24][20],int firstPlayerChoice,int secondPlayerChoice,int x)
{


 for(int i=0;i<24;i++)
 {
     if(i<6)

        if(strncmp(cards[randomNumbers[i]],"NEXT", 4)==0)
     {

           strcpy(cards[randomNumbers[i]],cards[randomNumbers[x]]);
           strcpy(cards[randomNumbers[x]], "   ");
     }

     if(i>=6)
        if(strncmp(cards[randomNumbers[i]],"NEXT",4)==0)
     {
           strcpy(cards[randomNumbers[i]],cards[randomNumbers[x+1]]);
           strcpy(cards[randomNumbers[x+1]], "   ");
     }
    // printf ("%s\n", cards[randomNumbers[i]]);

 }



//    deck(firstPlayerPoints,secondPlayerPoints,randomNumbers,cards,firstPlayerChoice,secondPlayerChoice);





}



