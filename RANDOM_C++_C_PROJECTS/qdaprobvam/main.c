#include <stdio.h>
#include <stdlib.h>


struct list
{
   int value;
   struct list *next;

};
typedef struct list list;
list *head=NULL;
list *current=NULL;

int main()
{
  for(int i=0;i<5;i++)
  {
      add();

  }


  show();
}


  void add()
  {

    list *temp=(list*)malloc(sizeof(list));

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


    printf ("\nEnter number: ");
    scanf ("%d", &temp->value);



  }
  void show()
  {
      list *temp;

    for(temp=head; temp!=NULL; temp=temp->next)

        {
            printf ("\nId is %d", temp->value);


        }

  }
