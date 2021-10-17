#include <stdio.h>
#include <stdlib.h>

struct account
{
    char name[50];
    char secondName[50];
    int age;
    int passWord;
    int money;
    int lenght;
    int lenght2;

};
int main()
{
    struct account user;

   int pari;
   char name[50];
    FILE *fp;
    if((fp=fopen("fitness","rb+"))==NULL)
        printf("cant open");




   /* printf("enter name: ");
    gets(user.name);
    printf("enter second name: ");
    gets(user.secondName);
    user.lenght=sizeof(user.name);
    user.lenght2=sizeof(user.secondName);
    printf("Enter password: ");
    scanf("%d",&user.passWord);
    printf("enter age: ");
    scanf("%d",&user.age);
    printf("enter money: ");
    scanf("%d",&user.money);




        if(fwrite(&user.lenght,sizeof(int),1,fp)!=1)
                     printf("error");
        if(fwrite(user.name,sizeof (user.name),1,fp)!=1)
                    printf("error");

        if(fwrite(&user.lenght2,sizeof(int),1,fp)!=1)
        printf("error");

        if(fwrite(user.secondName,sizeof(user.name),1,fp)!=1)
        printf("error");

        if(fwrite(&user.passWord,sizeof(int),1,fp)!=1)
        printf("error");

        if(fwrite(&user.age,sizeof(int),1,fp)!=1)
        printf("error");

        if(fwrite(&user.money,sizeof(int),1,fp)!=1)
        printf("error"); */


       printf ("vuvedi novo ime");
       gets(name);
      fseek(fp,4,SEEK_SET);
      if (fread(user.name,1,50,fp)!= 50)
        printf ("error");
      printf ("%s", user.name);
      if(fwrite(name,sizeof (name),1,fp)!=1)
                    printf("error");

      fclose(fp);
}
void reading()
{
    FILE *fp;
    struct account user;
    if((fp=fopen("fitness","rb"))==NULL)
        printf("the file cant open");

    for(;;)
    {

        if(fread(&user.lenght,sizeof(int),1,fp)!=1)
        {
            printf("readung 1 error");
            exit(1);
        }

        if(fread(user.name,1,user.lenght,fp)!=user.lenght)
        {
            printf("reading2 error");
            exit(2);
        }


        if(fread(&user.lenght2,sizeof(int),1,fp)!=1)
        {
            printf("reading error");
            exit(3);
        }

        if(fread(user.secondName,1,user.lenght2,fp)!=user.lenght2)
        {
            printf("reading4 error");
            exit(4);
        }

        if(fread(&user.passWord,sizeof(int),1,fp)!=1)
        {
            printf("reading 5error");
            exit(5);
        }

        if(fread(&user.age,sizeof(int),1,fp)!=1)
        {
            printf("reading 6error");
            exit(6);
        }

        if(fread(&user.money,sizeof(int),1,fp)!=1)
        {
            printf("reading 7error");
            exit(7);
        }

            printf ("\n\nName: %s\n", user.name);
            printf ("Second Name: %s\n", user.secondName);
            printf ("Password: %d\n", user.passWord);
            printf ("Money: %d\n", user.money);
            printf ("Age: %d\n\n\n", user.age);
    }
}

