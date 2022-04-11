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
    node *newnode;
    newnode = malloc(sizeof(node));
    {
        if (newnode == NULL)
        {
            printf("Node creation failed");
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
    // temp=head;
    head = head->next;
}

void display()
{
    node *print;
    print = head;
    printf("Queue is::: \n");
    while (print != NULL)
    {
        printf("%d", print->data);
        printf("\n");
        print = print->next;
    }
}

void menu()
{
    int n;
    printf("---------------------------------------------------------------------------\n");
    printf("Choose an option:\n1.Enter Data in Queue\n2.Delete item from beginning of Queue\n3.Display Queue\n4.End\n");
    printf("---------------------------------------------------------------------------\n");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        printf("---------------------------------------------------------------------------\n");
        if (head == NULL)
        {
            head = malloc(sizeof(node));
            if (head == NULL)
            {
                printf("Data Insertion failed");
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
            enqueue();
        }
        printf("---------------------------------------------------------------------------\n");
        menu();
        printf("---------------------------------------------------------------------------\n");
        break;

    case 2:
        printf("---------------------------------------------------------------------------\n");
        dequeue();
        printf("---------------------------------------------------------------------------\n");
        menu();
        printf("---------------------------------------------------------------------------\n");
        break;

    case 3:
        printf("---------------------------------------------------------------------------\n");
        display();
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