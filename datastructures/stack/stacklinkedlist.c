#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next; 
};

struct Node* push(struct Node* head, int value)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->next = head;
    temp->data = value;
    head = temp;
    return head;
}

struct Node* pop(struct Node* head)
{
    if (head == NULL) return;
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

void print(struct Node* head)
{
    if (head->next == NULL)
    {
        printf("%d ", head->data);
        return;
    }
    print(head->next);
    printf("%d ", head->data);
}

int main()
{
    struct Node* head = NULL;
    head = push(head, 2);
    print(head);
    printf("\n");
    head = push(head, 1);
    print(head);
    printf("\n");
    head = push(head, 4);
    print(head);
    printf("\n");
    head = push(head, 7);
    print(head);
    printf("\n");
    head = push(head, 5);
    print(head);
    printf("\n");
    head = pop(head);
    print(head);
    printf("\n");
}