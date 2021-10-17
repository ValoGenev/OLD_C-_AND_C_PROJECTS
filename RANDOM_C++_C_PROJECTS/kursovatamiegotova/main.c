#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char fileRead[20];
    char fileResult[20];

    int options;
    printf ("\nMenu:\n\n1.Chetene na programata of fail i zapis na rezultata\n2.Chetene na programata ot fail i izvejdane na rezultata na ekreana\n3,Chetene na programata ot klavietura i izvejdane vuv fail\n4.Chetene na programata ot klavieturata i izvejdane na ekrana\n");
    scanf("%d", &options);
    switch(options)
    {
        case 1:
                   printf ("Vuvedeto ima na faila za chetene: ");
                   scanf("%s", &fileRead);
                   printf ("Vuvedi ime na faila za zapis na rezultata: ");
                   scanf("%s", &fileResult);
                   firstOption(fileRead,fileResult);
                   break;

        case 2:  printf ("Vuvedeto ima na faila za chetene: ");
                   scanf("%s", &fileRead);
                   secondOption(fileRead);
                   break;

        case 3:   printf ("Vuvedeto ima na faila za chetene: ");
                   scanf("%s", &fileRead);
                   printf ("Vuvedi ime na faila za zapis na rezultata: ");
                   scanf("%s", &fileResult);
                   thirdOption(fileRead,fileResult);
                   break;

        case 4:  printf ("Vuvedeto ima na faila za chetene: ");
                   scanf("%s", &fileRead);
                   fourthOption(fileRead);
                   break;

    }
}
void firstOption(char name1[],char name2[])
{
    int smallLine=0;
    int ifoperator=0;
    char line[100];
    char symbol[5];
    int k=0;
    char ch[100];
    int lines=0;
    int space=0;
    int oldLenght;
    int checkForLines;

    int operators=0;
   FILE * fpointer1;
   if(!(fpointer1=fopen(name1, "r"))) printf ("greshka");

   while(fscanf(fpointer1, "%s", &line) != EOF)
   {


       for(k=0;k<strlen(line);k++)
       {
           ch[k] = line[k];
                ch[k]=line[k];
           if(ch[k] == 'f' && ch[k-1]== 'i' ) ifoperator++;
           if  (ch[k]=='e' && ch[k-1]== 's' && ch[k-2]== 'l' && ch[k-3]== 'e') ifoperator++;


         if(ch[k]=='-' || ch[k]=='+' || ch[k]=='*' || ch[k]=='/' || ch[k]=='*' || ch[k]=='%' || ch[k]=='^') operators++;

       }



   }



   fclose(fpointer1);
   FILE * fpointer2=fopen(name2, "w");
   fprintf (fpointer2, "Ima %d if/else operatori\nA broq na operatire e %d", ifoperator, operators);
   fclose(fpointer2);
}
void secondOption(char name1[])
{
    int space=0;
    int smallLine=0;
   int ifoperator=0;
    char line[100];
    char symbol[5];
    int k=0;
    char ch[100];
    int lines=0;
    char checkForLines;
    int number=0;
    int oldLenght;
    int operators=0;
   FILE * fpointer1;
   if(!(fpointer1=fopen(name1, "r"))) printf ("greshka");


   while(fscanf(fpointer1, "%s", &line) != EOF)
   {
       for(k=0;k<strlen(line);k++)
       {
           ch[k] = line[k];
                ch[k]=line[k];
            if(ch[k] == 'f' && ch[k-1]== 'i' ) ifoperator++;
           if  (ch[k]=='e' && ch[k-1]== 's' && ch[k-2]== 'l' && ch[k-3]== 'e') ifoperator++;
           if(ch[k]=='-' || ch[k]=='+' || ch[k]=='*' || ch[k]=='/' || ch[k]=='*' || ch[k]=='%' || ch[k]=='^') operators++;

       }

   }
   rewind(fpointer1);
    while (fscanf(fpointer1, "%c", &checkForLines) != EOF)
    {
        if (checkForLines=='\n') number++;
    }
   fclose(fpointer1);
   printf ("Ima %d if/else operatori\nA broq na operatorite e %d", ifoperator, operators);
}
void thirdOption(char name1[],char name2[])
{

    char line[1024];
   FILE * fpointer1;
   FILE * fpointer2;
   if(!(fpointer1=fopen(name1, "r"))) printf ("greshka");
   if(!(fpointer2=fopen(name2, "w"))) printf ("greshka");

   while(fscanf(fpointer1, "%c", &line) != EOF)
   {
     if(line=='\n') fprintf(fpointer2, "\n");
     else fprintf(fpointer2, "%s", line);
   }
   fclose(fpointer1);
   fclose(fpointer2);
}
void fourthOption(char name1[])
{
    int a;
    char line[1024];
   FILE * fpointer1;
   if(!(fpointer1=fopen(name1, "r"))) printf ("greshka");

   while(fscanf(fpointer1, "%s", &line) != EOF)
   {
     printf ("%s\n",line);

    }
   fclose(fpointer1);
}
