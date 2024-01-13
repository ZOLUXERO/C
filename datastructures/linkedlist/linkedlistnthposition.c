#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next_position;
};

struct Node* head;

void insert(int x, int n)
{
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node*));
    temp1->data = x;
    temp1->next_position = NULL;
    if(n == 1)
    {
        temp1->next_position = head;
        head = temp1;
        return;
    }

    struct Node* temp2 = head;    
    for(int i = 0; i < n-2; i++)
    {
        temp2 = temp2->next_position;
    }
    temp1->next_position = temp2->next_position;
    temp2->next_position = temp1;
}

void print()
{
    struct Node* temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next_position;
    }
    printf("\n");
    
}

int main()
{
    head = NULL;
    insert(2,1);
    insert(3,2);
    insert(4,1);
    insert(5,2);
    insert(6,3);
    insert(7,5);
    print();
}