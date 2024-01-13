#include<stdio.h>

void printHola(char *texto)
{
    printf("Hola %s\n", texto);
}

int suma(int a, int b)
{
    return a + b;
}

int main()
{
    int (*ptr)(int, int);
    ptr = suma; // esto es igual a decir &suma que es la direccion de la funcion suma
    int c = (*ptr)(2, 4); // esto es igual a ptr(2, 4)
    printf("%d\n", c);

    void (*pt)(char*); // la variable debe ser de el mismo tipo que retorna la funcion con la misma cantidad y tipo de parametros
    pt = printHola; // el nombre de la funcion retorna la direccion de la funcion
    pt("Pepe");
}