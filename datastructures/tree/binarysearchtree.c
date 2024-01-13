#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *left_node;
    struct Node *right_node;
};

struct Node* insert(int data)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->data = data;
    temp->left_node = temp->right_node = NULL;
    return temp;
}

struct Node* bts_insert(struct Node *root, int data)
{
    if(root == NULL) {
        root = insert(data);
    } else if(data <= root->data) {
        root->left_node = bts_insert(root->left_node, data);
    } else {
        root->right_node = bts_insert(root->right_node, data);
    }

    return root;
}

int bts_min(struct Node *bts)
{
    if(bts == NULL) return -1;
    if(bts->left_node == NULL) return bts->data;
    return bts_min(bts->left_node);
}

int bts_max(struct Node *bts)
{
    if(bts == NULL) return -1;
    if(bts->right_node == NULL) return bts->data;
    return bts_max(bts->right_node);
}

int main()
{
    struct Node *root = NULL;
    root = bts_insert(root, 10);
    root = bts_insert(root, 9);
    root = bts_insert(root, 7);
    printf("Max value on BTS: %d\n", bts_max(root));
    root = bts_insert(root, 11);
    root = bts_insert(root, 12);
    printf("Max value on BTS: %d\n", bts_max(root));
    printf("Min value on BTS: %d\n", bts_min(root));
    root = bts_insert(root, 6);
    printf("Min value on BTS: %d\n", bts_min(root));
}