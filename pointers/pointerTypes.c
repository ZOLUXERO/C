#include<stdio.h>
#include<string.h>

int main()
{
    int a = 1025;
    int *p;
    p = &a;
    char string[] = "quiero saber el valor de este string";
    int sizestring = sizeof(string) / sizeof(char);
    printf("size of integer is %d bytes\n", sizeof(int));
    printf("Address = %d, value = %d\n", p, *p); // *p desreferencia el apuntador para traer el valor de donde esta apuntando
    printf("Address = %d, value = %d\n", p+1, *(p+1)); // pointer aritmethic
    char *p0;
    p0 = (char*)p; // typecasting cambiar el valor de una variable
    printf("size of char is %d bytes\n", sizeof(char));
    printf("Address = %d, value = %d\n", p0, *p0);
    printf("Address = %d, value = %d\n", p0+1, *(p0+1));
    printf("Size of string: %d\n", sizestring);
    printf("Size of string strlen: %d\n", strlen(string));
    // 1025 = 00000000 00000000 00000100 00000001

    // Void pointer - Generic pointer
    void *p1;
    p1 = p;
    printf("Address = %d\n", p1); // void pointers no permiten desreferenciacion ni aritmetica

}