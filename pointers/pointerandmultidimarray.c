#include<stdio.h>

int multiDim(int (*B)[3][2]) // cuando es un array multidimensional el parametro debe ser *(B) + la cantidad de [] anidados
{
    printf("multiDim %d\n", B);
    printf("multiDim %d\n", B[0][0][1]); // esto es igual a *(*(*(B)+1)) = 2
    printf("multiDim %d\n", *(*(*(B))+1)); // esto es igual a B[0][0][1] = 2
    printf("multiDim %d\n", *(*(*(B+2)+1)+1)); // esto es igual a B[2][1][1] = 16
    printf("multiDim %d\n", &B[2][1][1]); // esto es igual a *(*(B+2)+1)+1 que es la direccion de 16
    printf("multiDim %d\n", *(*(B+2)+1)+1); // esto es igual a &B[2][1][1] que es la direccion de 16
}

int main()
{
    int A[3][3][2] = {
            {
                {{1},{2}},
                {{3},{4}},
                {{5},{6}}
            },
            {
                {{7},{8}},
                {{9},{10}},
                {{11},{12}}
            },
            {
                {{13},{14}},
                {{15},{16}},
                {{17},{18}}
            }
        };

    printf("primer direccion de A = %d\n", A);
    printf("primer direccion de A = %d\n", A[0][0][1]);
    multiDim(A);
}