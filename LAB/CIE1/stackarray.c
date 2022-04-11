#include <stdio.h>
#include <string.h>
int stack[100], top, choice, value, i, n;

void push()
{
    if (top >= n - 1)
    {
        printf("stack overflow");
    }
    else
    {
        printf("Enter value in stack::: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
    }
}

void pop()
{
    if (top < 0)
    {
        printf("Stack underflow");
    }
    else
    {
        printf("The popped element is::: %d", stack[top]);
        top--;
    }
}

void display()
{
    if (top >= 0)
    {
        printf("The elements in the stack are:::\n");
        for (i = top; i >= 0; i--)
        {
            printf("\n%d", stack[i]);
        }
    }
    else
    {
        printf("\nStack empty");
    }
}

int main()
{
    top = -1;
    printf("Enter size: ");
    scanf("%d", &n);
    printf("\n1.Push\n2.Pop\n3.Display\n4.Exit");
    do
    {
        printf("Enter choice::::");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        default:
            printf("choose again\n");
            break;
        }
    } while (choice != 4);

    return 0;
}