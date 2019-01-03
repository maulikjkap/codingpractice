
#include <stdio.h>

void print_binary(int number) {
    int digit;
    for(digit = 32 - 1; digit >= 0; digit--) {
        printf("%c", number & (1 << digit) ? '1' : '0');
    }
    printf("\n");
}


unsigned int reverseBits(unsigned int num)
{
    unsigned int count = sizeof(num) * 8 - 1;
        unsigned int reverse_num = num;

        num >>= 1;
        while(num)
        {
           reverse_num <<= 1;
           reverse_num |= num & 1;
           num >>= 1;
           count--;
        }
        reverse_num <<= count;
        return reverse_num;
}


int main(void)
{
    unsigned int num = 0xb1b2b3b4;
    printf("OriginalNum = 0x%x, ReverseNum = 0x%x\n",num,reverseBits(num));
    return(0);
}
