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

    struct library* next;

};
typedef struct library library;
library *head=NULL;
library *current=NULL;









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
       printf ("Press (2) to update book information.\n ");
       printf ("Press (3) to search book by inserting [title].\n ");
       printf ("Press (4) to search book by inserting  [author].\n ");
       printf ("Press (5) to list all books.\n ");
       printf ("Press (6) to delete all books.\n ");

       printf ("Press (0) to exit the program.\n\n\n");


       printf ("Enter option:  ");
       scanf("%d", &choice);
       fflush(stdin);
       switch(choice)
       {

           case 1: addNewBook(); break;
           case 2: updateInformation(); break;
           case 3: searchByTitle(); break;
           case 4: searchByAuthorName(); break;
           case 5: listAll(); break;
           case 6: deletePls(); break;

           case 0: printf ("\nYou exited the program.");  break;
           default: printf ("\nWrong operation: ");

       }

    if(choice==0) break;

    }



}


void addNewBook()
{

  library *temp=(library*)malloc(sizeof(library));
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
  strcpy(temp->ID,ID);


  printf("Enter title:\n");
  gets(temp->title);


  printf("Enter author:\n");
  gets(temp->author);


  printf("Enter price:\n");
  scanf("%ld",&temp->price);

  printf ("Enter year published:\n");
  scanf("%d",&temp->yearPublished);
  fflush(stdin);

  printf ("Enter publisher:\n");
  gets(temp->publisher);
  fflush(stdin);




}
void updateInformation()
{

    int choice;
    char name[80];
    library *temp;
    bool isFound=false;

    printf ("Enter name of book to update information");
    gets(name);

    for(temp=head; temp!=NULL; temp=temp->next)

        {
            if (strcmp(name,temp->title) == 0)
            {
            printf ("Old iformation about book:\n\n");
            printf ("\nCurrent Id is %s", temp->ID);
            printf ("\nCurren Title is %s", temp->title);
            printf ("\nCurren Author is %s", temp->author);
            printf ("\nCurren Price is %ld", temp->price);
            printf ("\nCurren Published in year  %d", temp->yearPublished);
            printf ("\nCurren Publisher is %s\n\n\n", temp->publisher);

             isFound=true;


            printf ("Do you want to change the ID\nPress (1) to change it. Press (2) to skip.\n");
            scanf ("%d", &choice);
            if(choice==1)
            {
                 fflush(stdin);
                printf("Enter reader ID:\n");
                gets(temp->ID);
                 fflush(stdin);
            }


            printf ("Do you want to change the title\nPress (1) to change it. Press (2) to skip.\n");
            scanf ("%d", &choice);
            if(choice==1)
            {
                 fflush(stdin);
                 printf("Enter title:\n");
                 gets(temp->title);
                  fflush(stdin);

            }



            printf ("Do you want to change the author name\nPress (1) to change it. Press (2) to skip.\n");
            scanf ("%d", &choice);
            if(choice==1)
            {
                 fflush(stdin);
                printf("Enter author:\n");
                gets(temp->author);
                 fflush(stdin);

            }


            printf ("Do you want to change the price\nPress (1) to change it. Press (2) to skip.\n");
            scanf ("%d", &choice);
            if(choice==1)
            {
                 fflush(stdin);
                 printf("Enter price:\n");
                 scanf("%ld",&temp->price);
                  fflush(stdin);

            }




            printf ("Do you want to change the year of publishment\nPress (1) to change it. Press (2) to skip.\n");
            scanf ("%d", &choice);
            if(choice==1)
            {
                 fflush(stdin);
                 printf("Enter year of publishment:\n");
                 scanf("%d",&temp->yearPublished);
                  fflush(stdin);

            }


            printf ("Do you want to change the publisher\nPress (1) to change it. Press (2) to skip.\n");
            scanf ("%d", &choice);
            if(choice==1)
            {
                 fflush(stdin);
                printf("Enter publisher:\n");
                gets(temp->publisher);
                 fflush(stdin);

            }

             break;

            }


        }


        if(isFound==false) printf ("Book with name '%s' cannot be found\n", name);


}

void listAll()
{

    char title[80];
    library *temp;



    for(temp=head; temp!=NULL; temp=temp->next)

        {

            printf ("\nId is %s", temp->ID);
            printf ("\nTitle is %s", temp->title);
            printf ("\nAuthor is %s", temp->author);
            printf ("\nPrice is %ld", temp->price);
            printf ("\nPublished in year  %d", temp->yearPublished);
            printf ("\nPublisher is %s\n", temp->publisher);


        }




}

void searchByTitle()
{
    char title[80];
    library *temp;
    bool isFound=false;

    printf ("Enter title: ");
    gets(title);

    for(temp=head; temp!=NULL; temp=temp->next)

        {
            if (strcmp(title,temp->title) == 0)
            {
            printf ("\nId is %s", temp->ID);
            printf ("\nTitle is %s", temp->title);
            printf ("\nAuthor is %s", temp->author);
            printf ("\nPrice is %ld", temp->price);
            printf ("\nPublished in year  %d", temp->yearPublished);
            printf ("\nPublisher is %s\n", temp->publisher);
            isFound=true;
            break;

            }

        }
        if(isFound==false) printf ("Author with name '%s' cannot be found\n", title);
}

void searchByAuthorName()
{
    char author[80];
    library *temp;
    bool isFound=false;

    printf ("Enter author: ");
    gets(author);

    for(temp=head; temp!=NULL; temp=temp->next)

        {
            if (strcmp(author,temp->author) == 0)
            {
            printf ("\nId is %s", temp->ID);
            printf ("\nTitle is %s", temp->title);
            printf ("\nAuthor is %s", temp->author);
            printf ("\nPrice is %ld", temp->price);
            printf ("\nPublished in year  %d", temp->yearPublished);
            printf ("\nPublisher is %s\n", temp->publisher);
            isFound=true;
            break;

            }

        }
        if(isFound==false) printf ("Author with name '%s' cannot be found\n", author);

}

void writeToFile()
{
    FILE * fp;
    library *temp = (library*)malloc(sizeof(temp));


    if((fp=fopen("Readers.bin","wb"))==NULL)
    {
        printf("Error opening tile1");
        exit(1);
    }

    for(temp=head; temp!=NULL; temp=temp->next)

        {
             if(fwrite(temp, sizeof(struct library), 1, fp) != 1)
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


    library *temp=(library*)malloc(sizeof(library));

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


     if(fread(temp, sizeof(struct library), 1, fp) != 1)
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

    library *temp;
    bool isFound=false;

    for(temp=head; temp!=NULL; temp=temp->next)

        {
            if (strcmp(temp->ID,string) == 0)
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

void deletePls()
{

    char name[20];

  library *current=head;
  library *previous=head;

  printf ("Enter title: ");
  gets(name);

  for(current=head;current!=NULL;current=current->next)
  {

    if(strcmp(name,current->title)== 0)
    {
        if(current==head)
        head=head->next;

        else previous->next=current->next;

        free(current);
        break;

    }

    previous=current;


  }







}












