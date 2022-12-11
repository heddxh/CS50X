// Declares a dictionary's functionality

// Ensure that, even though dictionary.c and speller.c `#include` this file, `clang` will only compile it once.
#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h> // Define type Bool (used to be within `cs50.h`)

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45

// Define the size of Alphabet for the data type `triw_node`
#define SIZE_OF_ALPHABET 26

// Prototypes
bool check(const char *word); // String and CANNOT change
unsigned int hash(const char *word);
bool load(const char *dictionary);
unsigned int size(void);
bool unload(void);

#endif // DICTIONARY_H
