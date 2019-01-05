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

return_t initialize_hash(node_t ***hashptr, uint32_t sizeofhash);

return_t initialize_hash(node_t ***hashptr, uint32_t sizeofhash)
{
    /*
    Variable Hash is at location 0xffff1000 and it contains a value that is the
    address of the first Element of the array
    Hash is what is passed in to the function.

    Lets assume HashPtr is located at 0xFFFE0000.

    Suppose the Array is as shown below
        Address             Data
        0x50007000          1
        0x50007008          2
        0x50007010          3
        0x50007018          4

    So value at [0xFFFE0000] i.e. hashptr is going to be 0xffff1000
    [0xFFFE0000] -> 0xffff1000
    (address of Hash that is passed in. Hash is a pointer to array of pointers)
    We want Hash to contain the malloc'ed Value

    [0xffff1000] <- Malloced value

    so by doing a *hashptr we dereference the value conatined in 0xFFFE0000 which gives us
    *(0xffff1000) i.e. the address of the first element of the array
    */

    // Based on the logic above *hashptr will print the value conatined at address 0xffff1000
    printf("Function Hashptr allocated at %p\n",*hashptr);

    *hashptr = (node_t**)calloc(sizeofhash, sizeof(node_t*));
    printf("Hashptr allocated at %p\n",*hashptr);

    if(*hashptr == NULL)
    {
        printf("Malloc for Hash table failed\n");
        return(ERROR);
    }

    memset((void*)(*hashptr), 0, sizeofhash);

    printf("Hash of size %u is created @ %p. This consumes a total of %u Bytes \
    of space\n",sizeofhash,*hashptr,(uint32_t)(sizeofhash*sizeof(node_t*)));
    return(SUCCESS);
}

//This function frees a hash table
return_t free_hash(node_t ***hash, uint32_t hashlen)
{
    if(*hash == NULL)
    {
        printf("No hash table to free \n ");
        return(ERROR);
    }

    for(int i = 0;i<hashlen;i++)
    {
        node_t *traverse_ptr = NULL;
        traverse_ptr = *(*hash + i);
        if(traverse_ptr != NULL)
        {
            printf("Free LL at location %d\n",i);
            while(traverse_ptr->next != NULL)
            {
                printf("Free LL with value %d \n",traverse_ptr->value);
                node_t *temp_ptr = traverse_ptr->next;
                free(traverse_ptr);
                traverse_ptr = NULL;
                traverse_ptr = temp_ptr;
            }
            free(traverse_ptr);
            traverse_ptr = NULL;
        }
    }
    free(*hash);
    *hash = NULL;
    return(SUCCESS);
}


uint32_t hash_key(char* key)
{
    uint32_t i = 0;
    uint32_t hashed_key = 0;


    for(i = 0;(key[i] != '\0') && (i < MAX_KEY_SIZE); i++)
    {
        hashed_key = hashed_key + (uint32_t)key[0] + (uint32_t)key[i];
    }
    hashed_key = hashed_key % MAX_HASH_BUCKETS;
    return(hashed_key);
}


return_t hash_add(node_t ***hash, char *key, uint32_t value)
{
    //Get the hashed Key
    uint32_t hashed_key = hash_key(key);
    printf("PUT VALUE Hashed Key is %d\n",hashed_key);
    if(*(*hash + hashed_key) == NULL)
    {
        printf("New Node Added to Bucket %d\n",hashed_key);
        node_t *newptr = (node_t*)malloc(sizeof(node_t));
        memcpy((void*)newptr->key, (const void*)key, strlen(key)+1);
        newptr->value = value;
        newptr->next = NULL;
        *(*hash + hashed_key) = newptr;
    }
    else
    {
        printf("Collision Detected @ Bucket %d\n",hashed_key);
        node_t *traverse_ptr = NULL;
        traverse_ptr = *(*hash + hashed_key);
        while(traverse_ptr->next != NULL)
        {
            printf("key=%s, ptrkey=%s\n",key,traverse_ptr->key);

            if(memcmp((const void*)traverse_ptr->key,(const void*)key,strlen(key)) == 0)
            {
                printf("Found an entry with Duplicate key. Using that entry and replacing the original value\n");
                traverse_ptr->value = value;
                return(SUCCESS);
                break;
            }
            traverse_ptr = traverse_ptr->next;
        }
        node_t *newptr = (node_t*)malloc(sizeof(node_t));
        memcpy((void*)newptr->key, (const void*)key, strlen(key)+1);
        newptr->value = value;
        newptr->next = traverse_ptr->next;
        traverse_ptr->next = (node_t *)newptr;
    }

    return(SUCCESS);
}

return_t hash_get_value(node_t*** hashptr, char* key, uint32_t *value)
{
    //Get the hashed Key
    uint32_t hashed_key = hash_key(key);
    printf("\nGET VALUE Hashed Key is %d\n",hashed_key);

    if(*(*hashptr + hashed_key) == NULL)
    {
        printf("Error, No value at the requested Bucket. Key maps to NONE");
        return(ERROR);
    }
    else
    {
        node_t *traverse_ptr = NULL;
        traverse_ptr = *(*hashptr + hashed_key);
        while(traverse_ptr != NULL)
        {
            if(memcmp((const void*)key, (const void*)traverse_ptr->key, strlen(key)) == 0)
            {
                *value = traverse_ptr->value;
                return(SUCCESS);
            }
            traverse_ptr = traverse_ptr->next;
        }
        return(ERROR);
    }


}
int main(void)
{
    //Hash is a pointer to an arry of pointers of type node_t*


    node_t **hash = NULL;
    initialize_hash(&hash, MAX_HASH_BUCKETS);
    if(hash == NULL)
    {
        printf("Failed to Initialize the Hash table\n");
        return(ERROR);
    }
    else
    {
        printf("Successfully created hash at %p\n",hash);
    }

    hash = (node_t**)hash;

    char key1[] = "ABC";
    uint32_t value1 = 3;
    hash_add(&hash, key1, value1);

    char key2[] = "ACB";
    uint32_t value2 = 77;
    hash_add(&hash, key2, value2);

    char key3[] = "CBA";
    uint32_t value3 = 171;
    hash_add(&hash, key3, value3);
    value3 = 172;
    hash_add(&hash, key3, value3);
    value3 = 173;
    hash_add(&hash, key3, value3);

    uint32_t valx = 0;
    hash_get_value(&hash, key1, &valx);
    printf("Value found for key %s is %d\n",key1, valx);
    hash_get_value(&hash, key2, &valx);
    printf("Value found for key %s is %d\n",key2, valx);
    hash_get_value(&hash, key3, &valx);
    printf("Value found for key %s is %d\n",key3, valx);

    if(free_hash(&hash, MAX_HASH_BUCKETS) != SUCCESS)
    {
        printf("Failed to Free Hash @ %p\n",hash);
        return(ERROR);
    }

    return(SUCCESS);
}
