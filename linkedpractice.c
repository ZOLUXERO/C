#include<stdio.h>
#include<stdlib.h>


struct Node
{
    int data;
    struct Node* next;
};

struct Node* insertnth(struct Node* head, int value)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->next = head;
    temp->data = value;
    head = temp;
    return head; 
}

struct Node* print(struct Node* head)
{
    if (head->next == NULL)
    {
        printf("%d ", head->data);
        return head;
    }
    print(head->next);
    printf("%d ", head->data);
}

int main()
{
    struct Node* head = NULL;
    head = insertnth(head, 1);
    head = insertnth(head, 2);
    head = insertnth(head, 3);
    head = insertnth(head, 4);
    print(head);
    printf("\n");
}