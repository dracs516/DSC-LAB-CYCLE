#include <stdio.h>

void toh(int n, char a, char b, char c)
{
    if (n > 0)
    {
        toh(n - 1, a, c, b);
        printf("%c ---> %c\n ", a, c);
        toh(n - 1, b, a, c);
    }
}
int main()
{
    printf("the steps required for the traversal of pegs from the tower of hanoi problem is :------------>\n");
    toh(4, 'a', 'b', 'c');
    return 0;
}