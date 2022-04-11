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

node *findMin(node *node)
{
    struct node *prev = node;

    while (prev && prev->left != NULL)
    {
        prev = prev->left;
    }
    return prev;
}

node *delete (node *root, int key)
{
    node *temp;
    if (root == NULL)
    {
        printf("element not in tree");
    }
    else if (key < root->data)
    {
        root->left = delete (root->left, key);
    }
    else if (key > root->data)
    {
        root->right = delete (root->right, key);
    }
    else
    {
        // element to be deleted is found
        if (root->left && root->right)
        {
            temp = findMin(root->left);
            root->data = temp->data;
            root->left = delete (root->left, root->data);
        }
        else
        {
            // one child
            temp = root;
            if (root->left == NULL)
            {
                root = root->right;
            }
            if (root->right == NULL)
            {
                root = root->left;
            }
            free(temp);
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

    inOrder(p);
    delete (p, 5);
    inOrder(p);
    return 0;
}