#include<stdio.h>

void IncrementByValue(int a) // call by value
{
    a = a + 1;
}

/**
 * Si se usa call by reference se puede ahorrar un buen pedazo
 * de memoria por que en vez de crear una copia de un data-type
 * largo y complejo se crea una referencia a ese data-type que
 * ingual va a gastar memoria pero no va a ser tanta como crear 
 * una copia.
*/
void Increment(int *p) // call by reference
{
    *p = (*p) + 1;
}

int main()
{
    int a = 10;
    IncrementByValue(a);
    printf("a = %d\n", a);
    Increment(&a);
    printf("a = %d\n", a);
}