#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct item
{
    int ID;
    char name[50];
    double price;
    char date[11];
    int quantity;
    struct item *next;

};
typedef struct item item;
item *head= NULL;
item *current=NULL;



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
       printf (" Press 1 to add new item .\n ");
       printf ("Press 2 to update  quantity.\n ");
       printf ("Press 3 to list all items with expired date.\n ");
       printf ("Press 4 to search item with ID number.\n ");
       printf ("Press (0) to exit the program.\n\n\n");


       printf ("Enter option:  ");
       scanf("%d", &choice);
       fflush(stdin);
       switch(choice)
       {

           case 1: addItem(); break;
           case 2: updateQuantity(); break;
           case 3: listExpiredDateItems(); break;
           case 4: searchItem(); break;


           case 0: printf ("\nYou exited the program.");  break;
           default: printf ("\nWrong operation: ");

       }

    if(choice==0) break;

    }
}

void addItem()
{
    char year[10],month[10],day[10];

    char tempDayMonthYear[10];

    item *temp=(item*)malloc(sizeof(item));

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

    printf ("Enter ID: ");
    scanf("%d", &temp->ID);
    fflush(stdin);

    printf ("Enter name: ");
    gets(temp->name);

    printf ("Enter quantity: ");
    scanf("%d", &temp->quantity);

    printf ("Enter price: ");
    scanf ("%lf", &temp->price);

    fflush(stdin);
    printf ("Enter date DAY: ");
    gets(day);

    if(atoi(day) < 10)
    {
      strcpy(tempDayMonthYear,"0");
      strcat(tempDayMonthYear, day);
      strcpy(day,tempDayMonthYear);
    }


    printf ("Enter date MONTH: ");
    gets(month);

    if(atoi(month) < 10)
    {
      strcpy(tempDayMonthYear,"0");
      strcat(tempDayMonthYear, month);
      strcpy(month,tempDayMonthYear);
    }



    printf ("Enter date YEAR: ");
    gets(year);
    if(atoi(year) < 10)
    {
      strcpy(tempDayMonthYear,"0");
      strcat(tempDayMonthYear, year);
      strcpy(year,tempDayMonthYear);
    }



    strcat(temp->date,year);
    strcat(temp->date,month);
    strcat(temp->date,day);


    fflush(stdin);


}



void updateQuantity()
{

  item *temp = (item*)malloc(sizeof(item));
  int quantity;


   char name[80];

    bool isFound=false;

    printf ("Enter name of item: ");
    gets(name);

    for(temp=head; temp!=NULL; temp=temp->next)

        {
            if (strcmp(name,temp->name) == 0)
            {

            printf ("\n Quantity : is %d\n",temp->quantity);
            isFound=true;
            break;

            }

        }

        if(isFound==false) printf ("Item with name '%s' cannot be found\n", name);

        else
        {

        int choice;
        printf ("\nDo you want to add (1) quantity or remove (2):  ");
        scanf ("%d", &choice);
        if(choice==1)
        {
            printf ("\nhow much do you want to add ");
            scanf ("%d", &quantity);
            temp->quantity+=quantity;

        }

        if(choice==2)
        {

            while(1)

            {

            printf ("\nhow much do you want to remove ");
            scanf ("%d", &quantity);
            if(temp->quantity<quantity)
            {
               printf ("\nYou dont have enough quantities");
            }
            else
            {
            temp->quantity-=quantity;
            break;
            }

            }

        }


        }




}

void searchItem()
{

    item *temp = (item*)malloc(sizeof(item));


    int ID;

    bool isFound=false;

    printf ("Enter ID: ");
    scanf ("%d", &ID);

    for(temp=head; temp!=NULL; temp=temp->next)

        {
            if (temp->ID==ID)
            {

               printf ("\nID : %d ",temp->ID);
               printf ("\nName : %s",temp->name);
               printf ("\nPrice : %lf",temp->price);
               printf ("\nDate : %s ",temp->date);
               printf ("\nQuantity : %d ",temp->quantity);
               printf ("\n\n");
            isFound=true;
            break;

            }

        }

        if(isFound==false) printf ("Item with ID '%d' cannot be found\n", ID);




}



void listExpiredDateItems()
{

   item *temp = (item*)malloc(sizeof(item));
   char date[10];
   char day[10],month[10],year[10];
   char tempDayMonthYear[10];

    printf ("Enter date DAY: ");
    gets(day);

    if(atoi(day) < 10)
    {
      strcpy(tempDayMonthYear,"0");
      strcat(tempDayMonthYear, day);
      strcpy(day,tempDayMonthYear);
    }


    printf ("Enter date MONTH: ");
    gets(month);

    if(atoi(month) < 10)
    {
      strcpy(tempDayMonthYear,"0");
      strcat(tempDayMonthYear, month);
      strcpy(month,tempDayMonthYear);
    }



    printf ("Enter date YEAR: ");
    gets(year);
    if(atoi(year) < 10)
    {
      strcpy(tempDayMonthYear,"0");
      strcat(tempDayMonthYear, year);
      strcpy(year,tempDayMonthYear);
    }

    printf ("\n\n");

    strcat(date,year);
    strcat(date,month);
    strcat(date,day);




   for(temp=head;temp!=NULL;temp=temp->next)
   {
      for(int i=0;i<10;i++)
      {

          if(strcmp(date,temp->date) > 0)
          {
               printf ("\nID : %d ",temp->ID);
               printf ("\nName : %s",temp->name);
               printf ("\nPrice : %lf",temp->price);
               printf ("\nDate : %s ",temp->date);
               printf ("\Quantity : %d ",temp->quantity);

               printf ("\n\n");
               break;

          }


      }



   }


}




void writeToFile()
{
    FILE * fp;
    item *temp = (item*)malloc(sizeof(item));


    if((fp=fopen("item.bin","wb"))==NULL)
    {
        printf("Error opening tile1");
        exit(1);
    }

    for(temp=head; temp!=NULL; temp=temp->next)

        {
             if(fwrite(temp, sizeof(struct item), 1, fp) != 1)
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


    if((fp=fopen("item.bin","rb"))==NULL)
    {
        menu();
        writeToFile();
        exit(1);
    }

    while(1)
    {


    item *temp=(item*)malloc(sizeof(item));

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


     if(fread(temp, sizeof(struct item), 1, fp) != 1)
     {
         break;
         printf ("Error in reading file");
         exit(0);
     }


    }
    fclose(fp);

}
