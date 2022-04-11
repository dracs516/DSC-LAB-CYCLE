#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *ptr;
} ab;
int ask()
{
    int a;
    printf("Enter how many nodes do you want?\n");
    scanf("%d", &a);
    return a;
}

void display(ab *l)
{
    while (l != NULL)
    {
        printf("%d\n", l->data);
        l = l->ptr;
    }
}
int main()
{
    ab *ob1, *n, *temp;
    ob1 = malloc(sizeof(ab));
    printf("Enter the data you want to input at node 1\n");
    scanf("%d", &ob1->data);
    ob1->ptr = NULL;
    temp = ob1;
    int d = ask();
    for (int i = 0; i < (d - 1); i++)
    {
        n = malloc(sizeof(ab));
        n->ptr = NULL;
        printf("Enter the value you want to input at node %d\n", i + 2);
        scanf("%d", &n->data);
        temp->ptr = n;
        temp = n;
    }
    display(ob1);
    free(ob1);
    free(n);
    return 0;
}