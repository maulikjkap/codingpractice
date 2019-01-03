/*
Write a function that, for a given no n, finds a number p which is greater
than or equal to n and is a smallest power of 2.
Examples :

    Input : n = 5
    Output: 8

    Input  : n = 17
    Output : 32

    Input  : n = 32
    Output : 32
*/

#include <stdio.h>

#define MAX_BITS_INT    (sizeof(unsigned int)*8)
unsigned int smallest_power_of_2(unsigned int n)
{
    int i = 0;
    for(i = 0;i<MAX_BITS_INT;i++)
    {
        if((1<<i) < n)
        {
            //dont do anything but keep searching
        }
        else
        {
            break;
        }
    }
    return((1<<i));
}

int main(void)
{
    printf("Smallest power of %d is %d\n",5,smallest_power_of_2(5));
    printf("Smallest power of %d is %d\n",17,smallest_power_of_2(17));
    printf("Smallest power of %d is %d\n",32,smallest_power_of_2(32));
    printf("Smallest power of %d is %d\n",63,smallest_power_of_2(63));
    printf("Smallest power of %d is %d\n",64,smallest_power_of_2(64));
    printf("Smallest power of %d is %d\n",65,smallest_power_of_2(65));

    return(0);
}
