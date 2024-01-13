#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int comparar(int a, int b)
{
    if(a > b) {
        return 1;
    } else {
        return -1;
    }
}

int comparar_valor_absoluto(int a, int b)
{
    if (abs(a) > abs(b))
    {
        return 1;
    } else {
        return -1;
    }
}

int compare_qsort(const void *a, const void *b) // para poder pasar esta funcion a qsort debe recibir valores tipo void ya que qsort es una funcion generica
{
    int A = *((int*)a); // se hace typecast para convertir el valor 
    int B = *((int*)b);
    return A-B;
}

void BubbleSort(int A[], int n, int (*comparar)(int, int)) // (*comparar)(int, int) es un puntero a la funcion para ser usada como callback
{
    int temp;
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n-1; j++) {
            if(comparar(A[j], A[j+1]) > 0) {
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

int main()
{
    // int A[] = {3, 2, 1, 5, 6, 4};
    int A[] = {3, 2, 1, 5, 6, 4, -10};
    int size = sizeof(A)/4;
    BubbleSort(A, size, comparar); // se pasa la direccion de la funcion comparar
    for (int c = 0; c < size; c++) {
        printf("%d ", A[c]);
    }
    printf("\n");

    BubbleSort(A, size, comparar_valor_absoluto); // se pasa la direccion de la funcion comparar
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    qsort(A, size, sizeof(int), compare_qsort); // con qsort se puede sortear cualquier tipo de array string, entero etc. Lo unico que se debe hacer es darle la logica de comparacion
    for (int j = 0; j < size; j++) {
        printf("%d ", A[j]);
    }
    printf("\n");
    
}