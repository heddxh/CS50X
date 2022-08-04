#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_words(string text);

int main(void)
{
    string text = get_string("Text: ");
    printf("count words: %c\n", count_words(text));

}

int count_words(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]) != 0)
        {
            count++;
        }
    }
    return count;
}