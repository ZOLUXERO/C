#include<stdio.h>

void print(char *c)
{
    int i = 0;
    while(c[i] != '\0') { // c[i] es lo mismo *(c+i)
        printf("%c", c[i]);
        i++;
    }
    printf("\n");

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
    char c[5];
    c[0] = 'J';
    c[1] = 'O';
    c[2] = 'H';
    c[3] = 'N';
    c[4] = '\0';
    char ch[] = "JOHN"; // string literal, cuando se usa un string literal la terminacion del string "\0" es implicita
    printf("Size in bytes = %d\n", sizeof(ch));
    int len = strlen(c);
    printf("%s\n", c);
    printf("length %d\n", len);

    print(ch);
}