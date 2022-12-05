// Declares a dictionary's functionality

// Ensure that, even though dictionary.c and speller.c `#include` this file, `clang` will only compile it once.
#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h> // Define type Bool (used to be within `cs50.h`)

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45

// Prototypes
bool check(const char *word); // String
unsigned int hash(const char *word); // String
bool load(const char *dictionary); // String
unsigned int size(void);
bool unload(void);

#endif // DICTIONARY_H
