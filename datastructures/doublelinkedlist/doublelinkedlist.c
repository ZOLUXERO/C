#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* insertnth(struct Node* head, int value, int position)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->data = value;
    temp->next = head;
    if(position == 1) {
        temp->prev = NULL;
        head = temp;
        return head;
    }
    temp->prev = head;
    for (int i = 0; i < position-2; i++)
    {
        temp->prev = temp->prev->next;
    }
    temp->next = temp->prev->next;
    temp->prev->next = temp;
    if(temp->next == NULL) return head;
    temp->next->prev = temp;
    return head;
}

void print(struct Node* p)
{
    if (p == NULL)
    {
        return p;
    }
    printf("%d ", p->data);
    print(p->next);
}

int main()
{
    struct Node* head = NULL;
    head = insertnth(head, 3, 1);
    head = insertnth(head, 2, 1);
    head = insertnth(head, 7, 3);
    head = insertnth(head, 5, 4);
    print(head);
    printf("\n");
    head = insertnth(head, 8, 3);
    print(head);
    printf("\n");
}