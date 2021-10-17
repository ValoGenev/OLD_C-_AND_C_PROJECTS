#include<stdio.h>
#include<stdlib.h>
 struct Item {
    char name[31];
    int ID;
    char godnost[11];
    float price;
};
typedef struct Item Item;


struct List{
Item val;
struct List *next;
};
typedef struct List List;




List * ReadFromFile(List * root)
{
    List * new_item=NULL;
    FILE *fp = fopen("input.bin","rb");
    if(fp == NULL){printf("can't open file");}
    while(1)
    {
        if(fp==EOF)break;
        new_item=(List *)malloc(sizeof(List));
        if(new_item==NULL)break;
        if(fread(&new_item->val,sizeof(Item),1,fp)!=1)break;
        new_item->next = root;
        root = new_item;
    }
    return root;
}

 void expiresIn(char * date,List * root)
 {
     List * curr_item=root;
     while(curr_item!=NULL)
     {
         if(strcmp(date,curr_item->val.godnost)<0)
            printf("%s %f\n",curr_item->val.name,curr_item->val.price);
         curr_item=curr_item->next;
     }
 }

 List * isIn(int ID, List* root)
 {
    List * curr_item=root;
     while(curr_item!=NULL)
     {
         if(ID==curr_item->val.ID)
            return curr_item;
         curr_item=curr_item->next;
     }
     return NULL;
 }

 void ADD(Item el,List* curr_item)
 {
     List * next_item = (List *)malloc(sizeof(List));
     next_item->val=el;
     next_item->next=curr_item->next;
     curr_item->next=next_item;
 }



 int main()
 {




     return 0;
 }
