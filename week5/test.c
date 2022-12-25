#include <stdio.h>

int main(void)
{
    char buffer;
    FILE *file = fopen("hi.txt", "r");
    while (fscanf(file, "%s", buffer) != EOF)
    {
        printf("%c\n", buffer);
    }
}
