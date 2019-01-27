#include <stdio.h>
#include <string.h>

typedef unsigned int uint32_t;
typedef int int32_t;
typedef char uint8_t;

void convert_dec_to_binary_fraction(double val)
{
    if(val >= 1)
    {
        printf("Only Support less than decimal\n");
    }
    if(val == 0)
    {
        printf("Binary is 0\n");
        return;
    }

    if(val < 0)
    {
        printf("Value of Double %f in Binary is = -0.",val);
        val = (!val) + 1;
    }
    else
    {
        printf("Value of Double %f in Binary is = 0.",val);
    }


    uint32_t digitcount = 32;
    while((val != 0) && (digitcount != 0))
    {
        val = val * 2; //val = val *2
        if(val >= 1)
        {
            printf("1");
            val = val - 1;
        }
        else
        {
            printf("0");
        }
        digitcount--;
    }
    printf("\n");
}
int main(void)
{
    double val_to_convert = 0.625;
    convert_dec_to_binary_fraction(val_to_convert);
    val_to_convert = 0.775;
    convert_dec_to_binary_fraction(val_to_convert);
    val_to_convert = -0.625;
    convert_dec_to_binary_fraction(val_to_convert);
    return(0);
}
