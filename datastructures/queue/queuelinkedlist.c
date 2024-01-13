#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define MAX_QUEUE_SIZE 4

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;
int current_queue_size = 0;

bool isempty()
{
    if(head == NULL && tail == NULL) {
        printf("Queue is empty\n");
        return true;
    }
    return false;
}

bool isfull()
{
    if(current_queue_size == MAX_QUEUE_SIZE) {
        printf("Queue is full\n");
        return true;
    }
    return false;
}

void enqueue(int n)
{
    if(isfull()) return;
    
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->data = n;
    temp->next = NULL;
    if (isempty()) {
        head = tail = temp;
        current_queue_size++;
        return;
    }
    tail->next = temp;
    tail = temp;
    current_queue_size++;
}

int dequeue()
{
    if(isempty()) return;

    struct Node *temp = head;
    int node_value = temp->data;
    head = temp->next;
    free(temp);
    current_queue_size--;
    return node_value;
}

int first()
{
    if(isempty()) return;
    return head->data;
}

int last()
{
    if(isempty()) return;
    return tail->data;
}

int main()
{
    enqueue(1);
    enqueue(4);
    enqueue(2);
    enqueue(8);
    printf("First value of queue is: %d\n", first());
    printf("Last value of queue is: %d\n", last());
    dequeue();
    dequeue();
    enqueue(7);
    enqueue(9);
    enqueue(3);
    printf("First value of queue is: %d\n", first());
    printf("Last value of queue is: %d\n", last());
}