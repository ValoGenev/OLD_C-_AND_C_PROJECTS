#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Facility {
 int ID;
 char name_of_facility[50];
 char name_of_industry[30];
 int profit;
 int loans;
 int number_of_workers;
 struct Facility *next;
};
typedef struct Facility Facility;

   Facility *head;
   Facility *current;


 int main()
 {

   Facility *temp =(Facility*)malloc(sizeof(Facility));

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
    printf("Enter ID\n");
    scanf ("%d", &temp->ID);
    fflush(stdin);

    printf("Enter name of facility\n");
    gets(temp->name_of_facility);

    printf("Enter the industry\n");
    gets(temp->name_of_industry);

    printf("Enter profit\n");
    scanf ("%d", &temp->profit);

    printf("Enter loans\n");
    scanf ("%d", &temp->loans);

    printf("Enter number of workers\n");
    scanf ("%d", &temp->number_of_workers);



 return 0;
 }
