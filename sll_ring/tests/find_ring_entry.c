/*
 * test functions for sll
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "sll_api.h"

/***************************************************************************************/
/* initialize a test list */

node_t * init_test_list(void)
{
    node_t *head = NULL;
    
    head = sll_insert_first(head, 5);
    head = sll_insert_first(head, 2);
    head = sll_insert_first(head, 6);
    head = sll_insert_first(head, 8);
    head = sll_insert_first(head, 1);
    head = sll_insert_first(head, 0);
    
    return head;
}

/***************************************************************************************/

int main(void)
{
    int len;
    node_t *head = NULL;
    node_t *list = NULL;
    node_t *t = NULL;

    head = init_test_list();
    sll_dump_list(head);

    /************* case 1 ****************/
    /* make a ring */
    list = head;    
    list->next->next->next->next = head;
    
    if ((t = sll_find_ring(list)) == NULL) {
        fprintf(stdout, "sll: no ring detected \n");
        exit(2);
    }
    
    len = sll_ring_length(t);
    t = sll_ring_entry(head, len);

    if (t)
        fprintf(stdout, "sll: case 1: ring entry is %p(%d), ring_len = %d \n",
                t, t->data, len);
    else
        fprintf(stderr, "sll: couldn't find the ring entry point \n");

    
    /********* case 2 ****************/
    /* make a ring */
    
    head = init_test_list();    
    list = head->next->next;
    list->next->next->next = head->next->next;
    
    if ((t = sll_find_ring(list)) == NULL) {
        fprintf(stdout, "sll: no ring detected \n");
        exit(2);
    }
    
    len = sll_ring_length(t);
    t = sll_ring_entry(head, len);

    if (t)
        fprintf(stdout, "sll: case 2: ring entry is %p(%d), ring_len = %d \n",
                t, t->data, len);
    else
        fprintf(stderr, "sll: couldn't find the ring entry point \n");

    
    return 0;
}

/***************************************************************************************/
