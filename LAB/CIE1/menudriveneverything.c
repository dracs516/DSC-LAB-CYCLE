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

void insert_beginning()
{
    node *newNode;
    newNode = malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Node Creation failes... Try again... ");
    }
    else
    {
        printf("Insert the data to be added in the node: ");
        scanf("%d", &newNode->data);
        newNode->next = head;
        head = newNode;
    }
    printf("----------------------------------------------------------\n");
    printf("Node Inserted Successfully\n");
    printf("----------------------------------------------------------\n");
}

void insert_end()
{
    node *newNode, *temp;
    temp = head;
    newNode = malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Node Creation failes... Try again... ");
    }
    else
    {
        printf("Insert the data to be added in the node: ");
        scanf("%d", &newNode->data);
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
    }
    printf("----------------------------------------------------------\n");
    printf("Node Inserted Successfully\n");
    printf("----------------------------------------------------------\n");
}

void insert_pos()
{
    node *newNode, *temp;
    temp = head;
    int posn;
    printf("Insert the position in which you want to insert the data: ");
    scanf("%d", &posn);
    printf("Insert the data you want in that position of the list: ");
    scanf("%d", &newNode->data);
    if (posn > 1)
    {
        for (int i = 1; i < posn - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    else if (posn == 1)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        printf("----------------------------------------------------------\n");
        printf("Not a valid position\n");
        printf("----------------------------------------------------------\n");
    }
    printf("----------------------------------------------------------\n");
    printf("Node Inserted Successfully\n");
    printf("----------------------------------------------------------\n");
}

void insert_after()
{
    node *temp, *put, *com;
    temp = head;
    com = malloc(sizeof(node));
    put = malloc(sizeof(node));
    printf("Enter after which data do you want to insert a node: ");
    scanf("%d", &com->data);
    printf("Enter the data at that node: ");
    scanf("%d", &put->data);
    if (temp->data == com->data)
    {
        put->next = temp->next;
        head->next = put;
    }
    while (temp->next->data != com->data)
    {
        temp = temp->next;
    }
    put->next = temp->next->next;
    temp->next->next = put;
    printf("----------------------------------------------------------\n");
    printf("Node Inserted Successfully\n");
    printf("----------------------------------------------------------\n");
}
void insert_before()
{
    node *temp, *put, *com;
    temp = head;
    com = malloc(sizeof(node));
    put = malloc(sizeof(node));
    printf("Enter before which data do you want to insert a node: ");
    scanf("%d", &com->data);
    printf("Enter the data at that node: ");
    scanf("%d", &put->data);
    if (temp->data == com->data)
    {
        put->next = temp->next;
        head->next = put;
    }
    while (temp->next->data != com->data)
    {
        temp = temp->next;
    }
    put->next = temp->next;
    temp->next = put;
    printf("----------------------------------------------------------\n");
    printf("Node Inserted Successfully\n");
    printf("----------------------------------------------------------\n");
}

void delete_beginning()
{
    head = head->next;
    printf("----------------------------------------------------------\n");
    printf("Node Deleted Successfully\n");
    printf("----------------------------------------------------------\n");
}

void delete_end()
{
    node *temp, *temp2;
    temp = head;
    if (temp->next == NULL)
    {
        temp->next = NULL;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
            // temp2 = temp;
        }
        // temp2->next = NULL;
        temp->next = NULL;
        printf("----------------------------------------------------------\n");
        printf("Node Deleted Successfully\n");
        printf("----------------------------------------------------------\n");
    }
}

void delete_pos()
{
    node *temp, *temp2;
    temp = head;
    temp2 = head;
    int posn;
    printf("Insert the position in which you want to delete the data: ");
    scanf("%d", &posn);
    if (posn > 1)
    {
        for (int i = 1; i < posn - 1; i++)
        {
            temp = temp->next;
            temp2 = temp;
        }
        temp = temp->next->next;
        temp2->next = temp;
        // temp->next = newNode;
    }
    else if (posn == 1)
    {
        head = NULL;
    }
    else
    {
        printf("----------------------------------------------------------\n");
        printf("Not a valid position\n");
        printf("----------------------------------------------------------\n");
    }
    printf("----------------------------------------------------------\n");
    printf("Node Inserted Successfully\n");
    printf("----------------------------------------------------------\n");
}

void delete_after()
{
    node *temp, *com, *temp2;
    temp = head;
    temp2 = head;
    com = malloc(sizeof(node));
    printf("Enter after which data do you want to delete a node: ");
    scanf("%d", &com->data);
    if (temp->data == com->data)
    {
        head = head->next;
    }
    while (temp->next->data != com->data)
    {
        temp = temp->next;
    }
    temp = temp->next;
    temp2 = temp->next;
    temp->next = temp2->next;
    temp2->next = NULL;
    free(temp2);
    printf("----------------------------------------------------------\n");
    printf("Node Inserted Successfully\n");
    printf("----------------------------------------------------------\n");
}

void delete_before()
{
    node *temp, *com, *temp2;
    temp = head;
    temp2 = head;
    com = malloc(sizeof(node));
    printf("Enter before which data do you want to delete a node: ");
    scanf("%d", &com->data);
    if (temp->data == com->data)
    {
        head = head->next;
    }
    if (temp->next->data == com->data)
    {
        temp2 = temp2->next->next;
        temp->next = temp2;
    }
    while (temp->next->next->data != com->data)
    {
        temp = temp->next;
        temp2 = temp2->next;
    }
    temp = temp->next->next;
    temp2->next = temp;
    // temp->next = temp2->next;
    // temp2->next = NULL;
    // free(temp2);
    printf("----------------------------------------------------------\n");
    printf("Node Deleted Successfully\n");
    printf("----------------------------------------------------------\n");
}

void sort()
{
    node *start, *end;
    int temp;
    start = head;
    end = head;
    while (start != NULL)
    {
        end = start->next;
        while (end != NULL)
        {
            if (start->data > end->data)
            {
                temp = start->data;
                start->data = end->data;
                end->data = temp;
            }
            end = end->next;
        }
        start = start->next;
    }
    printf("----------------------------------------------------------\n");
    printf("List Sorted Successfully\n");
    printf("----------------------------------------------------------\n");
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

void menu()
{
    int op, n;
    printf("----------------------------------------------------------\n");
    printf("Choose the option\n1.Create n nodes\n2.Insert node at the beginning\n3.Insert node at the end\n4.Insert at a position x\n5.Insert after a particular data\n6.Insert before a particular node\n7.Delete at the beginning\n8.Delete at the end\n9.Delete at a position x\n10.Delete after a particular node\n11.Delete before a particular node\n12.Sort the list\n13.Display the list\n14.End\n");
    printf("----------------------------------------------------------\n");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
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
            menu();
        }
        break;
    case 2:
        printf("----------------------------------------------------------\n");
        insert_beginning();
        menu();
        printf("----------------------------------------------------------\n");
        break;
    case 3:
        printf("----------------------------------------------------------\n");
        insert_end();
        menu();
        printf("----------------------------------------------------------\n");
        break;
    case 4:
        printf("----------------------------------------------------------\n");
        insert_pos();
        menu();
        printf("----------------------------------------------------------\n");
        break;
    case 5:
        printf("----------------------------------------------------------\n");
        insert_after();
        menu();
        printf("----------------------------------------------------------\n");
        break;
    case 6:
        printf("----------------------------------------------------------\n");
        insert_before();
        menu();
        printf("----------------------------------------------------------\n");
        break;
    case 7:
        printf("----------------------------------------------------------\n");
        delete_beginning();
        menu();
        printf("----------------------------------------------------------\n");
        break;
    case 8:
        printf("----------------------------------------------------------\n");
        delete_end();
        menu();
        printf("----------------------------------------------------------\n");
        break;
    case 9:
        printf("----------------------------------------------------------\n");
        delete_pos();
        menu();
        printf("----------------------------------------------------------\n");
        break;
    case 10:
        printf("----------------------------------------------------------\n");
        delete_after();
        menu();
        printf("----------------------------------------------------------\n");
        break;
    case 11:
        printf("----------------------------------------------------------\n");
        delete_before();
        menu();
        printf("----------------------------------------------------------\n");
        break;
    case 12:
        printf("----------------------------------------------------------\n");
        sort();
        menu();
        printf("----------------------------------------------------------\n");
        break;
    case 13:
        printf("----------------------------------------------------------\n");
        display();
        printf("----------------------------------------------------------\n");
        menu();
        break;
    case 14:
        printf("Thank you!!!\n");
        break;
    default:
        printf("Not a Valid Option... Choose again...\n");
        menu();
        break;
    }
}

int main()
{
    menu();
    return 0;
}