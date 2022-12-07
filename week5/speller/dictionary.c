// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    // char word[LENGTH + 1];
    char word;
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26 * LENGTH;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO:
    int hash = hash(word);
    int len = 
    for (int i = 0; i < )
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int i = 0;
    int hash;
    while (word[i] != NULL)
    {
        hash = hash * 10 + toupper(word[i]) - 'A';
        i++;
    }
    return hash;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO:
    FILE *DICT = fopen(dictionary, "r");
    node *dict = malloc(sizeof(node));
    fread(dict, sizeof(node), , DICT);
    fread()
    if (dict == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO:
    int size = 0;

    while (word != NULL)
    {
        size++;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO:
    return false;
}
