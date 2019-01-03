// C Program to swap bits
// in a given number

/*
Given a number x and two positions (from right side) in binary representation of
 x, write a function that swaps n bits at given two positions and returns the
 result. It is also given that the two sets of bits do not overlap.


Let p1 and p2 be the two given positions.

Example 1
Input:
x = 47 (00101111)
p1 = 1 (Start from second bit from right side)
p2 = 5 (Start from 6th bit from right side)
n = 3 (No of bits to be swapped)
Output:
227 (11100011)
The 3 bits starting from the second bit (from right side) are
swapped with 3 bits starting from 6th position (from right side)

Example 2
Input:
x = 28 (11100)
p1 = 0 (Start from first bit from right side)
p2 = 3 (Start from 4th bit from right side)
n = 2 (No of bits to be swapped)
Output:
7 (00111)
The 2 bits starting from 0th postion (from right side) are
swapped with 2 bits starting from 4th position (from right side)
*/

#include<stdio.h>

void print_binary(int number, int num_digits) {
    int digit;
    for(digit = num_digits - 1; digit >= 0; digit--) {
        printf("%c", number & (1 << digit) ? '1' : '0');
    }
    printf("\n");
}

int swapBits(unsigned int x, unsigned int p1, unsigned int p2, unsigned int n)
{
    printf("Num   = \n");
    unsigned int mask = ((1<<n) - 1);
    print_binary(x,32);

	/* Move all bits of first set to rightmost side */
    unsigned int set1 = (((x >> p1) & (mask)) << p2);

	/* Move all bits of second set to rightmost side */
	unsigned int set2 = (((x >> p2) & (mask)) << p1);

    x = x & (~(mask << p1));
    x = x & (~(mask << p2));
    x = x | (set1 | set2);

	return x;
}

/* Driver program to test above function*/
int main(void)
{
	int res = swapBits(47, 1, 5, 3);
	printf("\nResult = %d \n", res);
	return 0;
}
