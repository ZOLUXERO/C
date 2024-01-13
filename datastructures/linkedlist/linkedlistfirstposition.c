#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next_node;
};

/**
 * en este caso head es una copia, si se quiere pasar la direccion del 
 * head verdadero se pude hacer desreferenciando head struct Node** head
 * y en la funcion main() ya no se usaria head = insert(head, x); si no
 * insert(&head, x); esto lo que hace es modificar el alcance del head
*/
struct Node* insert(struct Node* head, int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x; // esto es lo mismo que decir (*list).data
    temp->next_node = head;
    head = temp;
    return head;
}

void print(struct Node* head)
{
    printf("Lista: \n");
    while (head != NULL)
    {
        printf(" %d", head->data);
        head = head->next_node;
    }
    printf("\n");
    
}

int main()
{
    struct Node* head = NULL;
    printf("Cuantos numeros?\n");
    int n,x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Ingrese el numero \n");
        scanf("%d", &x);
        head = insert(head, x);
        print(head);
    }
    
}