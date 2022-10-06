#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE");
        return 1;
    }

    const int BLOCK_SIZE = 512;
    FILE *file = fopen(argv[1], "r");
    while (fread(buffer, 1, BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    {

    }
}