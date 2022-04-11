#include <stdio.h>

#define size 5

int arr[size];
int top = -1;

int isStackFull()
{
    if (top == size - 1)
        return 1;
    return 0;
}

void push(int val)
{

    if (isStackFull())
        printf("Unable to push %d as the Stack Is Full\n", val);
    else
    {

        ++top;

        arr[top] = val;
    }
}

int isStackEmpty()
{
    if (top == -1)
        return 1;
    return 0;
}

void pop()
{

    if (isStackEmpty())
        printf("Stack Is Empty\n");
    else
    {

        printf("Popped element = %d\n", arr[top]);

        top--;
    }
}

int main()
{
    push(15);
    push(19);
    push(9);
    push(27);
    push(97);
    push(69);
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    return 0;
}