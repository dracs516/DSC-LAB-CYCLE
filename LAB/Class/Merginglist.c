#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} ab;
int main()
{
    int n1;
    ab *head1, *list1, *temp1, *dummy;
    head1 = malloc(sizeof(ab));
    printf("Enter the data in the node 1");
    scanf("%d", &head1->data);
    printf("Enter the no. of nodes you want for the first list");
    scanf("%d", &n1);
    head1->next = NULL;
    temp1 = head1;
    for (int i = 1; i <= n1; i++)
    {
        list1 = malloc(sizeof(ab));
        printf("Enter the value at the node %d", i + 1);
        scanf("%d", &list1->data);
        list1->next = NULL;
        temp1->next = list1;
        temp1 = list1;
    }
    temp1 = head1;
    int n2;
    ab *head2, *list2, *temp2;
    head2 = malloc(sizeof(ab));
    prinf("Enter the data in the node 1");
    scanf("%d", &head2->data);
    printf("Enter the no. of nodes you want for the second list");
    scanf("%d", n2);
    head2->next = NULL;
    temp2 = head2;
    for (int i = 1; i <= n2; i++)
    {
        list2 = malloc(sizeof(ab));
        printf("Enter the value at the node %d", i + 1);
        list2->next = NULL;
        temp2->next = list2;
        temp2 = list2;
    }
    temp2 = head2;
    void Merge();
}

void Merge()
{
}