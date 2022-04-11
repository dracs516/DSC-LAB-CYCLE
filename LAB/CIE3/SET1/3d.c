// Design a Linear Doubly Linked List to store characters in each node. Write a C program which reads two strings from the user and creates two DLL respectively. Include a routine compare ( ), which works similar to strcmp i.e., returns 0 if both strings are same, returns 1 if first string is alphabetically greater or returns -1 if the second string is alphabetically greater.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char data;
    struct node *prev, *next;
} node;

node *list1, *list2;

node *createList()
{
    node *head;
    head = malloc(sizeof(node));
    if (head == NULL)
    {
        printf("Fail khayo");
        return 0;
    }
    else
    {
        head->next = NULL;
        head->prev = NULL;
    }
    return head;
}

void insertChar(node *list, char data)
{
    if (list == NULL)
        list = createList();
    else
        list->data = data;
}

void compare(node *head1, node *head2)
{
    while (head1->next != NULL && head2->next != NULL)
    {
        if (head1->data < head2->data)
        {
            printf("String 2 greater: -1\n");
            return;
        }
        if (head1->data > head2->data)
        {
            printf("String 1 greater: 1\n");
            return;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    printf("Equal: 0\n");
}

int main()
{
    char a[50], b[50];
    printf("Enter the 1st string: ");
    scanf("%s", a);
    printf("Enter the 2nd string: ");
    scanf("%s", b);

    list1 = createList();
    list2 = createList();

    node *temp1, *temp2;
    temp1 = list1;
    temp2 = list2;

    for (int i = 0; i < strlen(a); i++)
    {
        insertChar(temp1, a[i]);
        temp1->next = createList();
        temp1->next->prev = temp1;
        temp1 = temp1->next;
    }
    for (int i = 0; i < strlen(b); i++)
    {
        insertChar(temp2, b[i]);
        temp2->next = createList();
        temp2->next->prev = temp2;
        temp2 = temp2->next;
    }

    compare(list1, list2);
    return 0;
}