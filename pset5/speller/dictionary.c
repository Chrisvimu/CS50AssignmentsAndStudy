#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"

//I had to start using reddit and StackOverflow to check memory leaks and other problems, and while my solution seemed sound in paper
// It started to become an "internet" mashup while trying to debug it, I just hope this causes no problems in the future...

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;


// Number of buckets in hash table
const unsigned int N = 60000;

// Hash table
node *table[N];
int countOfWords = 0;


//declare empty head
node *head = NULL;


// Returns true if word is in dictionary
bool check(const char *word)
{
    int length = strlen(word);
    // take a byte extra for null character
    char copy[length + 1];
    copy[length] = '\0';

    for (int i = 0; i < length; i++)
    {
        copy[i] = tolower(word[i]);
    }

    int hashcode = hash(copy);
    node *tmp = table[hashcode];
    if (tmp == NULL)
    {
        return false;
    }

    while (tmp != NULL)
    {
        // checks for word in node to our temp word
        if (strcasecmp(tmp->word, copy) == 0)
        {
            return true;
        }

        tmp = tmp-> next;
    }

    return false;
}

//https://www.reddit.com/r/cs50/comments/1x6vc8/pset6_trie_vs_hashtable/
// Based on the hash used shown here: https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29
// In the 4.2, but adapted by me to fit here with some of reddit wisdom

unsigned int hash(const char *word)
{
    unsigned long hash = 5381;

    int c = *word;

    while (c == *word++)
    {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % N;
}


// Loads dictionary into memory
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    else
    {
        char buffer[LENGTH + 1];
        while (fscanf(file, "%s", buffer) != EOF)
        {
            node *n = malloc(sizeof(node));
            // check if memory is allocated
            if (n == NULL)
            {
                fclose(file);
                return false;
            }
            else
            {
                strcpy(n->word, buffer);
                n->next = NULL;
                unsigned int index = hash(buffer);
                n->next = table[index];
                table[index] = n;
                countOfWords++;
            }
        }
        fclose(file);
        return true;
    }
}


// Returns number of words in dictionary
unsigned int size(void)
{
    //added using word count
    return countOfWords;
}

// Unloads dictionary from memory
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *tmp1 = table[i];
        while (tmp1 != NULL)
        {
            node *tmp2 = tmp1;
            tmp1 = tmp1 -> next;
            free(tmp2);
        }
    }
    return true;
}