#include<stdlib.h>
#include<stdio.h>

struct linkedlist
{
    char data;
    struct linkedlist *next;
};

struct linkedlist *tail = NULL;

struct linkedlist* insert(struct linkedlist *head, char data) {
    struct linkedlist *newnode = (struct linkedlist*)malloc(sizeof(struct linkedlist*));
    newnode->data = data;
    newnode->next = NULL;
    if(head == NULL) {
        head = newnode;
        tail = newnode;
    } else {
        tail->next = newnode;
        tail = newnode;
    }
    return head;
}

void printlist(struct linkedlist *list) {
    if(list == NULL)
        return;
    printlist(list->next);
    printf("%c", list->data);
}

int main() {
    struct linkedlist *head = NULL;
    head = insert(head, 'H');
    head = insert(head, 'O');
    head = insert(head, 'L');
    head = insert(head, 'A');

    printlist(head);
}