#include<stdio.h>

void print(char *c)
{
    // c[0] = "A"; esto no sirve por que se esta asignando un string literal(sequencia de caracteres) a un solo elemento
    c[0] = 'A'; // aca se asigna correctamente un solo caracter al primer elemento
    while (*c != '\0') { // desreferenciacion y aumenta apuntador +1
        printf("%c", *c);
        c++;
    }
    printf("\n");
}

void println(const char *c) // si lo que se quiere es solo leer y no modificar
{
    while (*c != '\0') { // desreferenciacion y aumenta apuntador +1
        printf("%c", *c);
        c++;
    }
    printf("\n");
}

int main()
{
    // El tama;o de un string en c es char lentgth + 1 en este ejemplo "JHON" es un string de 4 bytes pero 
    // para que el programa sepa que el string termina en "N" le agrega un null "\0" para que sepa que es
    // el final del string
    char ch[] = "HELLO"; // string literal(sequencia de caracteres), cuando se usa un string literal la terminacion del string "\0" es implicita
    char *c = "HELLO"; // Este codigo queda guardado en memoria en la parte de code(text) de la memoria como una constante por lo que no se puede modificar
    print(ch);
    println(c);
}