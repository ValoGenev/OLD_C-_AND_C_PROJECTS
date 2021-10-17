#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
void main()
{
  int choice;
    printf ("Welcome to DSK Bank\n\n");
    printf ("Please login into your account (1)\n\nMake new account (2)");
    scanf ("%d", &choice);
    fflush(stdin);
    switch(choice)
    {
        case 1: loginIntoAccount(); break;
        case 2: createNewAccount(); break;
    }

    return 0;
}
void createNewAccount()
{
   struct account user;

    FILE *fp;

    printf("enter name: ");
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


      if((fp=fopen("fitness","ab"))==NULL)
        printf("cant open");


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
        printf("error");

      fclose(fp);

}
void loginIntoAccount()
{

      struct account user;
      FILE *fp;
      char login[50];
      int pass,result;

      printf ("Enter your account name: ");
      gets(login);
      printf ("Enter your password: ");
      scanf ("%d",  &pass);


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

         result = strcmp(user.name, login);

         if(result == 0 && pass == user.passWord)
         {

            clearScreen();

            printf ("\n\nName: %s\n", user.name);
            printf ("Second Name: %s\n", user.secondName);
            printf ("Password: %d\n", user.passWord);
            printf ("Money: %d\n", user.money);
            printf ("Age: %d\n\n\n", user.age);

            printf ("Enter option");
            printf ("\nPress 1 to withdraw");
            printf ("\nPress 2 to withdraw to transfer money");
            printf ("\nPress 3 to to go to main menu");

         }

    }

    fclose(fp);
}




