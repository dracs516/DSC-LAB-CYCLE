#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
} ab;
int ask()
{
    int a;
    printf("enter the number of nodes you want to enter in the program\n");
    scanf("%d", &a);
    return a;
}
void print(ab *l)
{
    int c = 1;
    while (l != NULL)
    {
        printf("the value at the %d th node is %d\n", c, l->data);
        l = l->link;
        c++;
    }
}
int main()
{
    int d;
    d = ask();
    char e, f;
    ab *head, *n, *temp, *newnode, *ran, *nnewnode;
    head = malloc(sizeof(ab));
    printf("enter the data you want to input in the first node \n");
    scanf("%d", &head->data);
    head->link = NULL;
    temp = head;

    for (int i = 0; i < (d - 1); i++)
    {
        n = malloc(sizeof(ab));
        printf("enter the value you want to enter at %d th node\n", i + 2);
        scanf("%d", &n->data);
        n->link = NULL;
        temp->link = n;
        temp = n;
    }
    fflush(stdin);
    printf("do you want a NEW new node ?\n");
    scanf("%c", &e);
    fflush(stdin);
    newnode = malloc(sizeof(ab));
    if (e == 'y' || e == 'Y')
    {
        printf("enter the data you want to input in your new node\n");
        scanf("%d", &newnode->data);
        newnode->link = NULL;

        fflush(stdin);
        printf("where do you want to input the new node \n");
        scanf("%c", &f);
        if (f == 'b' || f == 'B')
        {

            newnode->link = head;
            print(newnode);
        }

        else if (f == 'e' || f == 'E')
        {
            n->link = newnode;
            print(head);
        }
    }
    else
        print(head);
    //free(head);
    ///free(n);
    free(temp);

    //////ab *head,*newnode, *temp, ran;
    nnewnode->data = 6;
    nnewnode->link = NULL;
    temp = head;
    while (nnewnode->data <= temp->data && temp != NULL)
    {
        ran = temp;
        temp = temp->link;
    }
    nnewnode->link = temp;
    ran->link = nnewnode;

    return 0;
}