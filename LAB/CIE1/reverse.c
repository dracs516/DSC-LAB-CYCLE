#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head, *tempr;

void createNode(n)
{
    node *temp;
    head = malloc(sizeof(node));
    if (head == NULL)
    {
        printf("Node Creation Failed... Try again...");
    }
    else
    {
        printf("Insert the data in the node 1: ");
        scanf("%d", &head->data);
        head->next = NULL;
        temp = head;
        if (n > 1)
        {
            node *newNode;
            for (int i = 2; i <= n; i++)
            {
                newNode = malloc(sizeof(node));
                if (newNode == NULL)
                {
                    printf("Node Creation Failed... Try again...");
                }
                else
                {
                    printf("Insert the data in the node %d: ", i);
                    scanf("%d", &newNode->data);
                    temp->next = newNode;
                    temp = temp->next;
                    newNode->next = NULL;
                }
            }
        }
    }
}

void display()
{
    node *ptr;
    ptr = head;
    int i = 1;
    if (head == NULL)
    {
        printf("List not created\n");
    }
    while (ptr != NULL)
    {
        printf("Data at node %d = %d", i, ptr->data);
        printf("\n");
        i++;
        ptr = ptr->next;
    }
}

void reverse()
{
    node *start, *end;
    tempr = head;
    while (tempr != NULL)
    {
        end = tempr->next;
        tempr->next = start;
        start = tempr;
        tempr = end;
    }
    head = start;
}

int main()
{
    int n;
    printf("----------------------------------------------------------\n");
    printf("Enter the no. of nodes you want: ");
    scanf("%d", &n);
    printf("----------------------------------------------------------\n");
    if (n <= 0)
    {
        printf("No node created... Try again...");
    }
    else if (n > 0)
    {
        printf("----------------------------------------------------------\n");
        createNode(n);
        printf("----------------------------------------------------------\n");
    }
    printf("----------------------------------------------------------\n");
    display();
    printf("----------------------------------------------------------\n");
    printf("----------------------------------------------------------\n");
    printf("Reversing the list... ... \n");
    reverse();
    printf("----------------------------------------------------------\n");
    printf("----------------------------------------------------------\n");
    printf("----------------------------------------------------------\n");
    display();
    printf("----------------------------------------------------------\n");
    return 0;
}