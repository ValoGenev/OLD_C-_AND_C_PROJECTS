#include <iostream>

using namespace std;

int main()
{
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


    }
