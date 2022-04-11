#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int key;
    struct node *right;
    struct node *left;
    int height;
} ab;

ab *root = NULL;
int balancefactor(ab *root)
{
    if (root == NULL)
        return 0;
    else
        return getheight(root->left) - getheight(root->right);
}
int max(int a, int b)
{
    return (a > b) ? a : b;
}
struct node *rotateright(ab *y)
{
    ab *x = y->left;
    ab *t2 = x->right;

    x->right = y;
    y->left = t2;
    x->height = 1 + max(getheight(x->left), getheight(x->right));
    y->height = 1 + max(getheight(y->left), getheight(y->right));
    return x;
}
struct node *rotateleft(ab *x)
{
    ab *y = x->right;
    ab *t2 = y->left;

    y->left = x;
    x->right = t2;
    x->height = 1 + max(getheight(x->left), getheight(x->right));
    y->height = 1 + max(getheight(y->left), getheight(y->right));
    return y;
}
int getheight(struct node *root)
{
    if (root == NULL)
        return 0;
    else
        return root->height;
}
ab *insert(ab *root, int val)
{
    if (root == NULL)
    {
        root = malloc(sizeof(ab));
        root->key = val;
        root->right = NULL;
        root->left = NULL;
        root->height = 1;
        return root;
    }

    if (root->key > val)
        root->left = insert(root->left, val);
    if (root->key < val)
        root->right = insert(root->right, val);
    if (root->key == val)
    {
        printf("ERROR 404:YOU CANNOT ENTER THE SAME VALUE IN A TREE TWICE PLEASE EXIT \n");
        exit(1);
    }
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    int bf = balancefactor(root);
    // return root;

    // left left case
    if (bf > 1 && root->key > val)
    {
        return rotateright(root);
    }
    // right right case
    if (bf < -1 && root->key < val)
        return rotateleft(root);
    // right left case
    if (bf < -1 && root->right->key > val)
    {
        root->right = rotateright(root->right);
        return rotateleft(root);
    }
    // left right case
    if (bf > 1 && root->left->key < val)
    {
        root->left = rotateleft(root->left);
        return rotateright(root);
    }
    return root;
}
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    preorder(root);
    return 0;
}