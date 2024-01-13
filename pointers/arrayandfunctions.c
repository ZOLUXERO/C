#include<stdio.h>

/**
 * Array siempre es pasa como referencia cuando es un argumento
 * es lo mismo A[] y *A esto es lo mismo de call by reference
*/
int SumOfElements(int A[], int size)
{
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += A[i];
    }
    return sum;
}

/**
 * Cambia el mismo array A en main con desreferenciacion
*/
void Double(int *A, int size)
{
    for(int i = 0; i < size; i ++) {
        A[i] = A[i] * 2;
    }
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    int size = sizeof(A)/sizeof(A[0]);
    int total = SumOfElements(A, size);
    printf("Sum of elements = %d\n", total);
    Double(A, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", A[i]);
    }
}