#include <stdio.h>
#define SIZE 5

int r = -1, f = -1;
int queue[SIZE];

void enqueue()
{
    int data;
    if (r == SIZE - 1)
    {
        printf("QUEUE IS FULL\n");
        return;
    }
    else
    {
        if (f == -1)
        {
            f = 0;
        }
        printf("Enter the data u want to enter: ");
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
        printf("QUEUE IS EMPTY\n");
        return;
    }
    // if (f == r == SIZE)
    // {
    //     printf("QUEUE IS EMPTY\n");
    //     return;
    // }
    else
    {
        printf("\n");
        printf("Deleted Data: %d", queue[f]);
        printf("\n");
        f++;
    }
}

void display()
{
    if (f == -1 || f == SIZE)
    {
        printf("Queue is empty \n");
    }
    else
    {
        printf("--------------------------------------------------------------------------\n");
        printf("Queue is :::: \n");

        for (int i = f; i <= r; i++)
        {
            printf("%d", queue[i]);
            printf("\n");
            // printf("--------------------------------------------------------------------------\n");
        }
    }
}

void menu()
{
    int n;
    printf("--------------------------------------------------------------------------\n");
    printf("Choose an option:\n1.Enter data in the Queue\n2.Delete item from beginning\n3.Display Queue\n4.End\n");
    printf("--------------------------------------------------------------------------\n");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        printf("---------------------------------------------------------------------------\n");
        enqueue();
        printf("---------------------------------------------------------------------------\n");
        menu();
        printf("---------------------------------------------------------------------------\n");
        break;

    case 2:
        printf("---------------------------------------------------------------------------\n");
        dequeue();
        printf("---------------------------------------------------------------------------\n");
        menu();
        printf("---------------------------------------------------------------------------\n");
        break;

    case 3:
        printf("---------------------------------------------------------------------------\n");
        display();
        printf("---------------------------------------------------------------------------\n");
        menu();
        printf("---------------------------------------------------------------------------\n");
        break;

    case 4:
        printf("---------------------------------------------------------------------------\n");
        return;

    default:
        printf("---------------------------------------------------------------------------\n");
        menu();
        printf("---------------------------------------------------------------------------\n");
        break;
    }
}

int main()
{
    menu();
}