#include <stdio.h>
#include <stdlib.h>

struct item
{
    int ID;
    char name[20];
};
typedef struct item item;


struct list
{
    item value;
    struct list *next;

};
typedef struct list list;

int main()
{


}

list * readFromFile(list *root)
{
    list * current;
    FILE * fp;

    if(fp=fopen("da.txt","wb") != NULL)
    {


    }
    while(1)
    {
        if(fp==EOF) break;
        current=malloc;
        if(current==NULL) break;
        if(fread(&current->value,sizeof(item),1,fp) != 1)
        {

            break;
        }

        current->next=root;
        root=current;

    }


}

list *readFromFile2(list *root)
{
    list *current;
    list *temp;



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


void deleteItem(list *root)
{
    list * current=root;
    list * previous=root;
    int flag=0;

    for(current=root;current!=NULL;current=current->next)
    {

        if(current->value.ID==5)
        {

            if(current==root)
            {
                root=root->next;
            }
            else
            {
                previous->next=current->next;
            }
            free(current);



        }




        previous=current;
    }


}

list *add(item x;list *current)
{
    list *new_item=malloc;
    new_item->value=x;
    new_item->next=current->next;
    current->next=new_item;
}
