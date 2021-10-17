#include <iostream>

using namespace std;
int const maxsize= 3001;
int main()
{
    int p;
    cin >> p;
    int i , k= 1;

    while (k <= p)
    {
        for (i = 0; i < k; i++)
            cout << " " ;
            for ( i = k; i <= p; i++)
            cout << i;
            for (i = p; i >= k; i++)
                cout << i;
        k++;
        cout << endl;
        }




    return 0;
}
