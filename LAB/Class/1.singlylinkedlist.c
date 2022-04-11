#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void createnode(int n)
{
    // node *list = NULL;
    struct node *head, *newNode, *temp;
    if (n < 0)
    {
        printf("Linked List Not created as no. of nodes is less than 0.");
    }
    else
    {
        head = malloc(sizeof(node));
        if (head == NULL)
        {
            printf("Error in memory allocation.");
        }
        else
        {
            printf("Enter the data in node 1: ");
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

                    printf("Enter the data in node %d: ", i);
                    scanf("%d", &newNode->data);
                    temp->next = newNode;
                    temp = temp->next;
                }
            }
        }
    }
    printf("Data entered in the list is: \n");
    if (head == NULL)
    {
        printf("The list is empty.");
    }
    else
    {
        node *print;
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

int main()
{
    int n;
    printf("--------------------------------------\n");
    printf("Enter the no. of nodes you want: ");
    scanf("%d", &n);
    createnode(n);
    printf("\n");
    printf("--------------------------------------\n");
}