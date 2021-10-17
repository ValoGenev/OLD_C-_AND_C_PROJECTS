#include <stdio.h>
#include <stdlib.h>

struct item
{
    char *name;
    int price;

};


int main()
{
 struct item itm;
 struct item *pItem;
 pItem=&itm;
 pItem->name = (char *) malloc(30 * sizeof(char));
 input(pItem);
 output(pItem);


}

void input(struct item * i)
{
    printf ("Enter name: ");
    scanf ("%s", i->name);
    printf ("Enter price: ");
    scanf ("%d", &i->price);

}
void output(struct item *i)
{
    printf ("Name entered: %s", i->name);
    printf ("\nPrice entered: %d", i->price);
}
