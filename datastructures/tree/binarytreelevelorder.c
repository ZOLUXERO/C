#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_QUEUE_SIZE 100

struct bts_node
{
    int data;
    struct bts_node *left;
    struct bts_node *right;
};

/********************************************
*       START OF QUEUE IMPLEMENTATION
*********************************************/
// This implementation of queue use a linked list as main logic to save the queue data
struct queue_node
{
    struct bts_node *ptr_to_bts_node;
    struct queue_node *next;
};

struct queue_node *front_queue_ptr = NULL;
struct queue_node *rear_queue_ptr = NULL;
int current_queue_size = 0;

bool queue_is_full()
{
    if(current_queue_size >= MAX_QUEUE_SIZE) {
        printf("Queue is full\n");
        return true;
    }
    return false;
}

bool queue_is_empty()
{
    if(front_queue_ptr == NULL && rear_queue_ptr == NULL) {
        printf("\nQueue is empty waiting for value to be inserted...\n");
        return true;
    }
    return false;
}

void push(struct bts_node *ptr)
{
    if(queue_is_full())
        return;

    struct queue_node *temp = (struct queue_node*)malloc(sizeof(struct queue_node*));
    temp->ptr_to_bts_node = ptr;
    temp->next = NULL;

    if(queue_is_empty()) {
        front_queue_ptr = rear_queue_ptr = temp;
        current_queue_size++;
        return;
    }
    rear_queue_ptr->next = temp;
    rear_queue_ptr = temp;
    current_queue_size++;
}

/* In this specific implementation of dequeue we must return pointer to BTS so we can validate later the value of the pointer */
struct bts_node* pop()
{
    if(queue_is_empty())
        return 0;
    
    struct queue_node *temp = front_queue_ptr;
    struct bts_node *front_value = temp->ptr_to_bts_node;
    front_queue_ptr = temp->next;
    if(temp->next == NULL) rear_queue_ptr = temp->next;
    free(temp);
    current_queue_size--;
    return front_value;
}

/* In this specific implementation of first on queue we must return pointer to BTS so we can validate later the value of the pointer */
struct bts_node* first()
{
    if(queue_is_empty())
        return 0;
    return front_queue_ptr->ptr_to_bts_node;
}

struct bts_node* last()
{
    if(queue_is_empty())
        return 0;
    return rear_queue_ptr->ptr_to_bts_node;
}
/********************************************
*       END OF QUEUE IMPLEMENTATION
*********************************************/

/********************************************
*     START OF BINARY TREE IMPLEMENTATION
*********************************************/
struct bts_node* allocate_bts_node(int data)
{
    struct bts_node *temp = (struct bts_node*)malloc(sizeof(struct bts_node*));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct bts_node* bts_insert(struct bts_node *root, int data)
{
    if(root == NULL) {
        return allocate_bts_node(data);
    } else if(data <= root->data) {
        root->left = bts_insert(root->left, data);
    } else {
        root->right = bts_insert(root->right, data);
    }
    return root;
}

int min(struct bts_node *root)
{
    if(root == NULL) return -1;
    if(root->left == NULL) return root->data;
    return min(root->left);
}

int max(struct bts_node *root)
{
    if(root == NULL) return -1;
    if(root->right == NULL) return root->data;
    return max(root->right);
}
/********************************************
*      END OF BINARY TREE IMPLEMENTATION
*********************************************/

void level_order(struct bts_node *root)
{
    if(root == NULL) return;

    push(root);

    while (!queue_is_empty()) {

        /* You can use pop instead of first in here but you will be printed a Queue is empty line 
        on the first print of the queue and also this looks a little better */
        struct bts_node *current = first();
        printf("%d ", current->data);
        if(current->left != NULL) push(current->left);
        if(current->right != NULL) push(current->right);
        pop();
    }
}


int main()
{
    struct bts_node *root = NULL;
    root = bts_insert(root, 20);
    root = bts_insert(root, 10);
    root = bts_insert(root, 30);
    root = bts_insert(root, 15);
    root = bts_insert(root, 5);
    printf("Min element of BTS: %d\n", min(root));
    printf("Max element of BTS: %d\n", max(root));
    level_order(root);
}