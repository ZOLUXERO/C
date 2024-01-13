#include<stdio.h>

int main()
{
    int a = 10;
    int *p; // pointer
    p = &a; // tomar address de a
    printf("Address p is %d\n", p); // address
    printf("Valule at address p is %d\n", *p); // value in address
    printf("Addres a is %d\n", &a); // address
    *p = 12;
    printf("Value of a is %d\n", a); // address

    printf("size of integer is %d bytes\n", sizeof(int));
    printf("size of char is %d bytes\n", sizeof(char));
    printf("size of float is %d bytes\n", sizeof(float));

    // pointer arithmetic
    printf("Address of p+1 is %d\n", p+1);
    printf("Value of p+1 is %d\n", *(p+1));
    printf("Addres of p is %d\n", &p);
}