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
           case 5:  listBooks(); break;
           case 0: printf ("\nYou exited the program.");  exit(1);
           default: printf ("\nWrong operation: ");

       }



    }



}
void listBooks()
{
    library *m;
    for(m=head; m!=NULL; m=m->next)

        {
            printf ("\nId is %s", m->ID);
            printf ("\nTitle is %s", m->title);
            printf ("\nAuthor is %s", m->author);
            printf ("\nPrice is %ld", m->price);
            printf ("\nPublished in year  %d", m->yearPublished);
            printf ("\nPublisher is %s\n", m->publisher);

        }

}



void addNewBook()
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

  printf("Enter reader ID:\n");
  gets(temp->ID);


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


}

void searchByTitle()
{
    char name[80];
    library *m;
    bool isFound=false;

    printf ("Enter title: ");
    gets(name);

    for(m=head; m!=NULL; m=m->next)

        {
            if (strcmp(name,m->title) == 0)
            {
            printf ("\nId is %s", m->ID);
            printf ("\nTitle is %s", m->title);
            printf ("\nAuthor is %s", m->author);
            printf ("\nPrice is %ld", m->price);
            printf ("\nPublished in year  %d", m->yearPublished);
            printf ("\nPublisher is %s\n", m->publisher);
            isFound=true;
            break;


            }


        }
        if(isFound==false) printf ("Book with name '%s' cannot be found\n", name);



}

void searchByAuthorName()
{
    char author[80];
    library *m;
    bool isFound=false;

    printf ("Enter author: ");
    gets(author);

    for(m=head; m!=NULL; m=m->next)

        {
            if (strcmp(author,m->author) == 0)
            {
            printf ("\nId is %s", m->ID);
            printf ("\nTitle is %s", m->title);
            printf ("\nAuthor is %s", m->author);
            printf ("\nPrice is %ld", m->price);
            printf ("\nPublished in year  %d", m->yearPublished);
            printf ("\nPublisher is %s\n", m->publisher);
            isFound=true;
            break;


            }


        }
        if(isFound==false) printf ("Author with name '%s' cannot be found\n", author);




}

void writeToFile()
{
int flag=0;
    FILE *fp;
    int len=0;

        if((fp=fopen("Readers.bin","wb"))==NULL)
    {
        printf("Error opening file1");
        exit(1);
    }


for(current=head;current!=NULL;current=current->next)
    {

if((fwrite(&flag, sizeof(int),1, fp))!=1)
        {
            printf("Error writing flag2!");
            exit(1);
        }


   len=strlen(&current->ID);
   if(fwrite(&len,sizeof(int),1,fp)!=1)
 {
     printf("Error2 writing file3");
     exit(1);

 }
 if(fwrite(&current->ID,sizeof(char),len,fp)!=len)
 {
      printf("Error3 writing file4");
      exit(1);

 }




 len=strlen(&current->title);
   if(fwrite(&len,sizeof(int),1,fp)!=1)
 {
     printf("Error2 writing file5");
     exit(1);

 }
 if(fwrite(&current->title,sizeof(char),len,fp)!=len)
 {
      printf("Error3 writing file6");
      exit(1);

 }



 len=strlen(&current->author);
   if(fwrite(&len,sizeof(int),1,fp)!=1)
 {
     printf("Error2 writing file5");
     exit(1);

 }
 if(fwrite(&current->author,sizeof(char),len,fp)!=len)
 {
      printf("Error3 writing file6");
      exit(1);

 }





 if(fwrite(&current->price,sizeof(double),1,fp)!=1)
 {
     printf("Error2 writing file7");
     exit(1);
 }


 if(fwrite(&current->yearPublished,sizeof(int),1,fp)!=1)
 {
     printf("Error2 writing file8");
     exit(1);
 }




 len=strlen(&current->publisher);
   if(fwrite(&len,sizeof(int),1,fp)!=1)
 {
     printf("Error2 writing file9");
     exit(1);

 }
 if(fwrite(&current->publisher,sizeof(char),len,fp)!=len)
 {
      printf("Error3 writing file10");
      exit(1);

 }


}
flag--;

    if((fwrite(&flag, sizeof(int),1, fp))!=1)
    {
        printf("Error writing flag!11");
        fclose(fp);
    }

fclose(fp);
}








void readFromFile()
{

    int flag;
    int len;
    FILE *fp;
    if((fp=fopen("Readers.bin","rb"))==NULL)
    {

        menu();
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


 if(fread(&flag, sizeof(int), 1, fp)!=1)
        {
            printf("Error reading flag\n");
            exit(4);
        }
        if (flag==-1){
            break;
        }




   if(fread(&len,sizeof(int),1,fp)!=1)
  {
        printf("Error2 reading file or no info entered yet\n");
        break;
  }
   if (fread(&temp->ID,sizeof(char),len,fp)!= len)
  {
        printf("Error3 reading file or no info entered yet\n");
        break;
  }





  if(fread(&len,sizeof(int),1,fp)!=1)
  {
        printf("Error2 reading file or no info entered yet\n");
        break;
  }
   if (fread(&temp->title,sizeof(char),len,fp)!= len)
  {
        printf("Error3 reading file or no info entered yet\n");
        break;
  }




  if(fread(&len,sizeof(int),1,fp)!=1)
  {
        printf("Error2 reading file or no info entered yet\n");
        break;
  }
   if (fread(&temp->author,sizeof(char),len,fp)!= len)
  {
        printf("Error3 reading file or no info entered yet\n");
        break;
  }





  if(fread(&temp->price,sizeof(double),1,fp)!=1)
  {
        printf("Error2 reading file or no info entered yet\n");
        break;
  }


  if(fread(&temp->yearPublished,sizeof(int),1,fp)!=1)
  {
        printf("Error2 reading file or no info entered yet\n");
        break;
  }



  if(fread(&len,sizeof(int),1,fp)!=1)
  {
        printf("Error2 reading file or no info entered yet\n");
        break;
  }
   if (fread(&temp->publisher,sizeof(char),len,fp)!= len)
  {
        printf("Error3 reading file or no info entered yet\n");
        break;
  }



    }
    fclose(fp);
}
