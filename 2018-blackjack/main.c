#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
int randomNumber();
int bet();
int money();
int main()

{
    int moneys;
    int betmoney;
    int x=0,y=0;
    int a=1;
    int i=1;
    printf ("WELCOME TO BLACKJACK\n\n\n\n\nTo start the game press ENTER:\nTo exit the game press CTRL+C:\n\n ");
    getchar();
    moneys=money(money);
    getchar();
    getchar();
    printf ("Please make your bet:" );
    printf ("\n--------------------");
    printf ("\nPress 1 for 50$.\nPress 2 for 100$.\nPress 3 for 500$.\nPress 4 for 1000$.\nPress 5 for 2500$.\nPress 6 for 5000$.\n");
    betmoney=bet();
    clearScreen();
    printf ("Total: %d\nBet: %d", moneys,betmoney);
    printf ("\n\n\nYou have %d",randomNumber());
    x+=randomNumber();
    getchar();
    printf ("     Dealer has %d",randomNumber());
    y+=randomNumber();
    printf ("\n\nHit(1) or Stay(2)");
    scanf ("%d",&a);
    while(i==a)
    {
    clearScreen();
    printf ("Total: %d\nBet: %d", moneys,betmoney);
    printf ("\n\n\nYou have %d",(x+randomNumber()));
    x+=randomNumber();
    printf ("     Dealer has %d",y);
    if(x>21)
    {
        printf ("\nYou lose!!");
        return 0;
    }
    printf ("\n\nHit(1) or Stay(2)");
    scanf ("%d",&a);

    } clearScreen();

    printf ("Total: %d\nBet: %d", moneys,betmoney);
    printf ("\n\n\nYou have %d",x);
    printf ("     Dealer has %d",y+randomNumber());
    y+=randomNumber();
    while (x>y)
    {
    clearScreen();

    printf ("Total: %d\nBet: %d", moneys,betmoney);
    printf ("\n\n\nYou have %d",x);
    printf ("     Dealer has %d",y+randomNumber());
    y+=randomNumber();

    }
    if (y>x && y<=21)
    {
        printf ("\nDealer wins!!");
    }
    else if (x==y)
    {
        printf ("\nDraw");
    }
    else
    {
        printf ("\nYou win!!!");
    }

    getchar();
    getchar();



    return 0;
}
void clearScreen()
{
system("cls");
}
int bet()
{
    int betmoney;
    int a;
    scanf ("%d", &a);
    switch (a)
    {
        case 1: betmoney=50;   break;
        case 2: betmoney=100;  break;
        case 3: betmoney=500;  break;
        case 4: betmoney=1000; break;
        case 5: betmoney=2500; break;
        case 6: betmoney=5000; break;
        default: printf ("Invalid operator");
    } return betmoney;
}
int checkForWin()
{

}
int randomNumber()
{
    int randomNumber;
    int cards[15] = {1,2,3,4,5,6,7,8,9,10,10,10,10,11};
    time_t t;
    int a=0;
    srand((unsigned) time(NULL));
    randomNumber= rand() % 14;
    return cards[randomNumber];
}

int  money()
{
    int money;
    printf ("Set a start point to your balance:   ");
    scanf("%d", &money);
    printf ("\nYou have %d$ in your wallet.",money);
    return money;

}
