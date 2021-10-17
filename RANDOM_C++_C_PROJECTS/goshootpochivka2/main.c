#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct medicine
{
    char ID[20];
    char nameOfMedicine[30];
    double price;
    char date[11];
    struct medicine *next;

};
typedef struct medicine medicine;
medicine *head= NULL;
medicine *current=NULL;


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
       printf (" Press 1 to add new medicine.\n ");
       printf ("Press 2 to update medicine price.\n ");
       printf ("Press 3 to list all medicine with expired date.\n ");
       printf ("Press 4 to search medicine with ID number.\n ");
       printf ("Press (5) to list all medicines.\n ");
       printf ("Press (0) to exit the program.\n\n\n");


       printf ("Enter option:  ");
       scanf("%d", &choice);
       fflush(stdin);
       switch(choice)
       {

           case 1: addMedicine(); break;
           case 2: updatePrice(); break;
           case 3: listExpiredDateMedicines(); break;
           case 4: searchMedicine(); break;
           case 5: listAllMedicines(); break;

           case 0: printf ("\nYou exited the program.");  break;
           default: printf ("\nWrong operation: ");

       }

    if(choice==0) break;

    }
}

void addMedicine()
{
    char year[10],month[10],day[10];

    char tempDayMonthYear[10];

    medicine *temp=(medicine*)malloc(sizeof(medicine));

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
    gets(temp->ID);

    printf ("Enter name: ");
    gets(temp->nameOfMedicine);

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



    strcat(temp->date,day);
    strcat(temp->date,month);
    strcat(temp->date,year);


    fflush(stdin);


}



void updatePrice()
{

  medicine *temp = (medicine*)malloc(sizeof(medicine));


   char name[80];

    bool isFound=false;

    printf ("Enter name: ");
    gets(name);

    for(temp=head; temp!=NULL; temp=temp->next)

        {
            if (strcmp(name,temp->nameOfMedicine) == 0)
            {

            printf ("\nOld Price : is %lf\n",temp->price);
            isFound=true;
            break;

            }

        }

        if(isFound==false) printf ("Medicine with name '%s' cannot be found\n", name);

        else
        {
        printf ("Enter new price:  ");
        scanf ("%lf", &temp->price);

        }




}

void searchMedicine()
{

    medicine *temp = (medicine*)malloc(sizeof(medicine));


   char ID[80];

    bool isFound=false;

    printf ("Enter ID: ");
    gets(ID);

    for(temp=head; temp!=NULL; temp=temp->next)

        {
            if (strcmp(ID,temp->ID) == 0)
            {

               printf ("\nID : %s ",temp->ID);
               printf ("\nName : %s",temp->nameOfMedicine);
               printf ("\nPrice : %lf",temp->price);
               printf ("\nID : %s ",temp->date);
               printf ("\n\n");
            isFound=true;
            break;

            }

        }

        if(isFound==false) printf ("Medicine with ID '%s' cannot be found\n", ID);

        else
        {
        printf ("Enter new price:  ");
        scanf ("%lf", &temp->price);

        }



}

void listAllMedicines()
{
   medicine *temp = (medicine*)malloc(sizeof(medicine));

   for(temp=head;temp!=NULL;temp=temp->next)
   {

       printf ("\nID : %s ",temp->ID);
       printf ("\nName : %s",temp->nameOfMedicine);
       printf ("\nPrice : %lf",temp->price);
       printf ("\nID : %s ",temp->date);
       printf ("\n\n");

   }



}

void listExpiredDateMedicines()
{
   char day[10],month[10],year[10];
   char tempDayMonthYear[10];
   medicine *temp = (medicine*)malloc(sizeof(medicine));

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

    printf ("%s %s %s", day,month,year);




   for(temp=head;temp!=NULL;temp=temp->next)
   {

       if(atoi(year)> ((atoi(temp->date[4]))*1000 + (atoi(temp->date[5]))*100 + (atoi(temp->date[6])*10) + atoi(temp->date[7])))
       {
         printf ("skr");

       }




   }






}




void writeToFile()
{
    FILE * fp;
    medicine *temp = (medicine*)malloc(sizeof(medicine));


    if((fp=fopen("medicine.bin","wb"))==NULL)
    {
        printf("Error opening tile1");
        exit(1);
    }

    for(temp=head; temp!=NULL; temp=temp->next)

        {
             if(fwrite(temp, sizeof(struct medicine), 1, fp) != 1)
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


    if((fp=fopen("medicine.bin","rb"))==NULL)
    {
        menu();
        writeToFile();
        exit(1);
    }

    while(1)
    {


    medicine *temp=(medicine*)malloc(sizeof(medicine));

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


     if(fread(temp, sizeof(struct medicine), 1, fp) != 1)
     {
         break;
         printf ("Error in reading file");
         exit(0);
     }


    }
    fclose(fp);

}
