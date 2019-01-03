
/*
Square of Even number n can be expressed as
n = 2x
square(n) = square(2x) = 4*square(x)

Square of ODD number n can be expressed as
n = 2x + 1
square(n) = square(2x + 1) = 4*square(x) + 4*x + 1
*/

#include <stdio.h>
unsigned int square(int num)
{
    if(num < 0)
    {
        num = -num;
    }

    if(num == 0)
    {
        return 0;
    }

    unsigned int halfnum = (num >> 1);

    // if num is odd
    if(num & 1)
    {
        return((square(halfnum) << 2) + (halfnum << 2) + 1);
    }
    else
    {
        return((square(halfnum) << 2));
    }


}
int main(void)
{
    unsigned int num = 0;

    for(num = 0; num<20;num++)
    {
        printf("Square of %d is %d\n",num,square(num));
    }
    return(0);
}
