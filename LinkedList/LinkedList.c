#include "LinkedList.h"
#include <stdio.h>


static node_t* headptr = NULL;
int main(void)
{
    headptr = create_linked_list(headptr);
    print_linked_list(headptr);
    headptr = add_node_to_end(headptr,3);
    printf("%p\n",headptr);
    headptr = add_node_to_end(headptr,7);
    headptr = add_node_to_end(headptr,8);
    headptr = add_node_to_end(headptr,11);
    print_linked_list(headptr);
    headptr = add_node_to_beggining(headptr,2);
    headptr = add_node_to_beggining(headptr,1);
    print_linked_list(headptr);
    headptr = add_node_after_val(headptr, 9, 8);
    headptr = add_node_after_val(headptr, 13, 11);
    print_linked_list(headptr);
    headptr = add_node_before_val(headptr, 6, 7);
    headptr = add_node_before_val(headptr, 12, 13);
    headptr = add_node_before_val(headptr, 0, 1);
    print_linked_list(headptr);
    headptr = free_entire_linked_list(headptr);
    print_linked_list(headptr);

    return 0;
}
