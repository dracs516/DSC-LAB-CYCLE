#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *createNode(int data)
{
    node *n;
    n = malloc(sizeof(node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
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

node *insertNode(node *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
    }
    else
    {
        if (data < root->data)
        {
            root->left = insertNode(root->left, data);
        }
        else
        {
            root->right = insertNode(root->right, data);
        }
    }
    return root;
}

node *rootSuccessor(node *root)
{
    node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

node *deleteNode(node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    else if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        else if (root->left == NULL)
        {
            node *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            node *temp = root;
            root = root->left;
            free(temp);
        }
        else
        {
            node *temp = rootSuccessor(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

node *searchNode(node *root, int data)
{
    while (root != NULL)
    {
        if (root->data == data)
        {
            return root;
        }
        else if (data < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}

int main()
{
    node *p = createNode(10);
    node *p1 = createNode(1);
    node *p2 = createNode(12);
    node *p3 = createNode(5);
    node *p4 = createNode(11);
    node *p5 = createNode(13);

    /*
                        10
                    /        \
                /               \
                1                 12
                    \           /   \
                      5         11    13

    */

    p->left = p1;
    p->right = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;

    inOrder(p);
    printf("\n");

    insertNode(p, 15);
    insertNode(p, 7);
    insertNode(p, 9);
    insertNode(p, 2);

    inOrder(p);
    printf("\n");

    deleteNode(p, 5);
    inOrder(p);
    printf("\n");

    deleteNode(p, 10);
    inOrder(p);
    printf("\n");

    node *n = searchNode(p, 9);
    if (n != NULL)
    {
        printf("Found: %d", n->data);
    }
    else
    {
        printf("Not Found");
    }

    return 0;
}