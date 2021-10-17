#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main(void)
{

   int i =1;
   int x=1;
    struct dirent *de;
    char decision[15];
    int lenght;
    char decisionNumber[10];
    int k=5;
    int a=0;
    int b=0;
    char F[3] = "F:";
    char name[100];




   // Pointer for directory entry

    // opendir() returns a pointer of DIR type.
    DIR *dr = opendir("F:World of Warcraft Wrath of the Lich King 3.3.5 enUS/");

    if (dr == NULL)  // opendir returns NULL if couldn't open directory
    {
        printf("Could not open current directory" );
        return 0;
    }


    while ((de = readdir(dr)) != NULL)
    {
        printf("%d - %s\n", i ,de->d_name);
        i++;
    }
    name[100]=de->d_name;
    printf ("%s", name[100]);
   /* printf ("\n\n");

    closedir(dr);
    while (x!=0)
    {
       printf ("Exit\n");
       printf ("Open (folder number)\n");
       printf ("Delete (folder number)\n");
       gets(decision);
       if(strncmp(decision,"Exit", 4)== 0) exit(1);
       if (strncmp(decision,"Open", 4)==0)
       {
         scanf ("%d", &a);
         struct dirent *de;
         DIR *dr = opendir("F:");
         if (dr == NULL)  // opendir returns NULL if couldn't open directory
    {
        printf("Could not open current directory" );
        return 0;
    }

    while (i=0 < a);
    {
        de = readdir(dr);

        i++;
    }

       name[100]=de->d_name;




       }

    }*/
   closedir(dr);

    return 0;
}
