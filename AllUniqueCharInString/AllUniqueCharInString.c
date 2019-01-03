
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef unsigned int uint32_t;

//Since the Ascii is only 128 bits the printable char list is going to be only 128 bits.
// each bit is for one ascii value
bool bitvectorbool[256] = {0};

void printvector()
{
    printf("\n");
    for(int i = 0;i<256;i++)
    {
        printf("%d",bitvectorbool[i]);
    }
    printf("\n");

}
void reset_bitmap()
{
    memset((void *)bitvectorbool, 0, sizeof(bitvectorbool));
}
void set_bit_in_bitmap(int val)
{
    bitvectorbool[val] = true;
}

bool get_bit_from_bitmap(int val)
{
    return(bitvectorbool[val]);
}

bool allCharUnique(char *str)
{

    uint32_t i = 0;
    uint32_t char_to_int = 0;
    bool unique = true;
    reset_bitmap();
    while(str[i] != '\0')
    {
        char_to_int = (uint32_t)str[i];
        if(get_bit_from_bitmap(char_to_int) == 1)
        {
            printf("%c not unique at location %d\n",str[i],i);
            unique = false;
        }
        else
        {
            set_bit_in_bitmap(char_to_int);
        }
        i++;
    }
    return(unique);
}

int main(void)
{
    char str1[] = "MYNAME";
    printf("All Char in String %s is %d (0=NotUnique, 1 = Unique)\n",str1,allCharUnique(str1));

    char str2[] = "1234567890~!@#$%^&*()_+{POIUYTREWQSADZCGV}";
    printf("All Char in String %s is %d (0=NotUnique, 1 = Unique)\n",str2,allCharUnique(str2));

    return 0;
}
