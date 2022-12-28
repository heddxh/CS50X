#include <stdio.h>

typedef struct node
{
    int a = 1;
} node;

int main(void)
{
    node *test = malloc(sizeof(node));
    printf("%i\n", test->a);
}