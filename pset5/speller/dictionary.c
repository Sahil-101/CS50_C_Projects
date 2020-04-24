// Implements a dictionary's functionality
#include<stdio.h>
#include <stdbool.h>
#include<strings.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1000;

// Hash table
node *table[N];

//making all the pointers in the hash table to NULL
void clean(unsigned int n, node *array[n])
{
    for(int i=0; i<N; i++)
    {
        table[i]=NULL;
    }
}
 


// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    node* temp=NULL;

    int index_ =hash(word);

    temp=table[index_];

    while(temp!=NULL)
    {
        if(strcasecmp(temp->word ,word))
        {
            return true;
        }
        else
        {
            temp=temp->next;
        }
    }

    return false;
}

// Hashes word to a number

/*The below hash function as offered by CS50
teachers is that it can be taken from internet
so i did to make it little bit fast modified slightly
but the idea is from below website all rights are reserved
to the author

https://cp-algorithms.com/string/string-hashing.html

*/

unsigned int hash(const char *word)
{
    // TODO
    int len=strlen(word);
    int p=23,m=7;
    int sum=0;
    for(int i=0; i<len; i++)
    {
        sum += (abs((int) word[i] - 96))*pow(p,i);
    }
    sum*=m;

    if(sum>1000)
    {
        sum=sum%1000;
    }

    return sum;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{   
    //TO DO

    //cleaning up garbage values
    clean(N,table);

    //opening file
    FILE *f=fopen(dictionary,"r");
    if(f==NULL)
    {
        return false;
    }

    //assigning temp string variable adn index variable and node* pointers
    char* word_=NULL;
    int index_;
    node *n=NULL, *n1=NULL;
    //reading word from dictionary to temp string variable
    //till EOF
    while(fscanf(f,"%s",word_)!=EOF)
    {
        //malloc gives new node memory if out of memory return 1
        n=malloc(sizeof(node));
        if(n==NULL)
        {
            return false;
        }

        //copying text to new node's word and assinging new node's next to NULL
        strcpy(n->word,word_);
        n->next=NULL;

        //getting index from hash function
        index_ =hash(word_);

        n1=table[index_];
        //if nothing present at table[index_] there then direct add else extend the list
        if(n1==NULL)
        {
                table[index_]=n;
        }
        else
        {
            n->next=table[index_]->next;
            table[index_]=n;           
        }

    }
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    
    node *temp;
    int count=0; 

    for(int i=0; i<N; i++)
    {
        temp=table[i]->next;

        while (temp!=NULL)
        {
            temp=temp->next;
            count++;
        }
    }

    return count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
