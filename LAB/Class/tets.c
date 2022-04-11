#include <stdio.h>
void ran(int *c)
{
    *c = 99;
}
int main()
{
    int c;
    ran(&c);
    printf("%d\n", c);
    return 0;
}