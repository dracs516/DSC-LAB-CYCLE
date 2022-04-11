#include <stdio.h>
#define size 5

int queue[size];
int f = -1;
int r = -1;

void enqueue()
{
    int data;
    if (r == size - 1)
    {
        printf("*************************************************************\n");
        printf("QUEUE IS FULL\n");
        printf("*************************************************************\n");
        return;
    }
    else
    {
        if (f == -1)
        {
            f++;
        }
        printf("Enter the data:");
        scanf("%d", &data);
        r++;
        queue[r] = data;
        printf("\n");
        printf("Inserted Data: %d", queue[r]);
        printf("\n");
    }
}

void dequeue()
{
    if (f == -1)
    {
        printf("*************************************************************\n");
        printf("QUEUE IS EMPTY\n");
        printf("*************************************************************\n");
        return;
    }
    else
    {
        if (r == -1)
        {
            printf("*************************************************************\n");
            printf("QUEUE IS EMPTY\n");
            printf("*************************************************************\n");
            return;
        }
        printf("Deleted element is: %d", queue[f]);
        printf("\n");
        for (int i = f; i < r; i++)
        {
            queue[i] = queue[i + 1];
        }
        r--;
    }
}

void display()
{
    if (r == -1)
    {
        printf("*************************************************************\n");
        printf("QUEUE IS EMPTY\n");
        printf("*************************************************************\n");
    }
    else
    {
        printf("Queue is:::\n");
        for (int i = f; i <= r; i++)
        {
            printf("%d", queue[i]);
            printf("\n");
        }
    }
}

void menu()
{
    int option;
    printf("-------------------------------------------------------------\n");
    printf("Choose an option:\n1.Insert data\n2.Delete data\n3.Display queue\n4.Exit\n");
    printf("-------------------------------------------------------------\n");
    scanf("%d", &option);
    printf("-------------------------------------------------------------\n");
    switch (option)
    {
    case 1:
        enqueue();
        menu();
        break;

    case 2:
        dequeue();
        menu();
        break;

    case 3:
        display();
        menu();
        break;

    case 4:
        return;
    default:
        break;
    }
}

int main()
{
    menu();
    return 0;
}