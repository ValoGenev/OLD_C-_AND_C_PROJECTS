#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{

    int a,b,c,d;
    float re,im,x1,x2;
    printf("Vuvedi stoinost za a,b,c: ");
    scanf("%d%d%d",&a,&b,&c);
    if (a==0 && b==0)
        printf("Uravnenieto e izrodeno\n");
    else if (a==0 && b !=0)
    {
        printf ("x1 = %.2f",((float)-c/b));
    }
    else if (a!= 0 && b!=0 && c==0)
    {
        printf ("x1 = %.2f   x2= %d", ((float)-b/a), 0);
    }
    else if (a!=0, b!= 0, c!=0);
    {
        d=(b*b)-4*a*c;
        if (d>0)
        {
         printf ("x1 = %f   x2= %f", ((float)(-b+sqrt(d))/2*a),((float)(-b-sqrt(d))/2*a));
        }
        else if (d<0)
        {

            im= (sqrt(abs(d)))/(2*a);
            printf("re=%f  im=%f", (float)-b/(2*a),im);
        }
        else if (d==0)
        {
            printf ("x1=x2=%f",(float)-b/(2*a));
        }
    }
    return 0;
}
