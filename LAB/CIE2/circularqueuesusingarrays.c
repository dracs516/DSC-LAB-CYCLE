#include <stdio.h>
#define size 5

int queue[size];
int f = -1;
int r = -1;

void enqueue()
{
    int data;
    if ((r == size - 1 && f == 0) || (r == (f - 1) % (size - 1)))
    {
        printf("*************************************************************\n");
        printf("QUEUE IS FULL\n");
        printf("*************************************************************\n");
        return;
    }
    else if (r == size - 1 && f != 0)
    {
        if (f == -1)
        {
            f++;
        }
        printf("Enter the data:");
        scanf("%d", &data);
        r = (r + 1) % size;
        queue[r] = data;
        printf("\n");
        printf("Inserted Data: %d", queue[r]);
        printf("\n");
    }
    else
    {
        if (f == -1)
        {
            f++;
        }
        printf("Enter the data:");
        scanf("%d", &data);
        r = (r + 1) % size;
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
        f = (f + 1) % size;
    }
}

void display()
{
    if (f == -1)
    {
        printf("\nQueue is Empty");
        return;
    }
    printf("\nElements in Circular Queue are: \n");
    if (r >= f)
    {
        for (int i = f; i <= r; i++)
        {
            printf("%d ", queue[i]);
            printf("\n");
        }
    }
    else
    {
        for (int i = f; i < size; i++)
        {
            printf("%d ", queue[i]);
            printf("\n");
        }

        for (int i = 0; i <= r; i++)
        {
            printf("%d ", queue[i]);
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