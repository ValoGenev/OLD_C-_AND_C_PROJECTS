#include <stdio.h>
#include <stdlib.h>
struct list
{

  int value;
  struct list *next;

};
typedef struct list list;
list *head = NULL;
list *current = NULL;

int main()
{
    list *temp = (list*)malloc(sizeof(list));
    if(head==NULL)
    {
        head=temp;
        current=head;
        current->next=NULL;

    }
    if(head!=NULL)
    {
        current->next=temp;
        current=temp;
        current->next=NULL;

    }

    scanf ("%d", &current->value);
    list *temp = (list*)malloc(sizeof(list));
    if(head==NULL)
    {
        head=temp;
        current=head;
        current->next=NULL;

    }
    if(head!=NULL)
    {
        current->next=temp;
        current=temp;
        current->next=NULL;

    }

     scanf ("%d", &current->value);
     listall();


    return 0;
}

void listall()
{
    list *temp;
   for(temp=head; temp!=NULL; temp=temp->next)
    {
        printf ("%d", temp->value);

    }

}
