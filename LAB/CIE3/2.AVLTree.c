#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
} node;

void preOrder(node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int getHeight(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->height;
}

node *createNode(int data)
{
    node *newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

int getBalanceFactor(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return getHeight(root->left) - getHeight(root->right);
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

node *rightRotate(node *y)
{
    node *x = y->left;
    node *t2 = x->right;

    x->right = y;
    y->left = t2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return x;
}

node *leftRotate(node *x)
{
    node *y = x->right;
    node *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

node *insertNode(node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }

    if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }

    else if (data > root->data)
    {
        root->right = insertNode(root->right, data);
    }
    else
    {
        return root;
    }

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    int balFact = getBalanceFactor(root);

    // Left Left
    if (balFact > 1 && data < root->left->data)
    {
        return rightRotate(root);
    }

    // Right Right
    if (balFact < -1 && data > root->right->data)
    {
        return leftRotate(root);
    }

    // Left Right
    if (balFact > 1 && data > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left
    if (balFact < -1 && data < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int main()
{
    node *root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 1);
    root = insertNode(root, 12);
    root = insertNode(root, 5);
    root = insertNode(root, 11);
    root = insertNode(root, 13);
    root = insertNode(root, 15);
    root = insertNode(root, 17);
    root = insertNode(root, 19);
    root = insertNode(root, 20);
    root = insertNode(root, 21);

    preOrder(root);
    printf("\n");
    // inOrder(root);
    // printf("\n");
    return 0;
}