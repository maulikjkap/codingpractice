

#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <overflow.h>

bool is_uint_add_overflow(int a, int b, int *c)
{
    if((void *)c == (void *)NULL)
    {
        return(false);
    }
    if((INTMAX - a) < b)
    {
        // Overflowed
        return (true);
    }
    else
    {
        *c = a+b;
        return(false);
    }
}
