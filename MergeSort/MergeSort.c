#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef enum {
    SORT_SUCCESS = 0,
    SORT_ERROR = 1,
    SORT_ERROR__INVALID_PARAM = 2,
} ret_value_t;

ret_value_t merge_sort(int* arr, int n);
void printarr(int* arr, int n);

int main(void)
{
    ret_value_t (*sort_func_ptr)(int*,const int) = merge_sort;

    printf("\nTEST 1\n");
    int arr[10] = {8,5,4,3,22,9,12,333,7,88};
    printarr(arr, sizeof(arr)/sizeof(int));
    sort_func_ptr(arr, sizeof(arr)/sizeof(int));
    printarr(arr, sizeof(arr)/sizeof(int));

    printf("\nTEST 2\n");
    int arr1[10] = {99,88,77,66,55,44,33,22,11,0};
    printarr(arr1, sizeof(arr1)/sizeof(int));
    sort_func_ptr(arr1, sizeof(arr1)/sizeof(int));
    printarr(arr1, sizeof(arr1)/sizeof(int));

    printf("\nTEST 3\n");
    int arr2[10] = {00,11,22,33,44,55,66,77,88,99};
    printarr(arr2, sizeof(arr2)/sizeof(int));
    sort_func_ptr(arr2, sizeof(arr2)/sizeof(int));
    printarr(arr2, sizeof(arr2)/sizeof(int));

    printf("\nTEST 4 - PTR NULL\n");
    int *ptr = NULL;
    if(sort_func_ptr(ptr, 10) != SORT_SUCCESS)
    {
        printf("Function failed as expected\n");
    }

    printf("\nTEST 5 - Size 0\n");
    if(sort_func_ptr(arr2, 0) != SORT_SUCCESS)
    {
        printf("Function failed as expected\n");
    }

    printf("\nTEST 6\n");
    int arr3[10] = {00,-11,22,-33,44,-55,66,-77,88,-99};
    printarr(arr3, sizeof(arr3)/sizeof(int));
    sort_func_ptr(arr3, sizeof(arr3)/sizeof(int));
    printarr(arr3, sizeof(arr3)/sizeof(int));

    printf("\nTEST 7\n");
    int arr4[1] = {-11};
    printarr(arr4, sizeof(arr4)/sizeof(int));
    sort_func_ptr(arr4, sizeof(arr4)/sizeof(int));
    printarr(arr4, sizeof(arr4)/sizeof(int));
    return(0);
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


void merge(int* arr, int left, int middle, int right)
{
    int leftArrSize = middle - left + 1;
    int rightArrSize = right - middle;
    //int *arrLeft = (int *)malloc(sizeof(int)*leftArrSize);
    //int *arrRight = (int *)malloc(sizeof(int)*rightArrSize);
    int arrLeft[leftArrSize];
    int arrRight[rightArrSize];
    // Copy the contents of left Subarry to ArrayLeft
    for(int i = 0; i< leftArrSize;i++)
    {
        arrLeft[i] = arr[left+i];
    }

    // Copy the contents of Right Subarry to ArrayRight
    for(int i = 0; i< rightArrSize;i++)
    {
        arrRight[i] = arr[middle+1+i];
    }

    int leftarridx = 0;
    int rightarridx = 0;
    int destarridx = left;

    while((leftarridx < leftArrSize) && (rightarridx < rightArrSize))
    {
        if(arrLeft[leftarridx] <= arrRight[rightarridx])
        {
            arr[destarridx] = arrLeft[leftarridx];
            destarridx++;
            leftarridx++;
        }
        else
        {
            arr[destarridx] = arrRight[rightarridx];
            destarridx++;
            rightarridx++;
        }
    }

    while(leftarridx < leftArrSize)
    {
        arr[destarridx] = arrLeft[leftarridx];
        destarridx++;
        leftarridx++;
    }

    while(rightarridx < rightArrSize)
    {
        arr[destarridx] = arrRight[rightarridx];
        destarridx++;
        rightarridx++;
    }

    //free(arrRight);
    //free(arrLeft);
    //arrRight = NULL;
    //arrLeft = NULL;
}

void merge_sort_halves(int *arr, int left, int right)
{
    if(left < right)
    {
        int middle = left + (right-left)/2;
        merge_sort_halves(arr, left, middle);
        merge_sort_halves(arr, middle+1, right);
        merge(arr, left, middle, right);
        return;
    }
    else
    {
        return;
    }
}

ret_value_t merge_sort(int* arr, const int n)
{
    if(arr == NULL)
    {
        return(SORT_ERROR__INVALID_PARAM);
    }

    if(n == 0)
    {
        return(SORT_ERROR__INVALID_PARAM);
    }
    printf("Sorting using Merge Sort \n");

    merge_sort_halves(arr, 0, n-1);
    return(SORT_SUCCESS);
}
