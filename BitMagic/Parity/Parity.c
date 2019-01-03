
#include <stdio.h>
#include <stdbool.h>


bool parity(unsigned int num)
{
    unsigned int paritycnt = 0;
    printf("0x%x have ",num);
    while(num != 0)
    {
        num = num & (num-1);
        paritycnt++;
    }
    bool parityval = (bool)(paritycnt & 0x1);
    if(parityval)
    {
        printf("ODD Parity\n");
    }
    else
    {
        printf("EVEN Parity\n");
    }
    return(parityval);
}

int main(void)
{
    parity(0x7);
    parity(0xfe);
    parity(0xff);

    parity(0x3);
    parity(0x19);
    parity(0xFFFFFFFF);
    parity(0xFFFFFFFE);
    parity(0x7FFFFFFF);

    return(0);
}
