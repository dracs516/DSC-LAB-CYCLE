#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} ab;

int ask()
{
    int a;
    printf("enter the number of nodes you want to enter in the program\n");
    scanf("%d", &a);
    return a;
}

void print(ab *l)
{
    int c = 1;
    while (l != NULL)
    {
        printf("the value at the %d th node is %d\n", c, l->data);
        l = l->link;
        c++;
    }
}

int main()
{
    ab *head, *n, *temp, *newnode;
    int d;
    head = malloc(sizeof(ab));
    printf("enter the data you want to input in the first node \n");
    scanf("%d", &head->data);
    head->link = NULL;
    temp = head;
    d = ask();
    newnode = malloc(sizeof(ab));
    printf("enter the value at the new node \n");
    scanf("%d", &newnode->data);
    newnode->link = NULL;
    newnode->link = head;

    for (int i = 0; i < (d - 1); i++)
    {
        n = malloc(sizeof(ab));
        printf("enter the value you want to enter at %d th node\n", i + 2);
        scanf("%d", &n->data);
        n->link = NULL;
        temp->link = n;
        temp = n;
    }
    print(newnode);

    return 0;
}