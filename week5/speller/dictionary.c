// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH];
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

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hash = hash(word);
    table[hash]
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
    //FIXME: char *dict = malloc(sizeof(char));
    fread(dict, sizeof(char), 1, DICT);
    if (dict == NULL)
    {
        return false;
    }

    int c_index = 0; //每个单词第几个字母
    int word_index = 0; //第几个单词
    char *word;
    char *words[]; // 包含指针的数组,每个指针指向字符数组，即字符串
    while (isalpha(dict[c_index]))
    {
        words[c_index] = dict[c_index];
        word[]
        c_index++;
    }
    if (dict[c_index] == "\n")
    {
        words[word_index] = word;
        word_index++;

    }

    int index;
    for (int i = 0; i <= cnt; i++)
    {
        index = toupper(word[i]) - 'A';
        trie[hash]->

    }

}

// TODO:Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    int size = 0;
    while (word != NULL)
    {
        size++;
    }
    return size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO:
    return false;
}
