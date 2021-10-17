#include <stdio.h>
#include <stdlib.h>
#define MONTHS 12
#define YEARS 5
int multiplyTwoNumbers  (int x, int y)
{
    int result= x*y;
    return result;

}
int main()
{
    int result;
    int x,y;
    scanf("%d", &x);
    scanf("%d", &y);
    result= multiplyTwoNumbers(x,y);
    printf ("result is %d\n", multiplyTwoNumbers(result));

    return 0;

}
