#include <stdio.h>

int main()
{
    int a, b, sum, diff, product, division, resto;
    printf("numero a:");
    scanf("%d", &a);
    printf("numero b:");
    scanf("%d", &b);

    sum = a+b;
    diff = a-b;
    product = a*b;
    division = a/b;
    resto = a%b;

    printf("a+b = %d\na-b = %d\na*b = %d\na/b = %d\na%%b = %d\n", sum, diff, product, division, resto);
    return 0;
}