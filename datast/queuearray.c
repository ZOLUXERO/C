#include<stdlib.h>
#include<stdio.h>

#define MAX_SIZE 3
char *queue[MAX_SIZE];
int current_size = 0;
int head, tail = 0;

/**
 * To know the next value use (i + 1) mod (array_size)
 * To know the previous value use (i + array_size - 1) mod (array_size)
*/

void enqueue(char *data) {
    if(current_size == MAX_SIZE) {
        printf("Queue is full for %s\n", data);
        return;
    }
    
    if(current_size > 0) {
        tail = (tail + 1) % MAX_SIZE;
    }
    queue[tail] = data;
    current_size++;
}

void dequeue() {
    if(current_size == 0)
        return;

    printf("dequeueing: %s \n", queue[head]);
    head = (head + 1) % MAX_SIZE;
    current_size--;
}

void printqueue() {
    for (int i = 0; i < current_size; i++) {
        printf("%s ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue("ahhh");
    enqueue("hola");
    enqueue("otro");
    enqueue("mundo"); // this one should fail to enqueue
    printqueue();
    dequeue();
    enqueue("mundo");
    enqueue("ahhh"); // this one should fail to enqueue
    printqueue();
    dequeue();
    enqueue("ahhh");
    printqueue();
}