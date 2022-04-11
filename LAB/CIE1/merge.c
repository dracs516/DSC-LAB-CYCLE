#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head1, *head2;

void createNode1(int n1)
{
    node *temp1;
    head1 = malloc(sizeof(node));
    if (head1 == NULL)
    {
        printf("Node Creation Failed... Try again...");
    }
    else
    {
        printf("Insert the data in the node 1 of list 1: ");
        scanf("%d", &head1->data);
        head1->next = NULL;
        temp1 = head1;
        if (n1 > 1)
        {
            node *newNode;
            for (int i = 2; i <= n1; i++)
            {
                newNode = malloc(sizeof(node));
                if (newNode == NULL)
                {
                    printf("Node Creation Failed... Try again...");
                }
                else
                {
                    printf("Insert the data in the node %d of list 1: ", i);
                    scanf("%d", &newNode->data);
                    temp1->next = newNode;
                    temp1 = temp1->next;
                    newNode->next = NULL;
                }
            }
        }
    }
}
void createNode2(int n2)
{
    node *temp2;
    head2 = malloc(sizeof(node));
    if (head2 == NULL)
    {
        printf("Node Creation Failed... Try again...");
    }
    else
    {
        printf("Insert the data in the node 1 of list 2 : ");
        scanf("%d", &head2->data);
        head2->next = NULL;
        temp2 = head2;
        if (n2 > 1)
        {
            node *newNode;
            for (int i = 2; i <= n2; i++)
            {
                newNode = malloc(sizeof(node));
                if (newNode == NULL)
                {
                    printf("Node Creation Failed... Try again...");
                }
                else
                {
                    printf("Insert the data in the node %d of list 2 : ", i);
                    scanf("%d", &newNode->data);
                    temp2->next = newNode;
                    temp2 = temp2->next;
                    newNode->next = NULL;
                }
            }
        }
    }
}

void display1()
{
    node *ptr1;
    ptr1 = head1;
    int i = 1;
    if (head1 == NULL)
    {
        printf("List not created\n");
    }
    while (ptr1 != NULL)
    {
        printf("Data at node %d of list 1 = %d", i, ptr1->data);
        printf("\n");
        i++;
        ptr1 = ptr1->next;
    }
}
void display2()
{
    node *ptr2;
    ptr2 = head2;
    int i = 1;
    if (head2 == NULL)
    {
        printf("List not created\n");
    }
    while (ptr2 != NULL)
    {
        printf("Data at node %d of list 2 = %d", i, ptr2->data);
        printf("\n");
        i++;
        ptr2 = ptr2->next;
    }
}

void sort1()
{
    node *start1, *end1;
    int temp1;
    start1 = head1;
    end1 = head1;
    while (start1 != NULL)
    {
        end1 = start1->next;
        while (end1 != NULL)
        {
            if (start1->data > end1->data)
            {
                temp1 = start1->data;
                start1->data = end1->data;
                end1->data = temp1;
            }
            end1 = end1->next;
        }
        start1 = start1->next;
    }
    printf("----------------------------------------------------------\n");
    printf("List Sorted Successfully\n");
    printf("----------------------------------------------------------\n");
}

void sort2()
{
    node *start2, *end2;
    int temp2;
    start2 = head2;
    end2 = head2;
    while (start2 != NULL)
    {
        end2 = start2->next;
        while (end2 != NULL)
        {
            if (start2->data > end2->data)
            {
                temp2 = start2->data;
                start2->data = end2->data;
                end2->data = temp2;
            }
            end2 = end2->next;
        }
        start2 = start2->next;
    }
    printf("----------------------------------------------------------\n");
    printf("List Sorted Successfully\n");
    printf("----------------------------------------------------------\n");
}

void merge()
{
    node *ptr1, *ptr2, *ran, *start;
    ptr1 = head1;
    ptr2 = head2;
    if (ptr1->data < ptr2->data)
    {
        ran = ptr1;
        head1 = head1->next;
        ptr1->next = ptr2;
        ptr1 = head1;
        start = ran;
    }
    else
    {
        ran = ptr2;
        head2 = head2->next;
        ptr2->next = ptr1;
        ptr2 = head2;
        start = ran;
    }
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (head1 == NULL)
        {
            break;
        }

        else if (head2 == NULL)
        {
            break;
        }
        if (ptr1->data > ptr2->data)
        {
            head2 = head2->next;
            ptr2->next = ptr1;
            ran->next = ptr2;
            ptr2 = head2;
            ran = ran->next;
        }
        else
        {
            head1 = head1->next;
            ptr1->next = ptr2;
            ran->next = ptr1;
            ptr1 = head1;
            ran = ran->next;
        }
    }

    node *print;
    print = start;
    int i = 1;
    if (start == NULL)
    {
        printf("List not created\n");
    }
    while (start != NULL)
    {
        printf("Data at node %d = %d", i, print->data);
        printf("\n");
        i++;
        print = print->next;
    }
}

int main()
{
    int n1, n2;
    printf("----------------------------------------------------------\n");
    printf("Enter the no. of nodes you want in the first list: ");
    scanf("%d", &n1);
    printf("----------------------------------------------------------\n");
    printf("----------------------------------------------------------\n");
    printf("Enter the no. of nodes you want in the second list: ");
    scanf("%d", &n2);

    if (n1 <= 0)
    {
        printf("No node created... Try again...");
    }
    else if (n1 > 0)
    {
        printf("----------------------------------------------------------\n");
        createNode1(n1);
        printf("----------------------------------------------------------\n");
    }
    printf("----------------------------------------------------------\n");

    if (n2 <= 0)
    {
        printf("No node created... Try again...");
    }
    else if (n2 > 0)
    {
        printf("----------------------------------------------------------\n");
        createNode2(n2);
        printf("----------------------------------------------------------\n");
    }
    printf("----------------------------------------------------------\n");

    display1();
    printf("----------------------------------------------------------\n");
    printf("----------------------------------------------------------\n");
    display2();

    sort1();
    sort2();

    printf("----------------------------------------------------------\n");
    printf("List 1 after sorting is: \n");
    display1();
    printf("----------------------------------------------------------\n");
    printf("List 2 after sorting is: \n");
    display2();
    printf("----------------------------------------------------------\n");

    printf("----------------------------------------------------------\n");
    printf("Merging... ... ... \n");
    merge();
    printf("----------------------------------------------------------\n");

    return 0;
}