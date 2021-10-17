#include <iostream>

using namespace std;
int const maxsize = 3001;
int main()
{
// Purva zadacha

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
        cout << arr[i] <<" " << endl ;


    }


/*
// Vtora zadacha
    int N;
    cin >> N;
    int i,k=1;

    while (k <= N)
    {
        for(i=0; i < k; i++)
            cout <<" " ;
        for(i=k; i <= N; i++)
            cout <<i;
        for(i=N; i >= k; i--)
            cout <<i;
    k++;
    cout<<endl;
    }
    */

// Treta zadacha
/*

    int n,k=0;
    cin>> n;
    for(int i=1; i<=n; i++)
    {
        for(int a=i; a%5==0; a=a/5)
        {
            k++;
        }
    }
    cout <<k;

*/


    return 0;
}
