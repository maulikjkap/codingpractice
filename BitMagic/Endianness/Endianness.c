
#include <stdio.h>
int main(void)
{
    unsigned int i = 0x1;
    char *charptr = (char*)&i;

    if(*charptr == 1)
    {
        printf("LittleEndian\n");
    }
    else
    {
        printf("BigEndian\n");
    }
    return(0);
}
