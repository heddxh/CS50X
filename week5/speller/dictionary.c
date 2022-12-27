// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char *word[LENGTH+1];
    struct node *next;
}
node;


/*typedef struct node
{
    bool is_word;
    struct node *children[SIZE_OF_ALPHABET];
}
node;
*/

// Choose number of buckets in hash table
const unsigned int N = SIZE_OF_ALPHABET;

node *taleb[N];

unsigned int count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hash = hash(word);
    if (scrcasecmp(word, table[hash]->word) == 0)
    {
        return true;
    }
    else if (strcasecmp(word, table[hash]->next->word) == 1)
    {
        return true;
    }
    else 
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int hash;
    hash = int(toupper(word[0]) - "A");
    return hash;
}

/*
void unhash(const char *word)
{
    int index[];
    int len = strlen(word);
    int i = 1;
    // 注意余数26整除为0时，我们应该得到25
    while (hash > 0)
    {
        index[len - i] = hash - hash / SIZE_OF_ALPHABET;
        hash = hash / SIZE_OF_ALPHABET;
        if (index[len - i] == 0)
        {
            index[len - i] = 25
        }
        i++;
    }
}
*/

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *DICT = fopen(dictionary, "r");
    char *dict_word = malloc(sizeof(LENGTH + 1));
    // fread(dict, sizeof(char), 1, DICT);
    if (dict == NULL)
    {
        return false;
    }

    while (fscanf(DICT, "%s", dict_word) != EOF)
    {
        node *word_node;
        if (word_node == NULL)
        {
            return false;
        }

        strcpy(word_node->word, dict_word);
        count++;
        word_node->next = table[hash(dict_word)]->next;
        table[hash(dict_word)] = word_node;
    }
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    int size = 0;
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    free(dict_word);
    return true;
}
