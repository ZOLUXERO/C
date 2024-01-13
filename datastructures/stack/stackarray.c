#include<stdio.h>
#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;

void push(int value)
{
    if (top == MAX_SIZE -1)
    {
        printf("Error: Stackoverflow");
        return;
    }
    top++;
    A[top] = value;
}

void pop()
{
    if (top == -1)
    {
        printf("Error: stack is empty");
        return;
    }
    top--; 
}

void print()
{
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main()
{
    push(1);
    print();
    push(2);
    print();
    push(4);
    print();
    push(6);
    print();
    push(5);
    print();
    pop();
    print();
}