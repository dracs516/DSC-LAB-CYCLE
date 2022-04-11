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

node *insert(node *root, int key)
{
    if (root == NULL)
    {
        root = createNode(key);
    }
    else
    {

        if (key < root->data)
        {
            root->left = insert(root->left, key);
        }
        else
        {
            root->right = insert(root->right, key);
        }
    }
    return root;
}

int main()
{
    // node *p;
    node *p = createNode(5);
    node *p1 = createNode(3);
    node *p2 = createNode(6);
    node *p3 = createNode(1);
    node *p4 = createNode(4);

    /*

            5
        /       \
        3       6
    /       \
    1       4

    */
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    insert(p, 2);
    inOrder(p);
    printf("\n");
    insert(p, 7);
    insert(p, 0);
    inOrder(p);
    printf("\n");
    return 0;
}