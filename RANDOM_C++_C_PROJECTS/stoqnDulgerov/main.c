#include <stdio.h>
#include <stdlib.h>
struct Cage{
    char type[10];
    int age;
    char id[10];
};
typedef struct Cage Cage;

struct QueueNode
{
    Cage node;
    struct QueueNode *next;
};
typedef struct QueueNode QueueNode;


struct StackNode
{
    Cage cage;
    struct StackNode *next;
};
typedef struct StackNode StackNode;






void load_newcomers(QueueNode *root)
{
    QueueNode *current=NULL;
    QueueNode *item=NULL;
    FILE *fp;
    if((fp=fopen("newcomers.bin","rb"))==NULL)
        {
            printf("Error opening file\n");
            exit(1);
        }
        while(1)
        {
            if(feof(fp))
                break;
            item=(QueueNode*)malloc(sizeof(QueueNode));
            if(fread(&item->node,sizeof(Cage),1,fp)!=1)
            {
                break;
                printf("Error reading file");
            }
            if(root=NULL)
            {
                root=item;
                current=root;
                current->next=NULL;
            }
            else
            {
                current->next=item;
                current=current->next;
                current->next=NULL;
            }

        }

}
int animal_typecnt(QueueNode *root,char *animalType)
{
    int count=0;
    QueueNode *current=root;
    while(current!=NULL)
    {
        if(strcmp(animalType,current->node.type)==0)
            count++;
        current=current->next;
    }
    return count;
}

StackNode *deworming(QueueNode *root)

{
     int temp=0;
     StackNode *new_item=NULL;


    FILE *fp;
    if((fp=fopen("newcomers.bin","rb"))==NULL)
        {
            printf("Error opening file\n");
            exit(1);
        }
        while(1)
        {
            if(feof(fp))
                break;

            new_item=(StackNode*)malloc(sizeof(StackNode));

            if(fread(&new_item->cage,sizeof(Cage),1,fp)!=1)
                break;

                new_item->next=root;
                root=new_item;
                if(new_item->cage.age < new_item->next->cage.age)
                {
                temp=new_item->cage.age;
                new_item->cage.age=new_item->next->cage.age;
                new_item->next->cage.age=temp;
                }
        }
        return new_item;


        }
