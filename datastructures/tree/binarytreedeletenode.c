#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

struct tree
{
    int data;
    struct tree* left;
    struct tree* right;
};

struct tree* allocnode(int data) {
    struct tree *temp = (struct tree*)malloc(sizeof(struct tree*));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct tree* insert(struct tree* root, int data) {
    if(root == NULL)
        return allocnode(data);
    if(data <= root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

struct tree* min(struct tree* root) {
    if(root->left == NULL)
        return root;
    return min(root->left);
}

int max(struct tree* root) {
    if(root->right == NULL)
        return root->data;
    return max(root->right);
}

void inordertraversal(struct tree* root) {
    if(root == NULL)
        return;
    
    inordertraversal(root->left);
    printf("%d ", root->data);
    inordertraversal(root->right);
}

struct tree* delete(struct tree* root, int data) {
    if(root == NULL)
        return root;
    if(data < root->data)
        root->left = delete(root->left, data);
    if(data > root->data)
        root->right = delete(root->right, data);

    if(data == root->data) {
        if(root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        } else if(root->left == NULL) {
            struct tree* temp = root;
            root = temp->right;
            free(temp);
        } else if(root->right == NULL) {
            struct tree* temp = root;
            root = temp->left;
            free(temp);
        } else {
            struct tree *temp = min(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

int main() {
    struct tree* root = NULL;
    root = insert(root, 100);
    root = insert(root, 50);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 70);
    root = insert(root, 71);
    root = insert(root, 72);
    root = insert(root, 62);
    root = insert(root, 78);
    root = insert(root, 200);
    root = insert(root, 150);
    root = insert(root, 300);
    inordertraversal(root);
    struct tree* minvalue = min(root);
    printf("min: %d\n", minvalue->data);
    printf("max: %d\n", max(root));
    root = delete(root, 70);
    struct tree* val = min(root);
    printf("min: %d\n", val->data);
    inordertraversal(root);
}