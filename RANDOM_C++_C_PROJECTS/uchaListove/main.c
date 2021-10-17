#include <stdio.h>
#include <stdlib.h>

struct list
{
  int value;
  struct list *next;

};
typedef struct list list;
list *head = NULL;
list *current=NULL;



int main()
{



    for(int i=0;i<5;i++)
{
        if(head==NULL)
    {
        head=new_item();
        current=head;

    }
    else
    {
        current->next=new_item();
        current=current->next;
    }


}



}










