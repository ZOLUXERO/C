#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head;

void reverse(struct Node* p)
{
    if (p->next == NULL)
    {
        head = p;
        return;
    }
    reverse(p->next);
    struct Node* q = p->next;
    q->next = p;
    p->next = NULL;
}

struct Node* reversephead(struct Node* p)
{
    struct Node* temp;
    if (p->next == NULL)
    {
        return p;
    }
    temp = reversephead(p->next); // temp queda con el ultimo valor del linked list
    struct Node* q = p->next;
    q->next = p;
    p->next = NULL;
    return temp;
}

void insert(int value)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->next = head;
    temp->data = value;
    head = temp;
}

struct Node* insertnth(struct Node* p, int value, int position)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->data = value;
    temp->next = p;
    if (position == 1)
    {
        p = temp;
        return p;
    }
    struct Node* temp2 = p;
    for (int i = 0; i < position-2; i++)
    {
        temp2 = temp2->next;
        if (temp2->next == NULL && position-3 > i)
        {
            printf("Error: can't put value %d in position %d, the list doesn't contains that ammount of values\n", value, position);
            return p;
        }
    }
    temp->next = temp2->next;
    temp2->next = temp;
    return p;
    
}

void print(struct Node* p)
{
    if (p->next == NULL)
    {
        printf("%d ", p->data);
        return;
    }
    // print(p->next); // reverse
    printf("%d ", p->data);
    print(p->next); // in order
}

int main()
{
    insert(1);
    insert(1);
    insert(3);
    insert(5);
    print(head);
    printf("\n");
    reverse(head);
    print(head);
    printf("\n");

    struct Node* phead = NULL;
    phead = insertnth(phead, 2, 1);    
    phead = insertnth(phead, 3, 2);    
    phead = insertnth(phead, 5, 3);    
    phead = insertnth(phead, 7, 4);    
    print(phead);
    printf("\n");
    phead = insertnth(phead, 4, 2);    
    phead = insertnth(phead, 9, 7);    
    print(phead);
    printf("\n");
    phead = reversephead(phead);
    print(phead);
    printf("\n");
}