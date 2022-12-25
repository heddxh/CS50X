#include <stdio.h>

int main(void)
{
    FILE *file = fopen("hi.txt", "r");
    while (fscanf(file, "%s", buffer) != EOF)
    {
        
    }
}
