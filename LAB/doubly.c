#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} ab;
ab *head, *n, *temp, *ran, *headptr;
int no;
void ask()
{
    printf("enter the total amount of nodes you want to insert :\n");
    scanf("%d", &no);
}
void insert()
{
    head = malloc(sizeof(ab));
    printf("enter the data you want to enter at the head\n");
    scanf("%d", &head->data);
    head->prev = NULL;
    head->next = NULL;
    temp = head;
    headptr = head;

    for (int i = 2; i <= no; i++)
    {
        n = malloc(sizeof(ab));
        printf("enter the data you want to input in the node %d\n", i);
        scanf("%d", &n->data);
        n->prev = temp;
        temp->next = n;
        n->next = NULL;
        temp = n;
    }
}
void insertbeg()
{
    ab *new;
    new = malloc(sizeof(ab));
    printf("enter the data you want to input in the beg\n");
    scanf("%d", &new->data);
    head->prev = new;
    new->next = head;
    head = new;
    head->prev = NULL;
    headptr = head;
    no++;
}
void insertend()
{
    ab *new;
    new = malloc(sizeof(ab));
    printf("enter the data you want to input in the end\n");
    scanf("%d", &new->data);
    temp->next = new;
    new->prev = temp;
    temp = new;
    temp->next = NULL;
    no++;
}
void insertatrandom()
{
    int a;
    printf("at which position do you want to insert the new node that you have created\n");
    scanf("%d", &a);
    int b = a;
    ab *new;
    new = malloc(sizeof(ab));
    printf("enter the data you want to input in the newnode\n");
    scanf("%d", &new->data);
    for (int i = 1; i <= a && b < no; i++)
    {
        if (i != (a - 1))
        {

            headptr = headptr->next;
        }
        else if (i == (a - 1))
        {

            new->next = headptr->next;
            new->prev = headptr;
            headptr->next = new;
            headptr = head;
            break;
        }
    }
}
void print()
{
    while (headptr->next != NULL)
    {
        printf("%d->", headptr->data);
        headptr = headptr->next;
    }
    printf("%d\n", headptr->data);
    headptr = head;
}
void delrandom(){
    ab *prevnode,*nextnode;
    int del;
    printf("enter the position of the node you want to delete\n");
    scanf("%d",&del);
    //the del position must be less than the node number-->no
    int lolo=1;
    while(lolo!=del){
        prevnode=headptr;
        headptr=headptr->next;
        nextnode=headptr->next;
        lolo++;

    }
    prevnode->next=nextnode;
    headptr->prev=NULL;
    nextnode->prev=prevnode;
    headptr->next=NULL;
    headptr=head;

}
int main()
{
    ask();
    insert();
    insertbeg();
    print();
    insertend();
    print();
    insertatrandom();
    print();
    delrandom();
    print();
    free(headptr);
    // free(temp);
    // free(head);

    return 0;
}
