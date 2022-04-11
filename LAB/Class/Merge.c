#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} ab;
void createnodelist(ab *head, *head1)
{
    int a, b;
    printf("enter the total number of nodes you want to insert in list 1 and list 2 respectively\n");
    scanf("%d %d", &a, &b);
    ab *n, *temp;
    head = malloc(sizeof(ab));
    head1 = malloc(sizeof(ab));
    printf("enter the value you want to enter at head1 and head respectively\n");
    scanf("%d %d", &head->data, &head1->data);
    head->next = NULL;
    head1->next = NULL;
    temp = head;
    temp1 = head1;
    for (int i = 1; i < a; i++)
    {
        n = malloc(sizeof(ab));
        printf("enter the %d th data you want to input in list 1\n", i + 1);
        scanf("%d", &n->data);
        n->next = NULL;
        temp->next = n;
        temp = n;
    }
    temp = head;
    for (int i = 1; i < b; i++)
    {
        n = malloc(sizeof(ab));
        printf("enter the %d th data you want to input in list 1\n", i + 1);
        scanf("%d", &n->data);
        n->next = NULL;
        temp1->next = n;
        temp1 = n;
    }
    temp1 = head1;
}
int main()
{
    ab *head, *head1, *dummy, *ran, *ran1;
    createnodelist(head, head1, temp, temp1);
    ran = head;
    ran1 = head;
    for (int i = 1; i <= b; i++)
    {
        dummy = malloc(sizeof(ab));
        if (temp1->data < temp->data)
        {
            dummy->next = temp1;
            dummy->data = temp1->data;
            temp1 = temp1->next;
        }
        else
        {
            dummy->next = temp;
            dummy->data = temp->data;
            temp = temp->next;
        }
    }
    while (dummy != NULL)
    {
        printf("%d\n", dummy->data);
        dummy = dummy->next;
    }
}