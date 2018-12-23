#include "LinkedList.h"
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

node_t* create_linked_list(node_t* headptr)
{
    headptr = NULL;
    return(headptr);
}

/*!
@brief thie function adds a node at the Beggining
*/
node_t* add_node_to_beggining(node_t* headptr, int val)
{
    printf("Add Node %d to the Beggining\n",val);
    node_t* newnode = (node_t*) malloc(sizeof(node_t));
    if(newnode == NULL)
    {
        printf("MALLOC FAILED\n");
        return(NULL);
    }

    newnode->val = val;
    newnode->next = NULL;
    if(headptr == NULL)
    {
        printf("Headptr NULL\n");
        headptr = newnode;
        return(headptr);
    }
    newnode->next = headptr;
    headptr = newnode;
    return(headptr);
}

/*!
@brief thie function adds a node at the end of the Linked list
*/
node_t* add_node_to_end(node_t* headptr, int val)
{
    printf("Add Node %d to the end\n",val);
    node_t* newnode = (node_t*) malloc(sizeof(node_t));
    if(newnode == NULL)
    {
        printf("MALLOC FAILED\n");
        return(NULL);
    }
    newnode->next = NULL;
    newnode->val = val;

    if(headptr == NULL)
    {
        printf("Headptr NULL\n");
        headptr = newnode;
        return(headptr);
    }

    node_t* ptr = headptr;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = newnode;
    return(headptr);
}

/*!
@brief thie function adds a node after a value node is found in the linked list
*/
node_t* add_node_after_val(node_t* headptr, int val, int val_to_add_after)
{
    node_t* ptr = headptr;
    if(headptr == NULL)
    {
        printf("Empty Linked List\n");
        return(headptr);
    }

    while(ptr != NULL)
    {
        if((ptr->val) == val_to_add_after)
        {
            printf("Found the LL that contains the valud %d \n",val_to_add_after);
            node_t* newnode = (node_t*) malloc(sizeof(node_t));
            if(newnode == NULL)
            {
                printf("MALLOC FAILED\n");
                return(NULL);
            }

            newnode->next = ptr->next;
            newnode->val = val;
            ptr->next = newnode;
            break;
        }
        ptr = ptr->next;
    }
    return(headptr);
}

node_t* add_node_before_val(node_t* headptr, int val, int val_to_add_before)
{
    node_t* ptr = headptr;
    if(headptr == NULL)
    {
        printf("Empty Linked List\n");
        return(headptr);
    }

    node_t* prev_ptr = NULL;
    while(ptr != NULL)
    {
        if(ptr->val == val_to_add_before)
        {
            node_t* newnode = (node_t*) malloc(sizeof(node_t));
            if(newnode == NULL)
            {
                printf("MALLOC FAILED\n");
                return(NULL);
            }
            newnode->val = val;

            if(prev_ptr == NULL)
            {
                newnode->next = headptr;
                headptr = newnode;
                break;
            }
            newnode->next = prev_ptr->next;
            prev_ptr->next = newnode;

            break;
        }
        prev_ptr = ptr;
        ptr = ptr->next;
    }
    return(headptr);
}

node_t* free_entire_linked_list(node_t* headptr)
{
    printf("Freeing Linked List\n");
    node_t* ptr = headptr;
    node_t* freeptr = NULL;

    while(ptr != NULL)
    {
        freeptr = ptr;
        ptr = ptr->next;
        printf("Freeing %p\n",freeptr);
        free(freeptr);
        freeptr = NULL;
    }
    return(ptr);
}
void print_linked_list(node_t* headptr)
{
    printf("Printing Linked List\n");
    node_t* ptr = headptr;
    if(headptr == NULL)
    {
        printf("Empty Linked List\n");
        return;
    }

    while(ptr->next != NULL)
    {
        printf("[DATA=%d | NEXT=%p]\n",ptr->val, (node_t*)ptr->next);
        ptr = ptr->next;
    }
    //printf the last one
    printf("[DATA=%d | NEXT=%p]\n",ptr->val, (node_t*)ptr->next);


}
