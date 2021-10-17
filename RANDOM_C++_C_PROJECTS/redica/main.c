#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x[5]= {1,5,16,3,-5};

    int temp;
    for(int i=0;i<=5;i++)
    {
        for(int j=i+1;j<=5;j++)
        {
            if(x[i] > x[j])
            {
                temp=x[i];
                x[i]=x[j];
                x[j]=temp;

            }

        }



    }
    for(int i=0;i<5;i++)
    {
        printf ("%d\n", x[i]);

    }

    return 0;
}
