#include <stdio.h>

int main(void)
{
    char buffer[3];
    FILE *file = fopen("hi.txt", "r");
    while (fscanf(file, "%s", buffer) != EOF)
    {
        printf("%s\n", buffer);
    }
}
