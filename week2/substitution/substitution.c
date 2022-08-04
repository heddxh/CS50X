#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_string_alpha(string s);
int is_string_(string s);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    else if ()
    }

    string raw = get_string("plaintext: ");
    string key = argv[1];
    string cip = raw;
    for (int i = 0, n = strlen(raw); i < n; i++)
    {
        if (isalpha(raw[i]))
        {
            if(islower(raw[i]))
            {
                int index = raw[i] - 97;
                cip[i] = tolower(key[index]);
            }
            else
            {
                int index = raw[i] - 65;
                cip[i] = toupper(key[index]);
            }
        }
        else
        {
            cip[i] = raw[i];
        }
    }

    printf("ciphertext: %s\n", cip);
}

int is_string_alpha(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isalpha(s[i]) == 0)
        {
            return 1;
        }
    }
}