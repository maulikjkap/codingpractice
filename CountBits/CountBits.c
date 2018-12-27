#include <stdio.h>

typedef unsigned int uint32_t;
typedef int int32_t;

uint32_t count_num_of_bits(int32_t num)
{
    uint32_t max = sizeof(uint32_t)*8;
    uint32_t num1 = 0;
    uint32_t i = 0;
    for(i = 0; i<max;i++)
    {
        if((num & 0x1) == 1)
        {
            num1++;
        }
        num = num >> 1;
        if(num == 0)
        {
            break;
        }
    }
    printf("Max loop cycles is %d\n",i);
    return(num1);
}

int main(void)
{
    printf("Num of bits in 0xFEFEFEFE is %d\n",count_num_of_bits(0xfefefefe));
    printf("Num of bits in 0x00000000 is %d\n",count_num_of_bits(0x00000000));
    printf("Num of bits in 0x00001000 is %d\n",count_num_of_bits(0x00001000));
    printf("Num of bits in 0xFFFFFFFF is %d\n",count_num_of_bits(0xFFFFFFFF));

}
