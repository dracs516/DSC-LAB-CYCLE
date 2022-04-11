#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;
node *head;

createNodeList(int n)
{
    node *newNode, *temp;
    head = malloc(sizeof(node));
    if (head == NULL)
    {
        printf("Node Creation failed");
    }
    else
    {
        printf("Insert data in the node 1: ");
        scanf("%d", &head->data);
        head->next = NULL;
        temp = head;

        for (int i = 2; i <= n; i++)
        {
            newNode = malloc(sizeof(node));
            if (newNode == NULL)
            {
                printf("Node Creation failed");
            }
            else
            {
                printf("Insert data in the node %d: ", i);
                scanf("%d", &newNode->data);
                temp->next = newNode;
                temp = temp->next;
            }
        }
    }
}

void insert_node_at_end()
{
    node *newNode, *endptr;
    endptr = head;
    newNode = malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Node Creation failed.");
    }
    else
    {
        printf("Insert data in the last node: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;
    }
    while (endptr->next != NULL)
    {
        endptr = endptr->next;
    }
    endptr->next = newNode;
    endptr = newNode;
    printf("Data is successfully entered in the list\n");
}

void delete_at_beginning()
{
}

int main()
{
    int n;
    char ans;
    printf("Enter the no. of nodes you want: ");
    scanf("%d", n);
    createNodeList(n);
    printf("Do you want to insert node at the end? (y/n): ");
    scanf("%c", &ans);
    switch (ans)
    {
    case 'y':
        insert_node_at_end();
        break;

    case 'n':

    default:
        break;
    }
}