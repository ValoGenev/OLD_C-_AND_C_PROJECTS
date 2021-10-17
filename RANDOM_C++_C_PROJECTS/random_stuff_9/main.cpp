#include <iostream>

using namespace std;

int main()
{
    int a=2;
    int arr[maxsize];
    for (int i=0;i<2999;i++)
    {
            arr[i]=a;
            a++;

    }

    for(int i=0;i<2999;i++)
    {
        if(arr[i] !=0)
        {
          for (int k=i+1;k<2999;k++)
          {
            if(arr[k]% arr[i]==0)
            {
                arr[k]=0;
            }

          }
        }
    }

    for(int i=0;i<2999;i++)
    {
        if (arr[i]!=0)
        cout << arr[i] <<" ";
    }
    return 0;
}
