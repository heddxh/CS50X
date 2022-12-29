// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

/*typedef struct node
{
    bool is_word;
    struct node *children[SIZE_OF_ALPHABET];
}
node;
*/

// Choose number of buckets in hash table
const unsigned int N = SIZE_OF_ALPHABET;

node *table[N];

unsigned int count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hash_word = hash(word);
    if (table[hash_word] == NULL)
    {
        return false;
    }
    node *cursor = table[hash_word];
    while (strcasecmp(word, cursor->word) != 0)
    {
        cursor = cursor->next;
        if (cursor == NULL)
        {
            return false;
        }
    }
    return true;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int hash_word = toupper(word[0]) - 'A';
    return hash_word;
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
    char *dict_word = malloc(LENGTH + 1);
    // fread(dict, sizeof(char), 1, DICT);
    if (dict_word == NULL)
    {
        fclose(DICT);
        free(dict_word);
        return false;
    }

    while (fscanf(DICT, "%s", dict_word) != EOF)
    {
        node *word_node = malloc(sizeof(node));
        if (word_node == NULL)
        {
            fclose(DICT);
            free(dict_word);
            free(word_node);
            return false;
        }

        strcpy(word_node->word, dict_word);
        count++;
        word_node->next = table[hash(dict_word)];
        table[hash(dict_word)] = word_node;
    }

    fclose(DICT);
    free(dict_word);
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
    for (int i = 0; i < LENGTH + 1; i++)
    {
        if (table[i] != NULL)
        {
            node *cursor = table[i]->next;
            table[i]->next = NULL;
            while (cursor != NULL)
            {
                node *next_cursor = cursor->next;
                free(cursor);
                cursor = next_cursor;
            }
        }
    }
    return true;
}
