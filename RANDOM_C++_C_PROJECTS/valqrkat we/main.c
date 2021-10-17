#include <stdio.h>
#include <stdlib.h>

int main()
{

    int temp[4];
    int temp2[4];
    int sum=0;
    int sum1=0;
    int MAT[4][4]  = {
      {1,3,4,5},
      {2,6,13,2},
      {4,16,3,2},
      {1,5,3,5}};






    for(int i=0;i<4;i++) {


      for(int j=0;j<4;j++){

        sum+=MAT[j][i];
        temp[j]=MAT[j][i];

      }



      for(int k=1;k<4;k++){

            for(int p=0;p<4;p++){

               sum1+=MAT[p][k];
               temp2[p]=MAT[p][k];

           }

           if(sum<sum1){

            for(int u=0;u<4;u++){


                MAT[u][i]=temp2[u];

                MAT[u][k]=temp[u];

            }
           sum1=0;
      }

      sum=0;

      i++;

      }


      }





       for(int y=0;y<4;y++){
        for(int z=0;z<4;z++)
            printf ("%d ", MAT[y][z]);
        printf ("\n");
      }



}
