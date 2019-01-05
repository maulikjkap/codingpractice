#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned int uint32_t;
typedef int int32_t;

typedef struct tp {
    int val;
    int val1;
} test_t;


void create_array_of_struct_pointers(test_t ***arr)
{
    // arr conatins 0x7ffeef8b6ac0
    printf("MemAllocation\n");
    printf("Function Array of pointers varaible conatins %p\n",arr);
    printf("Function Array of pointers varaible conatins %p\n",*arr);

    *arr = (test_t**)calloc(4, sizeof(uint32_t*));
    printf("Function Array of Pointer is at location = %p\n",(*arr + 0));//(*arr + 0));
    printf("Function Array of Pointer is at location = %p\n",(*arr + 1));
    printf("Function Array of Pointer is at location = %p\n",(*arr + 2));
    printf("Function Array of Pointer is at location = %p\n",(*arr + 3));
}

int main(void)
{
    // This is an pointer to an array of pointers hence the **
    test_t** arr_of_ptr = NULL;
    printf("Array of pointers varaible is at %p\n",&arr_of_ptr);
    printf("Array of pointers varaible conatins %p\n",arr_of_ptr);

    create_array_of_struct_pointers(&arr_of_ptr);
    //arr_of_ptr = (test_t**)calloc(4, sizeof(test_t*));

    printf("Main Array of pointers varaible conatins %p\n",arr_of_ptr);
    printf("Main Array of Pointer is at location = %p\n",&arr_of_ptr[0]);
    printf("Main Array of Pointer is at location = %p\n",&arr_of_ptr[1]);
    printf("Main Array of Pointer is at location = %p\n",&arr_of_ptr[2]);
    printf("Main Array of Pointer is at location = %p\n",&arr_of_ptr[3]);

    for(int i =0;i<4;i++)
    {
        printf("Value of Pointer %d before allocation\t\t=%p\n",i,arr_of_ptr[i]);
        arr_of_ptr[i] = (test_t*)malloc(1*sizeof(test_t));
        printf("Value of Pointer %d after  allocation\t\t=%p\n",i,arr_of_ptr[i]);
    }

    for(int i =0;i<4;i++)
    {
        free(arr_of_ptr[i]);
        printf("Value of Pointer %d After Free       \t\t=%p\n",i,arr_of_ptr[i]);
        arr_of_ptr[i] = NULL;
        printf("Value of Pointer %d After Free/Null  \t\t=%p\n",i,arr_of_ptr[i]);
    }
    return(0);
}
