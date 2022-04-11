#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head;

void createNode(int n)
{
    node *temp, *newNode;
    head = malloc(sizeof(node));
    if (head == NULL)
    {
        printf("Error in memory allocation.");
    }
    else
    {
        if (n > 0)
        {
            printf("Insert the data in node 1: ");
            scanf("%d", &head->data);
            head->next = NULL;

            temp = head;
            for (int i = 2; i <= n; i++)
            {
                newNode = malloc(sizeof(node));
                if (newNode == NULL)
                {
                    printf("Error in memory allocation.");
                }
                else
                {
                    printf("Insert the data in node %d: ", i);
                    scanf("%d", &newNode->data);
                    temp->next = newNode;
                    temp = temp->next;
                }
            }
        }
        else
        {
            printf("Error in List Node Creation.");
        }
    }
}

void insert_beginning(int bn)
{
    node *newNode;
    newNode = malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("New node Insertion Failed");
    }
    else
    {
        newNode->data = bn;
        newNode->next = head;
        printf("Data is successfully entered in the list\n");
    }
    head = newNode;
}

void insert_end(int en)
{
    node *newNode, *endptr;
    endptr = head;

    newNode = malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("New Node Insertion Failed");
    }
    else
    {
        newNode->data = en;
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

void insert_pos(int posn, int pos)
{
    node *newNode = malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("New Node Insertion Failed");
    }
    else
    {
        newNode->data = posn;
        int i;
        node *temp = head;
        if (pos == 1)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            for (int i = 1; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

void remove_beginning()
{
    node *delete;
    delete = head;
    head = head->next;
    printf("%d is successfully deleted from the list.\n", delete->data);
}

void sort()
{
    node *start = head;
    node *end = NULL;
    int temp;
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
    printf("The List is successfully sorted.\n");
}

void insert_sorted()
{
    node *newNode;
    node *temp, *start, *end;
    temp = head;
    newNode = malloc(sizeof(node));

    if (newNode == NULL)
    {
        printf("New Node Insertion Failed");
    }
    else
    {
        printf("Insert the data for the new node: ");
        scanf("%d", &newNode->data);
    }

    if (newNode->data == temp->data)
    {
        newNode->next = head->next;
        head->next = newNode;
    }
    else
    {
        while (temp->next != NULL && newNode->data > temp->next->data)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void displaylist()
{
    // node *tmp;
    node *print = head;
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("Data in the list: \n");
        print = head;
        int i = 1;
        while (print != NULL)
        {
            printf("Node %d data = %d", i, print->data);
            printf("\n");
            print = print->next;
            i++;
        }
    }
}

void menu()
{

    int s, n;
    int bn, en, posn, pos;
    printf("-------------------------------------------\n");
    printf("Choose the option:\n1.Create n nodes\n2.Insert node at the beginning\n3.Insert at the end\n4.Insert node at a given position\n5.Delete at beginning\n6.Sort the list\n7.Insert node after sorting\n8.Display the list\n9.End\n");
    printf("-------------------------------------------\n");
    scanf("%d", &s);
    printf("-------------------------------------------\n");
    switch (s)
    {
    case 1:
        printf("Input the no. of nodes: ");
        scanf("%d", &n);
        createNode(n);
        menu();
        break;

    case 2:
        printf("Insert the data  to be added at the beginning: ");
        scanf("%d", &bn);
        insert_beginning(bn);
        menu();
        break;

    case 3:
        printf("Insert the data to be added at the end: ");
        scanf("%d", &en);
        insert_end(en);
        menu();
        break;

    case 4:
        printf("Insert the data to be added in the list: ");
        scanf("%d", &posn);
        printf("Insert the position in which you want to enter the data to the list: ");
        scanf("%d", &pos);
        insert_pos(posn, pos);
        menu();
        break;

    case 5:
        remove_beginning();
        menu();
        break;

    case 6:
        sort();
        menu();
        break;

    case 7:
        sort();
        insert_sorted();
        menu();
        break;

    case 8:
        displaylist();
        menu();
        break;

    case 9:
        printf("Thank you!!!\n");
        printf("-------------------------------------------\n");
        break;

    default:
        printf("Not a valid option.");
        menu();
        break;
    }
}

int main()
{
    menu();
}