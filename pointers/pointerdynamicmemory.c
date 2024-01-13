#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a; // esta variable va al stack de la memoria
    int *p;
    p = (int*)malloc(sizeof(int)); // malloc reserva un pedazo de memoria en el heap, malloc retorna un puntero al heap
    *p = 10;
    printf("malloc %d\n", *p);
    free(p); // con esto limpiamos el pedazo de memoria que malloc asigno dinamicamente
    p = (int*) malloc(sizeof(int)); // se hace typecast por que malloc retorna tipo void
    *p = 20;
    printf("malloc %d\n", *p);


    /**
     * si quiero utilizar malloc para alocar un array
    */
    free(p);
    p = (int*)malloc(20*sizeof(int)); // para utilizarlo se puede hacer con p[0], p[1], p[2] ...
}