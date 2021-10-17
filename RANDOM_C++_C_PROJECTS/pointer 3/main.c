#include <stdio.h>
#include <string.h>

void vuvejdane(int *str1, int *n);
void izvejdane (int *str1, int *n);
void vuzhodqsht(int *str1, int *n);


int main()
{
  int str[50];
  int n;
  char c;
  printf ("Kolko dumi shte sortirash: " );
  scanf ("%d", &n);
  vuvejdane(str, &n);
  izvejdane (str, &n);
  printf ("Sortirane po vuzhodsqt(1) i Sortirane po nishodqsht(2) : ");
  scanf ("%d", &c);
  switch (c)
  {
      case 1 : vuzhodqsht(str, &n); break;
      case 2 : nishodqhst(str, &n); break;
      default : printf ("Nevaliden operator"); break;

  }


}

void vuvejdane (int *str1 , int *n)
{
  int i;
  for (i=0;i<*n;i++)
  {
      printf ("Vuvedi chislo: ");
      scanf ("%d", str1+i);
  }

}

void izvejdane (int *str1, int *n)
{

    for (int i=0;i<*n;i++)
  {
      printf ("%d\n", *(str1+i));
  }

}

void vuzhodqsht(int *str1, int *n)


{
    int temp;
    int j=0;
   for(int i=0;i<*n;i++)
   {
       for (j=i+1; j<*n;j++)
       {
           if (*(str1+i) > *(str1+j))
           {
               temp=*(str1+i);
               *(str1+i)=*(str1+j);
               *(str1+j)=temp;
           }
       }

   }
   printf ("Elementite sled sortirane : ");
   for (int i=0;i<*n;i++)
   {
       printf (" %d ", *(str1+i));

   }


}


void nishodqhst(int *str1, int *n)


{
    int temp;
    int j=0;
   for(int i=0;i<*n;i++)
   {
       for (j=i+1; j<*n;j++)
       {
           if (*(str1+i) < *(str1+j))
           {
               temp=*(str1+i);
               *(str1+i)=*(str1+j);
               *(str1+j)=temp;
           }
       }

   }
   printf ("Elements after sorting are: ");
   for (int i=0;i<*n;i++)
   {
       printf (" %d ", *(str1+i));

   }


}













