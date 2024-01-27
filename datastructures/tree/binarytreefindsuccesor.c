#include<stdio.h>
#include<stdlib.h>
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

struct tree* insert(struct tree *root, int data) {
    if(root == NULL)
        return allocnode(data);
    if(data < root->data)
        root->left = insert(root->left, data);
    if(data > root->data)
        root->right = insert(root->right, data);
    return root;
}

struct tree* insertreverse(struct tree *root, int data) {
    if(root == NULL)
        return allocnode(data);
    if(data > root->data)
        root->left = insertreverse(root->left, data);
    if(data < root->data)
        root->right = insertreverse(root->right, data);
    return root;
}

struct tree* reverse(struct tree *root, struct tree *temp) {
    if(root == NULL)
        return root;
    
    temp = insertreverse(temp, root->data);
    reverse(root->right, temp);
    reverse(root->left, temp);
    return temp;
}

struct tree* min(struct tree *root) {
    if(root == NULL)
        return root;
    if(root->left == NULL)
        return root;
    return min(root->left);
}

void printtree(struct tree *root) {
    if(root == NULL)
        return;
    printtree(root->left);
    printf("%d ", root->data);
    printtree(root->right);
}

// postorder
bool checkifbts(struct tree* root) {
    if(root == NULL)
        return true;

    // valida primero todos los nodos
    checkifbts(root->left);
    checkifbts(root->right);

    /* si el valor izquierdo es nulo o es menor al valor actual Y
    *  el valor derecho es nulo o es mayor al valor actual es un 
    *  arbol binario de busqueda */
    if((root->left == NULL || root->data > root->left->data) &&
        (root->right == NULL || root->data < root->right->data))
        return true;
    return false;
}

void checktree(struct tree* root) {
    bool tree = checkifbts(root);
    if(tree)
        printf("Es un arbol binario de busqueda\n");
    else
        printf("No es un arbol binario de busqueda\n");
}

struct tree* findintree(struct tree *root, int data) {
    if(root == NULL)
        return root;
    if(data == root->data)
        return root;
    
    if(data < root->data)
        root = findintree(root->left, data);
    else if(data > root->data)
        root = findintree(root->right, data);
    return root;
}

void findvalueintree(struct tree *root, int data) {
    struct tree *temp = NULL;
    temp = findintree(root, data);
    if(temp == NULL)
        printf("\nValor %d no existe en el arbol\n", data);
    else
        printf("\nEl valor %d existe en el arbol\n", data);
}

void inordersuccessor(struct tree *root, int data) {
    if(root == NULL)
        return;

    struct tree *current = findintree(root, data);
    if(current == NULL) {
        printf("El valor %d no existe en el arbol", data);
        return;
    }

    if(current->right != NULL) {
        current = min(current->right);
        printf("El valor sucesor es: %d\n", current->data);
    } else {
        struct tree *sucesor = NULL;
        struct tree *ancestro = root;
        while (ancestro != current) {
            if(current->data < ancestro->data) {
                sucesor = ancestro;
                ancestro = ancestro->left;
            } else {
                ancestro = ancestro->right;
            }
        }
        printf("El sucesor es %d\n", sucesor->data);
    }
}

int main() {
    struct tree* root = NULL;
    root = insert(root, 100);
    root = insert(root, 50);
    root = insert(root, 200);
    root = insert(root, 75);
    root = insert(root, 20);
    checktree(root);
    printtree(root);
    findvalueintree(root, 20);
    findvalueintree(root, 25);
    inordersuccessor(root, 75);

    printf("\n");
    struct tree* reversetree = NULL;
    reversetree = insertreverse(reversetree, 100);
    reversetree = insertreverse(reversetree, 50);
    reversetree = insertreverse(reversetree, 200);
    reversetree = insertreverse(reversetree, 75);
    reversetree = insertreverse(reversetree, 20);
    checktree(reversetree);
    printtree(reversetree);

    printf("\n");
    struct tree* revtree = NULL;
    revtree = reverse(root, revtree);
    checktree(revtree);
    printtree(revtree);
}