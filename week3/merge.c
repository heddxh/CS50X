#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int list[] = {2, 4, 5, 7, 0, 1, 3, 6};
    int n = 8;
    int a[n/2] = list[0:n/2];
    printf("i%\n", a);
}