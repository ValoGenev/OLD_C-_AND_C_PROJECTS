#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{

 FILE *f;
 int mn;
 f=fopen("gei.txt","r");

 mn=max(f);
 printf ("%d", mn);

}

int max(FILE *inp)
{
 int next,maxneg=0;
 for(;fscanf(inp,"%d",&next)!= EOF;){
 if(next <0){
 if(!maxneg) maxneg=next;
 else if(maxneg<next) maxneg=next;
 }
 }
 return maxneg;
}
