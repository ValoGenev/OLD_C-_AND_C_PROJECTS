#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int a;
  int brr[100];
  int arr[100] = {1,2,3,4,5,6,7,8,9,10};
  for (int i=0; i<10; i++)
  {
      arr[i]= rand() % 11;
    if(arr[i]==0 || arr[i]==a)
      {
          arr[i]= rand() % 11;
      }




      printf ("%d\n", arr[i]);
      a=arr[i];


  }
}




