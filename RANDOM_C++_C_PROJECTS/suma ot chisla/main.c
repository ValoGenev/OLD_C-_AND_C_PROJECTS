#include <stdio.h>
int main()
{
int a,b,i;
int sum;
printf("Vyvedi a: ");
scanf("%d", &a);
printf("Vyvedi b: ");
scanf("%d", &b);
sum=0;
i=a;
while(i<=b)
{
sum+=i;
i++;
}
printf("Sumata mejdu %d i %d = %d\n", a, b, sum);
return 0;
}
