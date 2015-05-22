/*
 * sll.c: singly linked list implementation and APIs
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "sll_api.h"

/***************************************************************************************/
/* checks if the list has a ring; if so, returns the pointer */

/* complexity:
 * time: O(n)
 * space: O(1), because it's a pointer algorithm
 */ 

node_t * sll_find_ring(node_t *head)
{
    node_t *slow = head;
    node_t *fast = head;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return slow;
    }
    
    return NULL;
}

/***************************************************************************************/
/* finds the length of the ring */

/* complexity:
 * time: O(n)
 * space: O(1)
 */ 

int sll_ring_length(node_t *ptr)
{
    int len = 0;
    node_t *t = NULL;

    if (ptr)
        t = ptr->next;
    
    while(t) {
        ++len;
        if (t == ptr)
            break;
        t = t->next;        
    }

    return len;
}

/***************************************************************************************/
/* returns the entry pont of a ring found in the list */

/* complexity:
 * time: O(n)
 * space: O(1) (pointer algorithm)
 */ 

node_t * sll_ring_entry(node_t *head, int ring_len)
{
    int len = ring_len;
    node_t *t = head;

    if (len < 0 || !t)
        return NULL;
    
    while(head && len--)
        head = head->next;

    len = ring_len;
    while(head && t) {
        if (head == t)
            return t;
        
        head = head->next;
        t = t->next;
    }

    return NULL;
}

/***************************************************************************************/
/* insert an intem to the beginning of the list */

node_t * sll_insert_first(node_t *head, int data)
{
    node_t *t = (node_t *)malloc(sizeof(node_t));

    if (t == NULL) {
        fprintf(stderr, "list insoert failed, %s(%d)\n",
                strerror(errno), errno);
    }

    t->data = data;
    t->next = head;
    head = t;
    
    return head;
}

/***************************************************************************************/
/* delete from the beginning of the list */

node_t * sll_delete_first(node_t *head)
{
    node_t *t = head;

    if (t) {
        head = head->next;
        free(t);
    }

    return head;
}

/***************************************************************************************/
/* print the list entries */

void sll_dump_list(node_t *list)
{
    fprintf(stdout, "dump list\n");
    fprintf(stdout, "---------\n");
    
    while(list) {
        fprintf(stdout, "%d \n", list->data);
        list = list->next;
    }
}

/***************************************************************************************/
/* traverse the list to search for an item */

node_t * sll_search(node_t *list, int data)
{

    return NULL;
}

/***************************************************************************************/
