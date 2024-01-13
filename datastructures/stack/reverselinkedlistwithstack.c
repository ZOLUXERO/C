#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct stackAdt
{
    struct Node *ptr;
    struct stackAdt *next;
};

struct Node *head = NULL;
struct stackAdt *top = NULL;

void push(struct Node *ptr)
{
    struct stackAdt *temp = (struct stackAdt*)malloc(sizeof(struct stackAdt*));
    temp->ptr = ptr;
    temp->next = top;
    top = temp;
}

void pop(struct stackAdt *ptr)
{    
    if (ptr == NULL) {
        printf("Error: pointer is NULL");
        return;
    }
    top = ptr->next;
    free(ptr);    
}

void reverseWhitStack()
{
    if(head == NULL) return;
    struct Node *nodeTemp = head;
    while (nodeTemp != NULL) {
        push(nodeTemp);
        nodeTemp = nodeTemp->next;
    }
    
    struct Node *temp = top->ptr;
    head = temp;
    pop(top); 
    while(top != NULL) {
        temp->next = top->ptr;
        pop(top);
        temp = temp->next;
    }
    temp->next = NULL;
}

void reverse(struct Node *ptr)
{
    struct Node *temp = ptr;   
    if (ptr->next == NULL) {
        head = ptr;
        return;
    }
    reverse(ptr->next);
    struct Node *nextLink = temp->next;
    nextLink->next = temp;
    temp->next = NULL;
}

void insertnth(int value, int position)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->data = value;
    temp->next = head;
    if(position == 1) {
        head = temp;
        return;
    }
    struct Node* temp2 = head;
    for (int i = 0; i < position - 2; i++) {
        temp2 = temp2->next;
    }
    temp->next = temp2->next;
    temp2->next = temp;
}

void print(struct Node *ptr)
{
    if(ptr == NULL) {
        return;
    }
    printf("%d ", ptr->data);
    print(ptr->next);
}


int main()
{
    insertnth(4, 1);
    insertnth(2, 1);
    insertnth(7, 3);
    print(head);
    printf("\n");
    // reverse(head);
    reverseWhitStack();
    print(head);
    printf("\n");
}