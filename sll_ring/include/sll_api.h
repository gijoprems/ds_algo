#ifndef _SLL_API_H_
#define _SLL_API_H_

/***************************************************************************************/
/* list structure */

typedef struct node_s {
    int data;
    struct node_s *next;
}node_t;

/***************************************************************************************/

void sll_dump_list(node_t *list);
node_t * sll_insert_first(node_t *head, int data);
node_t * sll_find_ring(node_t *head);
int sll_ring_length(node_t *ptr);
node_t * sll_ring_entry(node_t *head, int len);

/***************************************************************************************/

#endif /* _SLL_API_H_ */

