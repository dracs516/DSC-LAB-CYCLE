#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} ab;

int main()
{
    int a, b;
    printf("Enter the total nodes in 1st link and 2nd link");
    scanf("%d%d", &a, &b);
    ab *head, *head1, *temp, *temp1, *n1, *n, *head2;
    printf("Enter th e value at head1\n");
    head = malloc(sizeof(ab));
    scanf("%d", &head->data);
    head->next = NULL;
    temp = head;
    for (int i = 1; i < a; i++)
    {
        n = malloc(sizeof(ab));
        printf("eneter the value at %dth node\n", i + 1);
        scanf("%d", &n->data);
        n->next = NULL;
        temp->next = n;
        temp = n;
    }
    temp = head;

    printf("Enter th e value at head2\n");
    head1 = malloc(sizeof(ab));
    scanf("%d", &head1->data);
    head1->next = NULL;
    temp1 = head1;
    for (int i = 1; i < a; i++)
    {
        n1 = malloc(sizeof(ab));
        printf("eneter the value at %dth node\n", i + 1);
        scanf("%d", &n1->data);
        n1->next = NULL;
        temp1->next = n1;
        temp1 = n1;
    }
    temp1 = head1;
    return 0;
}