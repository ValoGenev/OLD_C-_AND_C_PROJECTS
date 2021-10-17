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

   menu();


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
            printf ("Age: %d\n\n\n", user.age);
            printf ("Money: %d\n", user.money);
            account(user.money, i,user.name);
            fclose(fp);
            break;

         }
         i++;

    }

    fclose(fp);
}
void clearScreen()
{
    system("cls");

}
int account(int money, int i, char name[50])
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
        case 2: transfer(money,i,name); break;
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
   printf ("Your total is: %d $ ", money);
   printf ("Amount of money you want to withdraw: ");
   scanf ("%d", &withdraw);
   money=money-withdraw;
   FILE *fp2;
   i=(i*120)-sizeof(int);

    if((fp2=fopen("fitness","rb+"))==NULL)
        printf("cant open");


      fseek(fp2,i,SEEK_SET);
      if(fwrite(&money,sizeof (int),1,fp2)!=1)
                    printf("error");

    else printf ("Sucsessfully transfered you have now %d", money);
    fclose(fp2);


}

void transfer(int money,int count, char myName[50])
{
    struct account user;
    FILE *fp1;
    int i=4;
    int person=1;
    int choice;
    int moneyToTransfer;
    int moneyToGive;

    if((fp1=fopen("fitness","rb+"))==NULL)
    {
        printf("the file cant open\n");
        exit(1);
    }

    while (fseek(fp1,i,SEEK_SET)== NULL)
    {

     if (fread(user.name,1,50,fp1)!=50)
     {
         break;
     }
     printf ("(%d) : %s\n", person,user.name);
     i=i+120;
     person++;
    }

    printf ("Select the person you want to transfer the money: \n\n");
    scanf ("%d",&choice);
    printf ("Select the amount of money you want to transfer");
    scanf ("%d", &moneyToTransfer);
    money=money-moneyToTransfer;


    if (fseek(fp1,(count*120)-4,SEEK_SET)== NULL)
    {
       if (fwrite(&money,sizeof(int),1,fp1)!= 1)
        printf ("error");

    }

    if (fseek(fp1,(choice*120)-4,SEEK_SET)== NULL)
    {
       if (fread(&moneyToGive,sizeof(int),1,fp1)!= 1)
        printf ("error");
        moneyToGive=moneyToGive+moneyToTransfer;
    }

    if (fseek(fp1,(choice*120)-4,SEEK_SET)== NULL)
    {
       if (fwrite(&moneyToGive,sizeof(int),1,fp1)!= 1)
        printf ("error");
    }



    fclose(fp1);


}
void information()
{
   FILE *fp;
    struct account user;
    if((fp=fopen("fitness","rb"))==NULL)
    {
        printf("the file cant open\n");
        menu();
    }


    for(;;)
    {

        if(fread(&user.lenght,sizeof(int),1,fp)!=1)
        {
            printf("readung 1 error");
            exit(1);
            menu();
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

