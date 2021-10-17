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

   test();


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

      clearScreen();
      menu();

}
void loginIntoAccount()
{

      struct account user;
      FILE *fp;
      char login[50];
      int pass,result,i=1;

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
            account(user.money, i);
            fclose(fp);

         }
         i++;

    }

    fclose(fp);
}
void clearScreen()
{
    system("cls");

}
int account(int money, int i)
{
    int choice;
    printf ("Enter option");
    printf ("\nPress 1 to withdraw");
    printf ("\nPress 2 to transfer money");
    printf ("\nPress 3 to go to main menu");
    printf ("\nPress 4 to exit");
    scanf ("%d", &choice);

    fflush(stdin);
    switch(choice)
    {
        case 1: withDraw(money, i); break;
        case 2: transfer(); break;
        case 3: menu(); break;
        case 4: exit(0); break;

    }
}

void menu()
{
    clearScreen();
    int choice;
    printf ("Welcome to DSK Bank\n\n");
    printf ("Please login into your account (1)\n\nMake new account (2)\n\nInformation (3)");
    scanf ("%d", &choice);
    fflush(stdin);
    switch(choice)
    {
        case 1: loginIntoAccount(); break;
        case 2: createNewAccount(); break;
        case 3: information(); break;
    }
}

void withDraw(int money,int i)
{
   int withdraw;
   printf ("Your total is: %d $ and you have %d \n", money,i);
   printf ("Amount of money you want to withdraw: ");
   scanf ("%d", &withdraw);
   money=money-withdraw;
   FILE *fp2;
   if (fp2=fopen("fitness", "wb")== NULL)
   {
       printf  ("error in file opening");
   }
   i=(i*120)-sizeof(int);
   if (fseek(fp2,i,SEEK_SET)== 0)
   {
       fwrite (&money,sizeof(int),1, fp2);
   }
   else printf ("error in fseek");


   printf ("Sucsessfully transfered you have now %d", money);


}

void transfer()
{

}
void information()
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
            printf ("Age: %d\n", user.age);
            printf ("Money: %d\n\n\n", user.money);

    }
}
void test()
{
    char name[50];
    FILE *fp;
    int chislo;

    if (fp=fopen("fitness", "wb") == NULL)
        printf ("mazna greshka");

    printf ("vuvedi novo ime");
       scanf ("%d", &chislo);
      if(fseek(fp,108,SEEK_SET)==NULL)
      {

                    printf("error");
      }
         fclose(fp);
}
