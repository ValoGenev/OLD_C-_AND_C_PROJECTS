#include <stdio.h>
#include <stdlib.h>
int subirane(int *pa,int *pb);
int main()
{
  int str[50];
  int i;
  int n;



  printf ("Input number of elements: ");
  scanf ("%d", &n);
  for (i=0;i<n;i++)
  {
      printf ("\nInput number %d: ", i);
      scanf ("%d", str + i);
  }

  for (i=0;i<n;i++)
  {
      printf ("\nNumber %d is : %d",i,str[i]);
  }
    return 0;
}

