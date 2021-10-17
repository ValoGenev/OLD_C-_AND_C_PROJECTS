#include <stdio.h>
#include <stdlib.h>

void townDistanseFill(int r, int c, int townDistanse[r][c]);
void arrDisplay(int r, int c, int townDistanse[r][c]);
void pathCalc(int townDistanse[5][5], int n, int r, int c);


int main(){

int row = 5;
int colomn = 5;
int townDistanse [row][colomn];
int len;


townDistanseFill(row, colomn, townDistanse);
arrDisplay(row, colomn, townDistanse);
pathCalc(townDistanse, len, row, colomn);

return 0;
}
//filling the matrix with town distanses
void townDistanseFill(int r, int c, int townDistanse[r][c]){
  int i, j;
  printf("Enter the distance in kilometers from one town to other");
  for(i=0; i<r; i++){
        for(j=0; j<c; j++){
        //filling just one of the diagonal sides for an easy use later
          if(i>j){
             townDistanse[i][j] = 0;
                continue;
                }
             scanf("%d \n",&townDistanse[i][j]);
             //making the distances between same city 0
             if(i == j){
                townDistanse[i][j] = 0;
                }
            }
        }
        printf("\n");
}

//output the matrix on the screen
void arrDisplay(int r, int c, int townDistanse[r][c]){
   int i, j;
   printf("\nDistanses :\n \n");
   for(i=0; i<r; i++){
       for(j=0; j<c; j++){
           printf("%d \t", townDistanse[i][j]);
           if(j == 5-1){
               printf("\n");
               printf("\n");
           }
    }
}
   printf("\n");
}

//Summing the path that the users input
void pathCalc(int townDistanse[5][5], int n, int r, int c){
int i;
int sum = 0;

for(i=0; i<n; i++){
         printf("Enter row cordinate :\n");
         scanf("%d", &r);
        //verificating is the user input wrong field(row field)
              if(r<0 || r>4){
                 printf("Invalid input\n");
                 pathCalc(townDistanse, n, r, c);
      }
       printf("Enter colomn cordinate :\n");
       scanf("%d", &c);
       //verificating is the user input wrong field(colom field)
            if(c<0 || c>4){
              printf("Invalid input\n");
              pathCalc(townDistanse, n, r, c);
              }
        //verificating is the inputed path is aveilable
              else if(townDistanse[r][c] == 0){
                          sum += townDistanse[r][c];
                               printf("There is no aveilable path for those cordinates so you cant go trough");
                               printf("You have traveled %d kilometers.", sum);
                               exit(0);

              }
                          sum += townDistanse[r][c];
      }
          printf("All path distance is :%d\n", sum);
          exit(0);
}
