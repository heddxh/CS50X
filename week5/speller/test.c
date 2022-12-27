#include <stdio.h>
#include <ctype.h>

int main(void)
{
    const char *word = "BAC";
    int a = toupper(word[0]) - "A";
    printf("%i\n", a);
}