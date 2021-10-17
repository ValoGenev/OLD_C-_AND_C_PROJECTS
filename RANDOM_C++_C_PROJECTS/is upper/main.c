#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main()


{
  printf ("Vuvedi parola, koqto sudurja min 1 glavna 5 malki bukvi 2 znaka i 2 cifri");
  printf ("\n\n");
  test();
  getch();
  printf ("\nBRAVO");


  return 0;
}

void test()
{
  char parola[20];
  int digits=0;
  int letter=0;
  int punct=0;
  int upper=0;
  int i=0;

  scanf ("%s", parola);

    while (parola[i])
   {
   if (isdigit(parola[i]))
   ++digits;
   else if (isupper(parola[i]))
   ++upper;
   else if (ispunct(parola[i]))
    ++punct;
   else if (isalpha(parola[i]))
    ++letter ;
   ++i;
  if (digits != 2 || upper != 1 || punct != 2 || letter != 5)
    printf ("Greshno vuvedena parola");
   else
    printf ("Parolata ti e zapametena");
    return 0;
    }
}

