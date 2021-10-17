#include <stdio.h>
#include <stdlib.h>


struct magazine
{
    char title[20];
    int numOfPages;
    double price;
    struct magazine *next;

};
typedef struct magazine magazine;
magazine *head=NULL;
magazine *current=NULL;


int main()
{

  enterData();
  listMagazine();
  ListWithPagesOver30();




    return 0;
}


 void enterData()
{


    for(int i=0;i<=2;i++)
    {

        magazine *temp=(magazine*)malloc(sizeof(magazine));

        if(head==NULL)
     {
         head=temp;
         current=head;
         current->next=NULL;

      }
       else
    {
      current->next=temp;
      current=temp;
      current->next=NULL;
    }


        printf ("Enter title of magazine: ");
        gets(current->title);
        printf ("Enter number of pages: ");
        scanf ("%d", &current->numOfPages);
        printf("Enter price: ");
        scanf("%lf", &current->price);
        fflush(stdin);

    }

}


void listMagazine()
{
    magazine *temp;
    for(temp=head; temp!=NULL; temp=temp->next)
    {
        printf ("\nTitle is %s", temp->title);
        printf ("\nPrice is %lf", temp->price);
        printf ("\nNummber pages : %d ", temp->title);
        printf ("\n\n\n")

    }

}

void ListWithPagesOver30()
{
    magazine *temp;
    for(temp=head; temp!=NULL; temp=temp->next)
    {
        if(temp->numOfPages>30)
        {

        printf ("\nTitle is %d", temp->title);
        printf ("\nPrice is %lf", temp->price);
        printf ("\nNummber pages : %d ", temp->numOfPages);

        }

    }

}
