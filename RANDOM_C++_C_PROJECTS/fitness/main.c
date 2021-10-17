#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct fitnes
{
   int sizeOfName;
   int ednokratna;
   char fitnesName[50];
   int mesechna;
};
void main()
{
 char choise;

 printf("Enter 1 for writening in file and 2 for reading!\n");
 choise=getchar();
 fflush(stdin);


 switch(choise)
 {
 case '1':
 writing();
 break;
 case '2':
 reading();
 break;
 }
 return 0;

    return 0;
}
void writing()
{
   struct fitnes fitnes;

    FILE *fp;

    printf("enter the name of fitness: \n");
    gets(&fitnes.fitnesName);


    fitnes.sizeOfName=(sizeof(fitnes.fitnesName));


    printf("Enter the price of 1 day training");
    scanf("%d",&fitnes.ednokratna);

    printf("enter the price of 30 days of training");
    scanf("%d",&fitnes.mesechna);


      if((fp=fopen("fitness","ab"))==NULL)
        printf("cant open");


        if(fwrite(&fitnes.sizeOfName,sizeof(int),1,fp)!=1)
                     printf("error");
        if(fwrite(fitnes.fitnesName,sizeof (fitnes.fitnesName),1,fp)!=1)
                    printf("error");

        if(fwrite(&fitnes.ednokratna,sizeof(int),1,fp)!=1)
        printf("error");

        if(fwrite(&fitnes.mesechna,sizeof(int),1,fp)!=1)
            printf("error");
    fclose(fp);

}
void reading()
{
      int result;
      char name[50];
      struct fitnes fitnes;

      FILE *fp;
      printf ("vuvedi ime ");
      gets(name);

    if((fp=fopen("fitness","rb"))==NULL)
        printf("the file cant open");

    for(;;)
    {

        if(fread(&fitnes.sizeOfName,sizeof(int),1,fp)!=1)
        {
            printf("readung 1 error");             exit(1);
        }

        if(fread(fitnes.fitnesName,1,fitnes.sizeOfName,fp)!=fitnes.sizeOfName)
        {
            printf("reading2 error");             exit(7);
        }


        if(fread(&fitnes.ednokratna,sizeof(int),1,fp)!=1)
        {
            printf("reading3 error");             exit(5);
        }


        if(fread(&fitnes.mesechna,sizeof(int),1,fp)!=1)
        {
            printf("reading 4error");             exit(6);
        }


        result = strcmp(fitnes.fitnesName, name);


        if(result == 0)
        {
            printf ("Fitness name: %s\n", fitnes.fitnesName);
            printf ("Price for 1 day: %d\n", fitnes.ednokratna);
            printf ("Price for 30 days: %d\n", fitnes.mesechna);
            break;
        }
    }

    fclose(fp);
}

