#include <stdio.h>

int main(void)
{
    char buffer[3];
    FILE *file = fopen("hi.txt", "r");
    /*while (fscanf(file, "%s", buffer) != EOF)
    {
        printf("%s\n", buffer);
    }*/
    fscanf(file, "%s", buffer);
    printf("%c %c %c %c\n", buffer[0], buffer[1], buffer[2], buffer[4]);
}
