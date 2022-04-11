#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head1;
node *head2;

void createNode1(int n)
{
    node *temp;
    node *newNode;

    head1 = malloc(sizeof(node));
    if (head1 == NULL)
    {
        printf("Error in node creation");
    }
    else
    {
        if (n > 0)
        {
            printf("Insert data in the node 1 of list 1: ");
            scanf("%d", &head1->data);
            head1->next = NULL;

            temp = head1;

            for (int i = 2; i <= n; i++)
            {
                newNode = malloc(sizeof(node));
                if (newNode == NULL)
                {
                    printf("Node creation failed");
                }
                else
                {
                    printf("Insert data in the node %d of list 1: ", i);
                    scanf("%d", &newNode->data);
                    temp->next = newNode;
                    temp = temp->next;
                }
            }
        }
        else
        {
            printf("Error in list creation.");
        }
    }
}

void createNode2(int n)
{
    node *temp;
    node *newNode;

    head2 = malloc(sizeof(node));
    if (head2 == NULL)
    {
        printf("Error in node creation");
    }
    else
    {
        if (n > 0)
        {
            printf("Insert data in the node 1 of list 2: ");
            scanf("%d", &head2->data);
            head2->next = NULL;

            temp = head2;

            for (int i = 2; i <= n; i++)
            {
                newNode = malloc(sizeof(node));
                if (newNode == NULL)
                {
                    printf("Node creation failed");
                }
                else
                {
                    printf("Insert data in the node %d of list 2: ", i);
                    scanf("%d", &newNode->data);
                    temp->next = newNode;
                    temp = temp->next;
                }
            }
        }
        else
        {
            printf("Error in list creation.");
        }
    }
}

void sort1()
{
    node *start = head1;
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
    printf("List 1 is sorted successfully.\n");
    printf("------------------------------------------\n");
}

void sort2()
{
    node *start = head2;
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
    printf("List 2 is sorted successfully.\n");
    printf("------------------------------------------\n");
}

void display1()
{
    node *print = head1;
    if (head1 == NULL)
    {
        printf("List is empty");
    }
    else
    {
        print = head1;
        int i = 1;
        while (print != NULL)
        {
            printf("Data in node %d of list 1 = %d", i, print->data);
            printf("\n");
            print = print->next;
            i++;
        }
    }
}

void display2()
{
    node *print = head2;
    if (head2 == NULL)
    {
        printf("List is empty");
    }
    else
    {
        print = head2;
        int i = 1;
        while (print != NULL)
        {
            printf("Data in node %d of list 2 = %d", i, print->data);
            printf("\n");
            print = print->next;
            i++;
        }
    }
}

void merge(int n1, int n2)
{
    node *ptr1;
    node *ptr2;
    node *ran;
    node *start;

    ptr1 = head1;
    ptr2 = head2;

    // while (ptr1->next != NULL && ptr2->next != NULL) // for (int i = 1; i <= max(n1, n2); i++) //n1*n2

    if (ptr1->data < ptr2->data)
    {
        ran = head1;
        head1 = head1->next;
        ptr1->next = ptr2;
        ptr1 = head1;
        start = ran;
    }
    else
    {

        ran = head2;
        head2 = head2->next;
        ptr2->next = ptr2;
        ptr2 = head2;
        start = ran;
    }
    // for (int i = 0; i <= 10; i++)
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
    int i = 1;
    while (start != NULL)
    {
        printf("Merged List Data %d = %d", i, start->data);
        printf("\n");
        start = start->next;
        i++;
    }

    //one possible way:::
    // node *endptr;
    // endptr = head1;

    // while (endptr->next != NULL)
    // {
    //     endptr = endptr->next;
    // }
    // endptr->next = head2;
    // // endptr = newNode;

    // // head1->next = head2;
    // sort1();
    // display1();
    /*



    


    */
    //failed way:::
    // ptr1 = head1;
    // ptr2 = head2;
    // while (ptr1->next != NULL || ptr2->next != NULL)
    // {
    //     if (ptr1->data < ptr2->data)
    //     {
    //         ptr1 = ptr1->next;
    //         ptr1->next = ptr2;
    //     }
    //     if (ptr1->data > ptr2->data)
    //     {
    //         ptr2 = ptr2->next;
    //         ptr2->next = ptr1;
    //     }
    //     ptr1->next = NULL;
    //     ptr2->next = NULL;
    // }
    // int i = 1;
    // node *print = ptr1;
    // while (print != NULL)
    // {
    //     printf("Node %d data = %d", i, print->data);
    //     printf("\n");
    //     print = print->next;
    //     i++;
    // }
}

int main()
{
    int n1, n2;

    printf("------------------------------------------\n");

    printf("Input the no. of nodes in list 1: ");
    scanf("%d", &n1);

    printf("------------------------------------------\n");

    printf("Input the no. of nodes in list 2: ");
    scanf("%d", &n2);

    printf("------------------------------------------\n");

    createNode1(n1);
    printf("------------------------------------------\n");
    createNode2(n2);

    printf("------------------------------------------\n");
    printf("The lists are now undergoing sorting process...Please Wait... ... ...\n");
    printf("------------------------------------------\n");
    sort1();
    sort2();
    printf("The lists after sorting is as follows: \n");

    printf("------------------------------------------\n");
    printf("List 1: \n");
    display1();
    printf("------------------------------------------\n");

    printf("list 2: \n");
    display2();
    printf("------------------------------------------\n");

    printf("The two lists are approaching Merging Process\n");
    printf("------------------------------------------\n");
    merge(n1, n2);
}