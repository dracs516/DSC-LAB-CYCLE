#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *next;
} node;
node *top;

void push(int value)
{
    node *newNode;
    newNode = malloc(sizeof(node));
    newNode->data = value;
    if (top == NULL)
    {
        newNode->next = NULL;
    }
    else
    {
        newNode->next = top;
    }
    top = newNode;
}

void pop()
{
    if (top == NULL)
    {
        printf("Stack undeerflow\n");
    }
    else
    {
        node *temp;
        temp = top;
        printf("\nDeleted element is :::: %d", temp->data);
        top = temp->next;
    }
}

void display()
{
    node *print;
    print = top;
    if (top == NULL)
    {
        printf("\nStack empty\n");
    }
    else
    {
        while (print != NULL)
        {
            printf("%d", print->data);
            print = print->next;
        }
    }
}

int main()
{
    int choice, value;

    do
    {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the value to be insert: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\nPlease try again\n");
        }
    } while (choice != 4);
}