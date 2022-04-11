#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev, *next;
} node;

node *head;
int node_num;

void createnode()
{
    printf("Enter no. of nodes you want: ");
    scanf("%d", &node_num);
    if (node_num <= 0)
    {
        printf("Insert valid number of nodes");
        return;
    }
    else
    {
        node *newnode, *temp;
        head = malloc(sizeof(node));
        if (head == NULL)
            printf("Node creation failed");
        else
        {
            printf("Insert data at node 1: ");
            scanf("%d", &head->data);
            head->prev = NULL;
            head->next = NULL;
            temp = head;
            if (node_num > 1)
            {
                for (int i = 2; i <= node_num; i++)
                {
                    newnode = malloc(sizeof(node));
                    if (newnode == NULL)
                        printf("Node creation failed");
                    else
                    {
                        printf("Insert data at node %d: ", i);
                        scanf("%d", &newnode->data);
                        newnode->next = NULL;
                        temp->next = newnode;
                        newnode->prev = temp;
                        temp = temp->next;
                    }
                }
            }
        }
    }
}

void display()
{
    node *print = head;
    int i = 1;
    while (print != NULL)
    {
        printf("Node %d: %d", i, print->data);
        printf("\n");
        print = print->next;
        i++;
    }
}

void displayreverse()
{
    // printf("Hello\n");
    node *printRev = head;
    int i = node_num;
    while (printRev->next != NULL)
    {
        printRev = printRev->next;
    }
    // printf("Hello\n");
    while (printRev != NULL)
    {
        printf("Node %d: %d", i, printRev->data);
        printf("\n");
        printRev = printRev->prev;
        i--;
    }
    // printf("Hello\n");
}

void menu()
{
    int n;
    printf("---------------------------------------------------------------------------\n");
    printf("Choose an option:\n1.Create Doubly linked list\n2.Display\n3.Display reverse\n4.End\n");
    printf("---------------------------------------------------------------------------\n");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        printf("---------------------------------------------------------------------------\n");
        createnode();
        printf("---------------------------------------------------------------------------\n");
        menu();
        printf("---------------------------------------------------------------------------\n");
        break;

    case 2:
        printf("---------------------------------------------------------------------------\n");
        display();
        printf("---------------------------------------------------------------------------\n");
        menu();
        printf("---------------------------------------------------------------------------\n");
        break;

    case 3:
        printf("---------------------------------------------------------------------------\n");
        displayreverse();
        printf("---------------------------------------------------------------------------\n");
        menu();
        printf("---------------------------------------------------------------------------\n");
        break;

    case 4:
        printf("---------------------------------------------------------------------------\n");
        return;

    default:
        printf("---------------------------------------------------------------------------\n");
        menu();
        printf("---------------------------------------------------------------------------\n");
        break;
    }
}

int main()
{
    menu();
    return 0;
}