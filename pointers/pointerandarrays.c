#include<stdio.h>

int main()
{
    int A[] = {2, 4, 5, 8, 1};
    printf("%d\n", A);
    printf("%d\n", &A[0]);
    printf("%d\n", A[0]);
    printf("%d\n", *A);
    int *p = A;
    // A++; // Invalido
    p++; // valido

    for(int i = 0; i < 5; i++) {
        printf("Address &A[%d] = %d ", i, &A[i]);
        printf("value = %d\n", A[i]);
        printf("Address A+%d = %d ", i, A+i);
        printf("value = %d\n", *(A+i));
    }
}