#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int a;
} node;

int main(void)
{
    node *test = NULL;
    test->a = 1;
    printf("%i\n", test->a);
}