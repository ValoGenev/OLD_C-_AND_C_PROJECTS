#include <stdio.h>
#include <stdlib.h>
int test(int a, int b);
int main()
{
    int a;
    int b;
    int result;
    printf ("Vuvedi stoinost za a i b");
    scanf ("%d %d", &a,&b);
    result = test(a,b);
    printf ("%d", result);



}
int test(int a, int b)
{
    char result;

    if (a>b)
    result= 1;
    return result;

}
