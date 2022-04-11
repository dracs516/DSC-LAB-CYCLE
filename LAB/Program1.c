#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} * head;
void createList(int n);
void insertNodeAtEnd(int data);
void deleteFirstNode();
void displayList();
int main()
{
    int n, data;
    int option;
    printf("Enter the total number of nodes:\n ");
    scanf("%d", &n);
    createList(n);
    printf("Enter 1 to insert at the end and  2 delete in the beginning and -1 to exit.\n");
    scanf("%d", &option);
    int choice;
    while (option != -1)
    {
        switch (option)
        {
        case 1:

            printf("\nEnter data to insert at end of the list: ");
            scanf("%d", &data);
            insertNodeAtEnd(data);
            printf("\nData in the list \n");
            displayList();
            break;

        case 2:
            printf("\nPress 5 to delete first node: ");
            scanf("%d", &choice);
            if (choice == 5)
                deleteFirstNode();
            printf("\nData in the list \n");
            displayList();

            return 0;
            break;
        }
    }
}

void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        printf("Enter the data of node 1: ");
        scanf("%d", &data);

        head->data = data;
        head->next = NULL;

        temp = head;
        for (i = 2; i <= n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            if (newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);

                newNode->data = data; // Link data field of newNode with data
                newNode->next = NULL; // Link address field of newNode with NULL

                temp->next = newNode; // Link previous node i.e. temp to the newNode

                temp = temp->next;
            }
        }

        printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}

void insertNodeAtEnd(int data)
{
    struct node *newNode, *temp;

    newNode = (struct node *)malloc(sizeof(struct node));

    if (newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data;
        newNode->next = NULL;

        temp = head;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;

        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}
void deleteFirstNode()
{
    struct node *toDelete;

    if (head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = head;
        head = head->next;

        printf("\nData deleted = %d\n", toDelete->data);
        free(toDelete);

        printf("SUCCESSFULLY DELETED FIRST NODE FROM LIST\n");
    }
}

void displayList()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            printf("Data = %d\n", temp->data);
            temp = temp->next;
        }
    }
}