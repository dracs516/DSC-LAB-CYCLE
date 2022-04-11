#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head;

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

void oddeven()
{
    node *temp, *evenstart, *evenend, *oddstart, *oddend;
    temp = head;
    evenstart = NULL;
    evenend = NULL;
    oddstart = NULL;
    oddend = NULL;
    while (temp != NULL)
    {
        int val = temp->data;
        if (val % 2 == 0)
        {
            if (evenstart == NULL)
            {
                evenstart = temp;
                evenend = evenstart;
            }
            else
            {
                evenend->next = temp;
                evenend = evenend->next;
            }
        }
        else
        {
            if (oddstart == NULL)
            {
                oddstart = temp;
                oddend = oddstart;
            }
            else
            {
                oddend->next = temp;
                oddend = oddend->next;
            }
        }
        temp = temp->next;
    }
    if (evenstart == NULL || oddstart == NULL)
    {
        return;
    }

    // print1 = evenstart;
    // print2 = oddstart;
    printf("Even List is:\n");
    while (evenstart != NULL)
    {
        printf("%d ", evenstart->data);
        printf("\n");
        evenstart = evenstart->next;
    }
    printf("Odd List is:\n");
    while (oddstart != NULL)
    {
        printf("%d ", oddstart->data);
        printf("\n");
        oddstart = oddstart->next;
    }
    // printf("%d", evenend->data);
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
    printf("Creating odd and even lists... ... ... \n");
    oddeven();
    printf("----------------------------------------------------------\n");
    return 0;
}