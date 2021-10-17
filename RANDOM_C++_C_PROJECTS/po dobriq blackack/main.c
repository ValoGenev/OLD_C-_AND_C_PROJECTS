#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS 52
#define DRAW 5

void showcard(int card);

int main()
{
    int deck[CARDS];
    int x,c;

/* initialize the deck */
    for(x=0;x<CARDS;x++)
        deck[x] = 0;

    srand((unsigned)time(NULL));
    for(x=0;x<DRAW;x++)
    {
        for(;;)                 /* loop until a valid card is drawn */
        {
            c = rand() % CARDS;     /* generate random drawn */
            if(deck == 0)        /* has card been drawn? */
            {
                deck[0] = 1;        /* show that card is drawn */
                showcard(c);        /* display card */
                break;              /* end the loop */
            }
        }                       /* repeat loop until valid card found */
    }

    return(0);
}

/* Take values 0 through 51 (cards in a deck) and display
   corresponding card name */
void showcard(int card)
{
    char *suit[4] = { "Spades", "Hearts", "Clubs", "Diamonds" };

    switch(card%13)
    {
        case 0:
            printf("%2s","A");
            break;
        case 10:
            printf("%2s","J");
            break;
        case 11:
            printf("%2s","Q");
            break;
        case 12:
            printf("%2s","K");
            break;
        default:
            printf("%2d",card%13+1);
    }
    printf(" of %s\n",suit[card/13]);
}
