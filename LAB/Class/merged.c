#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} ab;

void print(ab *a)
{
    while (a != NULL)
    {
        printf("%d \n", a->data);
        a = a->next;
    }
}

int main()
{
    int a;
    ab *head, *n, *temp;
    head = malloc(sizeof(ab));
    printf("enter the value at the header for the first list \n");
    scanf("%d", &head->data);
    head->next = NULL;
    printf("enter the total number of nodes you want after the first node\n");
    scanf("%d", &a);
    temp = head;
    for (int i = 1; i <= a; i++)
    {
        n = malloc(sizeof(ab));
        printf("enter the data you want to input for %d th node\n", i + 1);
        scanf("%d", &n->data);
        n->next = NULL;
        temp->next = n;
        temp = n;
    }
    temp = head;
    int b;
    ab *head1, *n1, *temp1, *ran, *start;
    head1 = malloc(sizeof(ab));
    printf("enter the value at the header for the first list \n");
    scanf("%d", &head1->data);
    head1->next = NULL;
    printf("enter the total number of nodes you want after the first node\n");
    scanf("%d", &b);
    temp1 = head1;
    for (int i = 1; i <= b; i++)
    {
        n1 = malloc(sizeof(ab));
        printf("enter the data you want to input for %d th node\n", i + 1);
        scanf("%d", &n1->data);
        n1->next = NULL;
        temp1->next = n1;
        temp1 = n1;
    }
    temp1 = head1;
    if (temp->data > temp1->data)
    {
        ran = head1;
        head1 = head1->next;
        temp1->next = temp;
        temp1 = head1;
        start = ran;
    }
    else
    {
        ran = head;
        head = head->next;
        temp->next = temp1;
        temp = head;
        start = ran;
    }
    for (int i = 0; i < 5; i++)
    {
        if (head == NULL)
            break;
        else if (head1 == NULL)
            break;
        if (head->data > head1->data)
        {
            head1 = head1->next;
            temp1->next = temp;
            ran->next = temp1;
            temp1 = head1;
            ran = ran->next;
        }
        else
        {
            head = head->next;
            temp->next = temp1;
            ran->next = temp;
            temp = head;
            ran = ran->next;
        }
    }
    print(start);
    return 0;
}