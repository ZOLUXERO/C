#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/* TREE */
struct tree
{
    int data;
    struct tree* left;
    struct tree* right;
};

bool isempty(struct tree *root) {
    return (root == NULL) ? true : false;
}

struct tree* allocnode(int data) {
    struct tree *temp = (struct tree*)malloc(sizeof(struct tree*));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct tree* insert(struct tree *root, int data) {
    if(isempty(root))
        return allocnode(data);
    if(data <= root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

int min(struct tree* root) {
    if(isempty(root))
        return -1;
    if(root->left == NULL)
        return root->data;
    return min(root->left);
}

int max(struct tree* root) {
    if(isempty(root))
        return -1;
    if(root->right == NULL)
        return root->data;
    return max(root->right);
}

void inorder(struct tree* root) {
    if(isempty(root))
        return;

    if (root->left != NULL)
        inorder(root->left);
    
    printf("%d ", root->data);

    if (root->right != NULL)
        inorder(root->right);
}

void postorder(struct tree* root) {
    if(isempty(root))
        return;

    if(root->left != NULL)
        postorder(root->left);
    if(root->right != NULL)
        postorder(root->right);

    printf("%d ", root->data);
}


int main() {
    struct tree *root = NULL;
    root = insert(root, 100);
    root = insert(root, 50);
    root = insert(root, 70);
    root = insert(root, 30);
    root = insert(root, 200);
    printf("min: %d\n", min(root));
    printf("max: %d\n", max(root));
    inorder(root);
    printf("\n");
    postorder(root);
}