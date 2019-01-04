#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned int uint32_t;
typedef int int32_t;

#define MAX_KEY_SIZE        (256)
#define MAX_HASH_BUCKETS    (1024)

typedef enum {
    SUCCESS = 0,
    ERROR = 1,
} return_t;

typedef struct Node {
    char        key[MAX_KEY_SIZE];
    uint32_t    value;
    struct Node *next;
} node_t;

node_t * initialize_hash(uint32_t sizeofhash);

node_t *initialize_hash(uint32_t sizeofhash)
{
    node_t *hash = NULL;
    hash = (node_t*)malloc(sizeof(node_t)*sizeofhash);
    if(hash == NULL)
    {
        printf("Malloc for Hash table failed\n");
        return(NULL);
    }

    memset((void*)hash, 0, sizeof(node_t)*sizeofhash);

    printf("Hash of size %u is created @ %p. This consumes a total of %u Bytes of space\n",sizeofhash,hash,(uint32_t)(sizeof(node_t)*sizeofhash));
    return(hash);
}

//This function frees a hash table
return_t free_hash(node_t *hash)
{
    if(hash == NULL)
    {
        printf("No hash table to free \n ");
        return(ERROR);
    }
    free(hash);
    hash = NULL;
    return(SUCCESS);
}


uint32_t hash_key(char* key)
{
    uint32_t i = 0;
    uint32_t hashed_key = 0;

    for(i = 0;(key[i] != '\0') && (i < MAX_KEY_SIZE); i++)
    {
        hashed_key = hashed_key + (uint32_t)key[i];
    }
    hashed_key = hashed_key % MAX_HASH_BUCKETS;
    return(hashed_key);
}


return_t hash_add(node_t *hash, char *key, uint32_t value)
{
    uint32_t hashed_key = hash_key(key);
    printf("Hashed Key is %d\n",hashed_key);

    if(hash[hashed_key] == NULL)
    {
        node_t *newptr = (node_t*)malloc(sizeof(node_t));
        newptr->value = value;
        newptr->next = NULL;
        hash[hashed_key] = (node_t *)newptr;
    }
    else
    {
        node_t *bucket_ptr;
        while(bucket_ptr->next != NULL)
        {
            bucket_ptr = bucket_ptr->next;
        }
        node_t *newptr = (node_t*)malloc(sizeof(node_t));
        newptr->value = value;
        newptr->next = NULL;
        bucket_ptr->next = (node_t *)newptr;
    }

    return(SUCCESS);
}

int main(void)
{
    node_t *hash = NULL;
    hash = initialize_hash(MAX_HASH_BUCKETS);
    if(hash == NULL)
    {
        printf("Failed to Initialize the Hash table\n");
        return(ERROR);
    }

    char key[] = "ABCDEFGHIJKLMNOPQRSTABCDEFGHIJKLMNOPQRSTABCDEFGHIJKLMNOPQRST";
    uint32_t value = 33;

    hash_add(hash, key,value);

    if(free_hash(hash) != SUCCESS)
    {
        printf("Failed to Free Hash @ %p\n",hash);
        return(ERROR);
    }

    return(SUCCESS);
}
