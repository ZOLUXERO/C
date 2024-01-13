#include<stdio.h>
#include<stdlib.h>

/**
 * malloc - void* malloc(size_t size):
 * reserva memoria dependiendo del parametro size donde size es el tama;o de memoria que
 * desea reservar en bytes, retorna void pointer
 * 
 * calloc - void* calloc(size_t num, size_t size):
 * reserva memoria segun la cantidad de elementos que necesite reservar(num) y el tama;o 
 * de cada elemento(size), calloc por defecto inicializa todas las posiciones que reserva
 * con 0
 * 
 * realloc - void* realloc(void* ptr, size_t size):
 * esta funcion toma dos argumentos donde ptr es el puntero a la direccion inicial del bloque
 * que se desea cambiar y el segundo size es el tama;o que se le va a asignar al nuevo bloque
*/
int main()
{
    int n;
    printf("Enter size of array\n");
    scanf("%d", &n);
    // int A[n]; no sirve por que cuando se usa de esta forma no se puede saber el tama;o del array durante run time o tiempo de ejecucion

    int *A = (int*)malloc(n*sizeof(int)); // array asignado dinamicamente, parece que malloc tambien inicializa los valores como 0 no deberia?
    for (int i = 0; i < n; i++) {
        A[i] = i + 1;
    }
    printf("A: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    free(A);
    printf("free: "); // aca es peligroso volver a usar A por que lo limpiamos y no sabemos que hay en ese pedazo de memoria
    // A = NULL; cuando se limpia la memoria el apuntador se deberia ajustar a NULL para evitar comportamientos indeseados
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    A = (int*)calloc(n, sizeof(int)); // esto hace lo mismo que malloc pero ahora inicializa los valores como 0
    printf("A: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    int *B = (int*)realloc(A, 2*n*sizeof(int)); // extiende el bloque anterior de A * 2 y lo asigna a B
    printf("Prev block address = %d, new address = %d\n", A, B);
    int *A = (int*)realloc(A, 0); // esto es equivalente a free(A)
    int *C = (int*)realloc(NULL, n*sizeof(int)); // esto es equivalente a llamar un malloc
    for (int i = 0; i < 2*n; i++) {
        printf("%d\n", B[i]);
    }
}
