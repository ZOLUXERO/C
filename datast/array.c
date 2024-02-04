#include<stdlib.h>

int main() {
    char A[10];
    A[0] = 'H';
    A[1] = 'O';
    A[2] = 'L';
    A[3] = 'A';
    A[4] = ' ';
    A[5] = 'M';
    A[6] = 'U';
    A[7] = 'N';
    A[8] = 'D';
    A[9] = 'O';

    int arrsize = sizeof(A) / sizeof(char);
    for (int i = 0; i < arrsize; i++) {
        printf("%c", A[i]);
    }
    
}