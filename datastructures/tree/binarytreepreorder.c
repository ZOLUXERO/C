#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};

/* QUEUE */
struct queue
{
    struct tree *treenode;
    struct queue *next;
};

struct queue *head = NULL;
struct queue *tail = NULL;

bool isqueueemtpy() {
    return (head == NULL && tail == NULL) ? true : false;
}

void push(struct tree *node) {
    struct queue *temp = (struct queue*)malloc(sizeof(struct queue*));
    temp->treenode = node;
    temp->next = NULL;
    if(isqueueemtpy()) {
        head = tail = temp;
        return;
    }
    tail->next = temp;
    tail = temp;
}

struct tree* pop() {
    if(isqueueemtpy()) return NULL;

    struct queue *temp = head;
    struct tree *value = head->treenode;
    head = temp->next;
    free(temp);
    return value;
}

struct tree* first() {
    if(isqueueemtpy()) return NULL;
    return head->treenode;
}
/* QUEUE */

/* TREE */
bool treeisempty(struct tree *root) {
    return (root == NULL) ? true : false;
}

struct tree* allocnode(int data) {
    struct tree *newnode = (struct tree*)malloc(sizeof(struct tree*));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct tree* insert(struct tree *root, int data) {
    if(treeisempty(root)) {
        return allocnode(data);
    } else if(data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

int min(struct tree *root) {
    if(treeisempty(root)) return -1;
    if(root->left == NULL) return root->data;
    return min(root->left);
}

int max(struct tree *root) {
    if(treeisempty(root)) return -1;
    if(root->right == NULL) return root->data;
    return max(root->right);
}

void preorder(struct tree *root) {
    if(treeisempty(root)) return;

    printf("%d ", root->data);
    if(root->left != NULL)
        preorder(root->left);

    if(root->right != NULL)
        preorder(root->right);
}

void inorderreversal(struct tree *root) {
    if(treeisempty(root)) return;

    if(root->right != NULL)
        inorderreversal(root->right);
    
    printf("%d ", root->data);

    if(root->left != NULL)
        inorderreversal(root->left);
}
/* TREE */

int main() {
    struct tree *root = NULL;
    root = insert(root, 89);
    root = insert(root, 49);
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 60);
    root = insert(root, 58);
    root = insert(root, 62);
    root = insert(root, 120);
    printf("min: %d\n", min(root));
    printf("max: %d\n", max(root));
    preorder(root);
    printf("\n");
    inorderreversal(root);
}