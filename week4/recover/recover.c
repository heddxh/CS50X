#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

const int BLOCK_SIZE = 512;
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
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

    BYTE buffer[BLOCK_SIZE];
    char filename[8]; // 7 width and the NUL
    int cnt = 0;
    

    while (fread(&buffer, BLOCK_SIZE, 1, raw_file)) // When reach the end, return 0, jump out the loop
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0x0f) == 0xef)
        {
            sprintf(filename, "%03i.jpg", cnt);
            FILE *img = fopen(filename, "w");
            cnt++;
        }
        else
        {
            if (cnt > 0)
            {
                fwrite(*buffer, BLOCK_SIZE, 1, img);
            }
        }
    }
}