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

void game()
{

}
void cards()
{
    int k = 0;
    time_t t;
	int random_numbers[24];
	int count =0;
	srand(time(0));
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
                int i =0;


     while(count <24)
        {

		int randNum =rand() % 24;
		bool found =false;


		for (i=0; i < 24; i++) {
			if(random_numbers[i] ==randNum) {
				found =true;
				break;
			}
		}

		//we have a new random number
		if(!found)
            {
			random_numbers[k] =randNum;
			printf ("random number is %d\n", random_numbers[i]);
			count++;
			k++;
		}
	}











}
