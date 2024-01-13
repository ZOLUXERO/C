#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct DoubleNode
{
    int data;
    struct DoubleNode *next;
    struct DoubleNode *prev;
};


// struct Node* push()
// {

// }

// struct Node* pop()
// {

// }

struct DoubleNode* dobuleLinkedList(struct DoubleNode *head, int value, int position)
{
    struct DoubleNode *temp = (struct DoubleNode*)malloc(sizeof(struct DoubleNode*));
    temp->data = value;
    temp->next = head;
    if (position == 1) {
        temp->prev = NULL;
        head = temp;
        return head;
    }

    temp->prev = head;
    for (int i = 0; i < position-2; i++) {
        temp->prev = temp->prev->next;
    }
    temp->next = temp->prev->next;
    temp->prev->next = temp;
    if(temp->next == NULL) return head;
    temp->next->prev = temp;
    return head;
}

struct Node* reverse(struct Node *ptr)
{
    if(ptr->next == NULL) {
        return ptr;
    }
    struct Node *lastElement = reverse(ptr->next); 
    struct Node *q = ptr->next;
    q->next = ptr;
    ptr->next = NULL;
    return lastElement;
}

struct Node* insertnth(struct Node *head, int value, int position)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->data = value;
    if(position == 1) {
        temp->next = head;
        head = temp;
        return head;
    }

    struct Node *temp2 = head;
    for (int i = 0; i < position-2; i++) {
        temp2 = temp2->next; 
    }
    temp->next = temp2->next;
    temp2->next = temp;
    return head;
} 

struct Node* insertFirst(struct Node *head, int value)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->next = head;
    temp->data = value;
    head = temp;
    return head;
}

void print(struct Node *ptr)
{
    if (ptr == NULL) {
        return;
    }
    printf("%d ", ptr->data); 
    print(ptr->next);

}

int main()
{
    struct Node *head = NULL;
    head = insertFirst(head, 1);
    head = insertFirst(head, 2);
    head = insertFirst(head, 3);
    print(head);
    printf("\n");
    head = reverse(head);
    print(head);
    printf("\n");

    free(head);
    head = NULL;
    head = insertnth(head, 4, 1);
    print(head);
    printf("\n");
    head = insertnth(head, 7, 2);
    print(head);
    printf("\n");
    head = insertnth(head, 3, 3);
    print(head);
    printf("\n");
    head = reverse(head);
    print(head);
    printf("\n");

    struct DoubleNode *head2 = NULL;
    head2 = dobuleLinkedList(head2, 4, 1);
    head2 = dobuleLinkedList(head2, 3, 2);
    head2 = dobuleLinkedList(head2, 5, 3);
    print(head2);
    printf("\n");
}