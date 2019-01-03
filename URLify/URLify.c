#include <stdio.h>
#include <string.h>

typedef unsigned int uint32_t;
typedef int int32_t;
typedef char uint8_t;


uint32_t find_num_of_spaces(uint8_t *str, uint32_t len)
{
    uint32_t num_spaces = 0;
    for(uint32_t i = 0; i<len; i++)
    {
        if(str[i] == ' ')
        {
            num_spaces++;
        }
    }
    return(num_spaces);
}

uint32_t find_strlen(uint8_t *str)
{
    uint32_t i = 0;
    for(i = 0; str[i] != '\0'; i++)
    {
    }
    return(i);
}

void urlify_string(uint8_t *str, uint32_t actual_char_len)
{
    uint32_t num_of_spaces = find_num_of_spaces(str, actual_char_len);
    uint32_t num_of_extra_space_needed = num_of_spaces << 1; //num_of_spaces*2
    uint32_t total_strlen = find_strlen(str);
    uint32_t new_str_end = actual_char_len + num_of_extra_space_needed;

    if(total_strlen < (new_str_end))
    {
        printf("ERROR. Not enough Space to save string");
    }

    int32_t i = 0;
    int32_t wrptr = actual_char_len - 1 + num_of_extra_space_needed;
    for(i = actual_char_len - 1; i >= 0; i--)
    {
        //If we found a space then insert %20
        if(str[i] == ' ')
        {
            str[wrptr] = '0';
            wrptr--;
            str[wrptr] = '2';
            wrptr--;
            str[wrptr] = '%';
            wrptr--;
        }
        else
        {
            str[wrptr] = str[i];
            wrptr--;
        }

    }


}


int main(void)
{
    uint8_t str[] = "Mr John Smith    ";
    printf("ULRify this string = %s\n",str);
    urlify_string(str, 13);
    printf("ULRified string    = %s\n",str);

    return(0);
}
