/*
 * test functions for sll
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "sll_api.h"

/***************************************************************************************/

int main(void)
{
    node_t *head = NULL;
    node_t *t = NULL;
    
    head = sll_insert_first(head, 5);
    head = sll_insert_first(head, 2);
    head = sll_insert_first(head, 6);
    head = sll_insert_first(head, 8);
    head = sll_insert_first(head, 1);
    head = sll_insert_first(head, 0);
    
    sll_dump_list(head);

    head->next->next = head;
    
    if ((t = sll_find_ring(head)))
        fprintf(stdout, "sll: ring detected \n");
    else
        fprintf(stdout, "sll: no ring detected \n");

    fprintf(stdout, "sll: length of the ring is %d \n",
            sll_ring_length(t));

    return 0;
}

/***************************************************************************************/
