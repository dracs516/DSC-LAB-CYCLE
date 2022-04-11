#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} ab;

int main()
{
    int a;
    ab *head, *newnode, *temp, *ran, *n;
    printf("Enter how many nodes u want");
    scanf("%d", &a);
    head = malloc(sizeof(ab));
    printf("Enter the data u want to put in node 1: \n");
    scanf("%d", &head->data);
    head->link = NULL;
    temp = head;
    for (int i = 1; i < a; i++)
    {
        newnode = malloc(sizeof(ab));
        printf("Enter the data u want to enter in node %d: ", i + 1);
        scanf("%d", &newnode->data);
        temp->link = newnode;
        temp = newnode;
    } // newnode->link->data
    n->data = 5;
    n->link = NULL;
    temp = head;
    while (n->data >= temp->data)
    {
        ran = temp;
        temp = temp->link;
    }
    n->link = temp;
    ran->link = n;
    temp = head;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->link;
    }

    return 0;
}