#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};

bool isempty(struct tree* root) {
    return (root == NULL) ? true : false;
}

struct tree* allocnode(int data) {
    struct tree* temp = (struct tree*)malloc(sizeof(struct tree*));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct tree* falsebts(struct tree* root, int data) {
    if(isempty(root))
        return allocnode(data);

    if(data <= root->data)
        root->right = falsebts(root->right, data);
    else
        root->left = falsebts(root->left, data);
    return root;
}

struct tree* truebts(struct tree *root, int data) {
    if(isempty(root))
        return allocnode(data);
    
    if(data <= root->data)
        root->left = truebts(root->left, data);
    else
        root->right = truebts(root->right, data);
    return root;
}

int min(struct tree* root) {
    if(root->left == NULL)
        return root->data;
    return min(root->left);
}

int max(struct tree* root) {
    if(root->right == NULL)
        return root->data;
    return max(root->right);
}

// Usa algoritmo depth-first preorder para validar si es bts o no
int checkbts(struct tree *root) {
    if(isempty(root))
        return 1;

    checkbts(root->left);
    checkbts(root->right);

    if((root->left == NULL || root->data > root->left->data) && 
        (root->right == NULL || root->data < root->right->data))
        return 1;
    else
        return 0;
}

int main() {
    struct tree* rooty = NULL;
    struct tree* rootn = NULL;

    rooty = truebts(rooty, 100);
    rooty = truebts(rooty, 50);
    rooty = truebts(rooty, 200);
    rooty = truebts(rooty, 25);
    rooty = truebts(rooty, 75);
    printf("Min: %d\n", min(rooty));
    printf("Max: %d\n", max(rooty));

    rootn = falsebts(rootn, 100);
    rootn = falsebts(rootn, 50);
    rootn = falsebts(rootn, 200);
    rootn = falsebts(rootn, 25);
    rootn = falsebts(rootn, 75);
    printf("Min: %d\n", min(rootn));
    printf("Max: %d\n", max(rootn));

    printf("Es rooty un arbol binario de busqueda? : %d\n", checkbts(rooty));
    printf("Es rootn un arbol binario de busqueda? : %d\n", checkbts(rootn));
}

