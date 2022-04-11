#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

int main()
{
    int n;
    printf("Enter the no. of node u want!!!!!!! jaldiiiiiiii!!!!!!:::: ");
    scanf("%d", &n);

    node *head, *newnode, *temp, *print;

    head = malloc(sizeof(node));
    if (head == NULL)
    {
        printf("Node creation failed/memory allocation failed");
    }
    else
    {
        printf("Enter the data at the node 1: ");
        scanf("%d", &head->data);
        head->next = NULL;
        temp = head;

        for (int i = 2; i <= n; i++)
        {
            newnode = malloc(sizeof(node));
            if (newnode == NULL)
            {
                printf("Node creation failed/memory allocation failed");
            }
            else
            {
                printf("Enter the data at the node %d: ", i);
                scanf("%d", &newnode->data);
                newnode->next = NULL;
                temp->next = newnode;
                temp = newnode;
            }
        }
        print = head;
        int num = 1;
        while (print != NULL)
        {
            printf("Data %d = %d", num, print->data);
            printf("\n");
            num++;
            print = print->next;
        }
    }
    return 0;
}