#include <iostream>

using namespace std;

int main()
{

   int k,arr[10000],brr[10000],a=0;
    cin >> k;
    for (int i=0;i<k;i++)
    {
        cin>>arr[i];
    }
    for (int j=0;j<=2;j++)
    {
        for(int i=0; i<k; i++)
        {
            if(arr[i]%3==j)
            {
                brr[a]=arr[i];
                a++;
            }
        }
    }

    for (int i=0;i<k;i++)
    {
        cout <<brr[i]<<" ";
    }
    return 0;
}

