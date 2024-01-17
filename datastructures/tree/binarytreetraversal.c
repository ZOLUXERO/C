#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct nodetree
{
    int data;
    struct nodetree *left;
    struct nodetree *right;
};


/* START QUEUE IMPLEMENTATION */
#define MAX_QUEUE_SIZE 100
struct nodequeue
{
    struct nodetree *tree;
    struct nodequeue *next;
};

struct nodequeue *head = NULL;
struct nodequeue *tail = NULL;
int queue_size = 0;

bool isempty() {
    if(head == NULL && tail == NULL)
        return true;
    return false; 
}

bool isfull() {
    if(queue_size == MAX_QUEUE_SIZE) {
        printf("Error: Queue is currently full\n");
        return true;
    }
    return false;
}

void push(struct nodetree *tree) {
    if(isfull())
        return;

    struct nodequeue *current_node = (struct nodequeue*)malloc(sizeof(struct nodequeue*));
    current_node->tree = tree;
    current_node->next = NULL;
    if (isempty()) {
        head = tail = current_node;
        queue_size++;
        return;
    }
    tail->next = current_node;
    tail = current_node;
    queue_size++;
}

int pop() {
    if(isempty())
        return -1;

    struct nodequeue *temp = head;
    int data = temp->tree->data;
    head = temp->next;
    if(head == NULL)
        tail = NULL;
    free(temp);
    return data;
}

struct nodetree* firstinqueue() {
    if(isempty())
        return NULL;

    return head->tree;
}
/* END QUEUE IMPLEMENTATION */

/* START TREE IMPLEMENTATION */
bool nodeisempty(struct nodetree *root) {
    if(root == NULL)
        return true;

    return false;
}

struct nodetree* allocatenode(int data) {
    struct nodetree *temp = (struct nodetree*)malloc(sizeof(struct nodetree*));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct nodetree* insert(struct nodetree *root, int data) {
    if(nodeisempty(root)) {
        return allocatenode(data);
    } else if(data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

int min(struct nodetree *root) {
    if(nodeisempty(root))
        return -1;
    if(root->left == NULL)
        return root->data;
    return min(root->left);
}

int max(struct nodetree *root) {
    if(nodeisempty(root))
        return -1;
    if(root->right == NULL)
        return root->data;
    return max(root->right);
}

void level_order_algo(struct nodetree *node) {
    if (nodeisempty(node))
        return;
    
    push(node);
    while(!isempty()) {
        /* El current_node que analiza si debe encolar o no 
        siempre debe ser el primer valor en la cola */
        struct nodetree *current_node = firstinqueue();
        printf("%d ", current_node->data);
        if(current_node->left != NULL)
            push(current_node->left);
        if(current_node->right != NULL)
            push(current_node->right);
        pop();
    }
}
/* END TREE IMPLEMENTATION */

struct nodetree* poblatetree() {
    struct nodetree *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 12);
    root = insert(root, 35);
    root = insert(root, 57);
    root = insert(root, 70);
    return root;
}

int main() {
    struct nodetree *tree = poblatetree();
    printf("Min: %d\n", min(tree));
    printf("Max: %d\n", max(tree));
    level_order_algo(tree);
}