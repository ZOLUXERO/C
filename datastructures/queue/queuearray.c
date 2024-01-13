#include<stdio.h>
#include<stdbool.h>

#define QUEUE_SIZE 4
int A[QUEUE_SIZE];
int front = -1;
int rear = -1;

bool isempty()
{
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
        return true;
    }
    return false;
}

bool isfull()
{
    if ((rear + 1) % QUEUE_SIZE == front) {
        printf("Queue is full\n");
        return true;
    }
    return false;    
}

void enqueue(int n)
{
    if (isfull())
        return; 
    
    if (isempty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % QUEUE_SIZE;
    }
    A[rear] = n;
}

int dequeue()
{
    if (isempty())
        return;
    
    int holdvalue = A[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % QUEUE_SIZE;
    }
    return holdvalue;
}

int first()
{
    if (isempty())
        return;

    return A[front];
}

int main()
{
    enqueue(1);
    enqueue(4);
    enqueue(2);
    enqueue(7);
    printf("Value at the front of the Queue is: %d\n", first());
    dequeue();
    printf("Value at the front of the Queue is: %d\n", first());
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    enqueue(3);
    enqueue(7);
    enqueue(8);
    enqueue(6);
    printf("Value at the front of the Queue is: %d\n", first());
    dequeue();
    enqueue(4);
    enqueue(9);
    printf("Value at the front of the Queue is: %d\n", first());
}