#include <stdio.h>

int main()
{
    int a, b, c;

    // %d -> int
    // %f -> float
    // %c -> char
    printf("numero a: ");

    // el & le dice a scanf la direccion en memoria de la variable a
    scanf("%d", &a);
    printf("numero b: ");
    scanf("%d", &b);
    c = a*b;
    printf("a = %d, b = %d, a*b = %d\n", a, b, c);
    return 0;
}