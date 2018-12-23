#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef enum {
    SORT_SUCCESS = 0,
    SORT_ERROR = 1,
    SORT_ERROR__INVALID_PARAM = 2,
} ret_value_t;

ret_value_t bubble_sort_algo(int* arr, int n);
__inline__ static void swap(int* a, int* b);
void printarr(int* arr, int n);

int main(void)
{
    printf("\nTEST 1\n");
    int arr[10] = {8,5,4,3,22,9,12,333,7,88};
    printarr(arr, sizeof(arr)/sizeof(int));
    bubble_sort_algo(arr, sizeof(arr)/sizeof(int));
    printarr(arr, sizeof(arr)/sizeof(int));

    printf("\nTEST 2\n");
    int arr1[10] = {99,88,77,66,55,44,33,22,11,0};
    printarr(arr1, sizeof(arr1)/sizeof(int));
    bubble_sort_algo(arr1, sizeof(arr1)/sizeof(int));
    printarr(arr1, sizeof(arr1)/sizeof(int));

    printf("\nTEST 3\n");
    int arr2[10] = {00,11,22,33,44,55,66,77,88,99};
    printarr(arr2, sizeof(arr2)/sizeof(int));
    bubble_sort_algo(arr2, sizeof(arr2)/sizeof(int));
    printarr(arr2, sizeof(arr2)/sizeof(int));

    printf("\nTEST 4 - PTR NULL\n");
    int *ptr = NULL;
    if(bubble_sort_algo(ptr, 10) != SORT_SUCCESS)
    {
        printf("Function failed as expected\n");
    }

    printf("\nTEST 5 - Size 0\n");
    if(bubble_sort_algo(arr2, 0) != SORT_SUCCESS)
    {
        printf("Function failed as expected\n");
    }

    printf("\nTEST 6\n");
    int arr3[10] = {00,-11,22,-33,44,-55,66,-77,88,-99};
    printarr(arr3, sizeof(arr3)/sizeof(int));
    bubble_sort_algo(arr3, sizeof(arr3)/sizeof(int));
    printarr(arr3, sizeof(arr3)/sizeof(int));

    printf("\nTEST 7\n");
    int arr4[1] = {-11};
    printarr(arr4, sizeof(arr4)/sizeof(int));
    bubble_sort_algo(arr4, sizeof(arr4)/sizeof(int));
    printarr(arr4, sizeof(arr4)/sizeof(int));
    return(0);
}

__inline__ static void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printarr(int* arr, int n)
{
    printf("Array is -> [ ");
    for(int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("]\n");
}
ret_value_t bubble_sort_algo(int* arr, const int n)
{
    if(arr == NULL)
    {
        return(SORT_ERROR__INVALID_PARAM);
    }

    if(n == 0)
    {
        return(SORT_ERROR__INVALID_PARAM);
    }

    printf("Sorting using Bubble Sort \n");
    unsigned int i = 0;
    unsigned int k = 0;
    unsigned int passes = 0;
    unsigned int end = 0;
    bool noswap = true;

    for(i = 0; i < (n-1); i++)
    {
        noswap = true;
        end = n - 1 - i;
        for(k = 0;k<end; k++)
        {
            if(arr[k] < arr[k+1])
            {
                noswap = false;
                swap(&arr[k], &arr[k+1]);
            }
            passes++;
        }
        // If there is no swap then the array is sorted in which case we can break
        if(noswap == true)
        {
            break;
        }
    }
    printf("NUM PASSES = %d \n",passes);
    return(SORT_SUCCESS);
}
