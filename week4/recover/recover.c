#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    const int BLOCK_SIZE = 512;

    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE");
        return 1;
    }

    FILE *raw_file = fopen(argv[1], "r");
    if (raw_file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    int *buffer =
    while (fread(buffer, 1, BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    {

    }
}