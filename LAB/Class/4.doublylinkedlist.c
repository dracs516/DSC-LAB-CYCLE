#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev, *next;
} node;

node *head;

void createnode()
{
    printf("---------------------------------------------------------------------------\n");
    int n;
    printf("Enter the no. of nodes u want: ");
    scanf("%d", &n);
    printf("--------------------------------------------------------------------------\n");
    node *newnode, *temp;
    head = malloc(sizeof(node));
    if (head == NULL)
    {
        printf("Node creation failed");
    }
    else
    {
        printf("Enter the data in node 1: ");
        scanf("%d", &head->data);
        head->prev = NULL;
        head->next = NULL;
        temp = head;
        // temp->next = NULL;
        for (int i = 2; i <= n; i++)
        {
            newnode = malloc(sizeof(node));
            {
                if (newnode == NULL)
                {
                    printf("NOde creation failed");
                }
                else
                {
                    printf("Enter the data in node %d: ", i);
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

void display()
{
    node *print;
    print = head;
    int i = 1;
    while (print != NULL)
    {
        printf("Node %d= %d", i, print->data);
        printf("\n");
        print = print->next;
        i++;
    }
}

void displayreverse()
{
    node *print;
    int i = 5;
    print = head;
    while (print->next != NULL)
    {
        print = print->next;
    }
    // print = print->next;

    while (print != NULL)
    {
        printf("Node %d= %d", i, print->data);
        printf("\n");
        print = print->prev;
        i--;
    }
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