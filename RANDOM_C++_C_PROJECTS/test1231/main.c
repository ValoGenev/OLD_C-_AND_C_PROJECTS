#include <stdio.h>

int main()
{
int a=0;
int b=-333;
int i;
i=0;
for (a=0; a>=b; a--)
{
    if(a%2!=0)
    i++;


}
printf ("%d", i);

return 0;
}
