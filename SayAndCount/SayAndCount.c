/*
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.



Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "1211"
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned int uint32_t;
typedef int int32_t;

void print_arr(int *arr)
{
    for(int i=0;arr[i]!=0;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void countAndSay(int n)
{
    /*
1.     1
2.     11
3.     21
4.     1211
5.     111221
6.     312211
7.     13112221
8.     1113213211
9.     31131211131221
*/
    printf("Count and say for %d numbers\n",n);
    if((n < 1) || (n > 30))
    {
        return;
    }

    int maxarrsz = (n);
    int* arr = (int*)calloc((maxarrsz),sizeof(int));
    int* temparr = (int*)calloc((maxarrsz),sizeof(int));

    if(arr == NULL)
    {
        printf("Malloc Failure\n");
    }

    if(temparr == NULL)
    {
        printf("Malloc Failure\n");
    }
    if(n == 1)
    {
        arr[0] = 1;
        return;
    }
    arr[0] = 1;

    if(arr == NULL)
    {
        return;
    }

    int arrlen = 1;
    for(int i = 0; i < n; i++)
    {
        int numelements = 1;
        int k = 0;
        printf("%d. ",i+1);
        print_arr(arr);

        for(int j = 0; j<arrlen;j++)
        {
            if(arr[j] == arr[j+1])
            {
                numelements++;
            }
            else    // We found a break
            {
                if((k) >= (maxarrsz))
                {
                    printf("Need to realloc k = %d, maxarrsz=%d\n",k,maxarrsz);
                    maxarrsz = maxarrsz << 1;
                    temparr = (int*) realloc(temparr, maxarrsz*(sizeof(int)));
                    if(temparr == NULL)
                    {
                        printf("Realloc Error\n");
                        free(arr);
                        arr = NULL;
                        free(temparr);
                        temparr = NULL;
                    }
                    int* arr = NULL;
                    arr = (int*) realloc(arr, maxarrsz*(sizeof(int)));
                    if(arr == NULL)
                    {
                        printf("Realloc Error\n");
                        free(arr);
                        arr = NULL;
                        free(temparr);
                        temparr = NULL;
                    }
                }
                temparr[k] = numelements;
                k++;
                temparr[k] = arr[j];
                k++;

                numelements = 1;
            }
        }
        memset((void*)arr,0,sizeof(arr));
        memcpy((void*)arr, (void*)temparr, (k)*(sizeof(int)));
        arrlen = k;
        //print_arr(temparr);
    }

    free(arr);
    arr = NULL;
    free(temparr);
    temparr = NULL;
}

int main(void)
{
    countAndSay(2);
    countAndSay(12);
    countAndSay(12);
    //countAndSay(0);
    //countAndSay(30);
    return(0);
}
