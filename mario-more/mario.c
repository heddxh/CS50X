#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h > 1); //ensure a valid input

    for (int i = 1, i < h + 1, i++)
    {
        for (int j = 1, j < h - i + 1, j++)
        {
            printf(" ");
        }

        for (int k = 1, k < i + 1, k++)
        {
            printf("#");
        }
    }
}