#include<stdio.h>

int main()
{
    int A[2][3];
    A[0][0] = 1;
    A[0][1] = 2;
    A[0][2] = 3;
    A[1][0] = 4;
    A[1][1] = 5;
    A[1][2] = 6;
    int (*p)[3] = A;

    printf("Address of A is %d\n", A); // referencia el puntero de A o &A[0]
    printf("Address of *A is %d\n", *A); // referencia el puntero de A[0] o &A[0][0]
    printf("Address of A+1 is %d\n", A+1); // referencia el puntero de A+1 o &A[1]
    printf("Address of *(A+1) is %d\n", *(A+1)); // referencia el puntero de A[1] o &A[1][0]
    printf("Address of *(A+1)+2 is %d\n", *(A+1)+2); // referencia el puntero de A[1]+2 o &A[1][2]
    printf("Address of *(A)+2 is %d\n", *(A)+2); // referencia el puntero de A[0]+2 o &A[0][2]
    printf("=======================================\n");
    printf("value of *(*A)+2 is %d\n", *(*A)+2); // referencia el valor de A[0][2]
    printf("value of *(*A+2) is %d\n", *(*A+2)); // referencia el valor de A[0][2]
    printf("=======================================\n");
    printf("value of *(A[1]+2) is %d\n", *(A[1]+2)); // referencia el valor de A[1][2] o *(*(A+1)+2)
    printf("value of *(*(A+1)+2) is %d\n", *(*(A+1)+2)); // referencia el valor de A[1][2] o *(*(A+1)+2)
    printf("value of *(A[1]) is %d\n", *(A[1])); // referencia el valor de A[1][0]
    printf("=======================================\n");
    printf("Address of A[1]+2 or 6 is %d\n", A[1]+2); // referencia el puntero de A[1][2]
    printf("value of *(A[1])+2 is %d\n", *(A[1])+2); // referencia el valor de A[1][2]
    printf("=======================================\n");

    int B[2][2];
    int C[2][2];

    B[0][0] = 1;
    B[0][1] = 2;
    B[1][0] = 3;
    B[1][1] = 4;
    printf("Address of B is %d\n", B); // referencia el puntero de A o &A[0]
    printf("value of *(*B+2) is %d\n", *(*B)); // referencia el puntero de A[0][2]
    
    C[0][0] = 5;
    C[0][1] = 6;
    C[1][0] = 7;
    C[1][1] = 8;
    printf("Address of C is %d\n", C); // referencia el puntero de A o &A[0]

}