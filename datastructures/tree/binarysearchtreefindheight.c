#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *left_node;
    struct Node *right_node;
};

struct Node* generate_node(int data)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->data = data;
    temp->left_node = NULL;
    temp->right_node = NULL;
    return temp;
}

struct Node* bts_insert(struct Node* root, int data)
{
    if(root == NULL) {
        return generate_node(data);
    } else if(data <= root->data) {
        root->left_node = bts_insert(root->left_node, data);
    } else {
        root->right_node = bts_insert(root->right_node, data);
    }
    return root;
}

int bts_min(struct Node* root)
{
    if(root == NULL) return -1;
    if(root->left_node == NULL)
        return root->data;
    return bts_min(root->left_node);
}

int bts_max(struct Node* root)
{
    if(root == NULL) return -1;
    if(root->right_node == NULL)
        return root->data;
    return bts_max(root->right_node);
}

int max_value(int a, int b)
{
    return (a > b) ? a : b;
}

int bts_height(struct Node* root)
{
    if(root == NULL)
        return -1;
    return max_value(bts_height(root->left_node), bts_height(root->right_node)) + 1;
}

/*             10             
*            /    \           
*           /      \          
*          5        29        
*         / \      /  \       
*        3   8    19   40     
*                /  \         
*               16   22     */
int main()
{
    struct Node *root = NULL;
    root = bts_insert(root, 10);
    root = bts_insert(root, 5);
    root = bts_insert(root, 8);
    root = bts_insert(root, 3);
    root = bts_insert(root, 29);
    root = bts_insert(root, 40);
    root = bts_insert(root, 19);
    root = bts_insert(root, 22);
    root = bts_insert(root, 16);
    printf("Min value of BTS: %d\n", bts_min(root));
    printf("Max value of BTS: %d\n", bts_max(root));
    printf("Max height of BTS: %d\n", bts_height(root));
}