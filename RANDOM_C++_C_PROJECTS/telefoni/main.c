#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct user
{
char name[10];
char lastname[10];
int number;
int adress;

};
void addcontact();
int main()
{

search();

}
void addcontact()
{
    FILE * f;
    char fileName[10];

    struct user p;
    printf ("Name: ");
    gets(p.name);
    printf ("Lastname: ");
    gets(p.lastname);
    printf ("number: ");
    strcpy(fileName,p.name);
    strcat(fileName,".txt");
    scanf ("%d", &p.number);
    f=fopen(fileName,"w");
    fprintf (f,"%s\n%s\n%d\n", p.name,p.lastname,p.number);
    fclose(f);

}
void modify()
{

}
void search()
{
    char name[10];
    char line[250];
    FILE * f;


    printf ("Name of the contact: ");
    gets(name);
    strcat(name,".txt");
    f=fopen(name, "r");
    if(f== NULL)
    {
        printf ("Not found");
        exit(1);
    }

    fgets(line,250,f);
    printf ("Name: %s", line);
    fgets(line,250,f);
    printf ("Last Name: %s", line);
    fgets(line,250,f);
    printf ("Number: %s", line);

    fclose(f);



}
void choice()
{
    int x;
    scanf ("%d", &x);
    switch(x)
    {
        case 1: addcontact(); break;
        case 2: search(); break;
    }
}
