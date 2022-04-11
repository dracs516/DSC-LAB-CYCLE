#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head, *temp;

void enqueue()
{
    if (head == NULL)
    {
        head = malloc(sizeof(node));
        if (head == NULL)
        {
            printf("QUEUE INSERTION FAILED");
        }
        else
        {
            printf("Enter the data: ");
            scanf("%d", &head->data);
            head->next = NULL;
            temp = head;
        }
    }
    else
    {
        node *newnode;
        newnode = malloc(sizeof(node));
        if (newnode == NULL)
        {
            printf("QUEUE INSERTION FAILED");
        }
        else
        {
            printf("Enter the data: ");
            scanf("%d", &newnode->data);
            newnode->next = NULL;
            temp->next = newnode;
            temp = temp->next;
        }
    }
}

void dequeue()
{
    if (head == NULL)
    {
        printf("*************************************************************\n");
        printf("QUEUE IS EMPTY\n");
        printf("*************************************************************\n");
        return;
    }
    else
    {
        head = head->next;
    }
}

void display()
{
    node *print;
    print = head;
    printf("Queue is:::\n");
    while (print != NULL)
    {
        printf("%d", print->data);
        printf("\n");
        print = print->next;
    }
}

void menu()
{
    int option;
    printf("-------------------------------------------------------------\n");
    printf("Choose an option:\n1.Insert data\n2.Delete data\n3.Display queue\n4.Exit\n");
    printf("-------------------------------------------------------------\n");
    scanf("%d", &option);
    printf("-------------------------------------------------------------\n");
    switch (option)
    {
    case 1:
        enqueue();
        menu();
        break;

    case 2:
        dequeue();
        menu();
        break;

    case 3:
        display();
        menu();
        break;

    case 4:
        return;
    default:
        break;
    }
}

int main()
{
    menu();
    return 0;
}