#include <overflow.h>
#include <assert.h>
#include <stdio.h>

int main(void)
{
    int a = 0;
    int b = 0;
    int c = 0


    a = 0x7fffffff; b = 0x80000001;
    assert(is_uint_add_overflow(a, b,&c) == false);

    a = 0x7fffffff; b = 0x00000001;
    assert(is_uint_add_overflow(a, b,&c) == true);

    a = 0x7fffffff; b = 0x00000000;
    assert(is_uint_add_overflow(a, b,&c) == false);

    a = 0x7fffffff; b = 0x80000000;
    assert(is_uint_add_overflow(a, b,&c) == false);

    a = 0x7fffffff; b = 0x80000001;
    assert(is_uint_add_overflow(a, b,&c) == false);

    return(0);
}
