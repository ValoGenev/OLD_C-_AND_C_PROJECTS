#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct library
{
    char ID[20];
    char title[80];
    char author[80];
    double price;
    int yearPublished;
    char publisher[80];



};
typedef struct library library;


struct List
{
  library value;
  struct List * next;

};
typedef struct List List;


struct Stack
{
    library value;
    struct Stack *next;

};
typedef struct Stack Stack;

Stack *headStack=NULL;
List *head=NULL;
List *current=NULL;

bool checkIfExist();


int main()
{
   readFromFile();
   menu();
   writeToFile();

	return 0;
}

void menu()
{
    int choice;
    while(1)
    {
       printf (" Press (1) to add new book.\n ");
       printf ("Press (2) to sort.\n ");
       printf ("Press (5) to list all books.\n ");
       printf ("Press (0) to exit the program.\n\n\n");


       printf ("Enter option:  ");
       scanf("%d", &choice);
       fflush(stdin);
       switch(choice)
       {

           case 1: addNewBook(); break;
           case 2: sort(); break;
           case 5: listAll(); break;


           case 0: printf ("\nYou exited the program.");  break;
           default: printf ("\nWrong operation: ");

       }

    if(choice==0) break;

    }



}
void listStack()
{
    Stack *tempStack;

   for(tempStack=headStack;tempStack!=NULL;tempStack=tempStack->next)
   {

            printf ("\nId is %s", tempStack->value.ID);
            printf ("\nTitle is %s", tempStack->value.title);
            printf ("\nAuthor is %s", tempStack->value.author);
            printf ("\nPrice is %ld", tempStack->value.price);
            printf ("\nPublished in year  %d", tempStack->value.yearPublished);
            printf ("\nPublisher is %s\n", tempStack->value.publisher);

   }
}

void sort()
{

    library tempLibrary;
    List *temp;
    Stack *tempStack;

    for(temp=head;temp!=NULL;temp=temp->next)
    {
        tempStack=(Stack*)malloc(sizeof(Stack));
        tempStack->value=temp->value;
        tempStack->next=headStack;
        headStack=tempStack;

    }



   for(tempStack=headStack;tempStack!=NULL;tempStack=tempStack->next)
   {

      for(Stack * x=tempStack->next;x!=NULL;x=x->next)
      {
          if(tempStack->value.price > x->value.price)
          {
              tempLibrary=tempStack->value;
              tempStack->value=x->value;
              x->value=tempLibrary;
          }

      }

   }


}



void addNewBook()
{

  List *temp=(List*)malloc(sizeof(List));
  char ID[20];
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

  printf("Enter reader ID:\n");
  while(!checkIfExist(gets(ID)))
  {
    printf ("Enter ID: ");

  }
  strcpy(temp->value.ID,ID);


  printf("Enter title:\n");
  gets(temp->value.title);


  printf("Enter author:\n");
  gets(temp->value.author);


  printf("Enter price:\n");
  scanf("%ld",&temp->value.price);

  printf ("Enter year published:\n");
  scanf("%d",&temp->value.yearPublished);
  fflush(stdin);

  printf ("Enter publisher:\n");
  gets(temp->value.publisher);
  fflush(stdin);




}

void listAll()
{

    char title[80];
    List *temp;



    for(temp=head; temp!=NULL; temp=temp->next)

        {

            printf ("\nId is %s", temp->value.ID);
            printf ("\nTitle is %s", temp->value.title);
            printf ("\nAuthor is %s", temp->value.author);
            printf ("\nPrice is %ld", temp->value.price);
            printf ("\nPublished in year  %d", temp->value.yearPublished);
            printf ("\nPublisher is %s\n", temp->value.publisher);


        }




}



void writeToFile()
{
    FILE * fp;
    List *temp = (List*)malloc(sizeof(List));


    if((fp=fopen("Readers.bin","wb"))==NULL)
    {
        printf("Error opening tile1");
        exit(1);
    }

    for(temp=head; temp!=NULL; temp=temp->next)

        {
             if(fwrite(&temp->value, sizeof(library), 1, fp) != 1)
            {
                printf ("Error in writing file");
                exit(0);
            }

        }


    fclose(fp);
}

void readFromFile()
{
    FILE *fp;


    if((fp=fopen("Readers.bin","rb"))==NULL)
    {
        menu();
        writeToFile();
        exit(1);
    }

    while(1)
    {


    List *temp=(List*)malloc(sizeof(List));

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


     if(fread(&temp->value, sizeof(struct library), 1, fp) != 1)
     {
         break;
         printf ("Error in reading file");
         exit(0);
     }


    }
    fclose(fp);

}


bool checkIfExist(char *string)
{

    List *temp;
    bool isFound=false;

    for(temp=head; temp!=NULL; temp=temp->next)

        {
            if (strcmp(temp->value.ID,string) == 0)
            {

            isFound=true;
            break;
            }

        }

        if (isFound)
        {
            printf ("Book with same ID already exist\n");
            return false;

        }

       return true;


}










