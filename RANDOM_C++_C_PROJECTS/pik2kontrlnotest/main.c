#include <stdio.h>
#include <stdlib.h>

struct item
{
    int ID;
    char name[20];
    char date[10];


};
typedef struct item item;


struct list
{
    item value;
    struct list *next;

};
typedef struct list list;
typedef list *head;


int main()
{

}

list * ReadFromFile(list *root)
{
  list * current;
  FILE *fp;
  if(fp=fopen("input.bin", "rb")== NULL)
  {

      printf ("error");
      exit(1);
  }
  while(1)
  {
     if(fp==EOF) break;
     current=(list*)malloc(sizeof(list));
     if(current==NULL)
     {
       break;
     }
     if(fread(&current->value,sizeof(item),1,fp) != 1)
     {
        printf  ("error");

     }
     current->next=root;
     root=current;


   }
   return root;



}

list * ReadFromFile2(list * root)
{

  list * current;
  list *temp;
  FILE *fp;
  if(fp=fopen("input.bin", "rb")== NULL)
  {

      printf ("error");
      exit(1);
  }
  while(1)
  {
     if(fp==EOF) break;
     temp=(list*)malloc(sizeof(list));
     if(fread(&temp->value,sizeof(item),1,fp) != 1)
     {

         break;
     }

     if(root==NULL)
     {
         root=temp;
         current=root;
         current->next=NULL;

     }
     else
     {
         current->next=temp;
         current=temp;
         current->next=NULL;


     }


     }
     return root;

}


list *add(item x,list * current)
{
    list *new_item=(list*)malloc(sizeof(list));
    new_item->value=x;
    current->next=new_item->next;
    current->next=new_item;


}
