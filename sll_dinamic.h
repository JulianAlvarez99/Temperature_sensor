#ifndef SLL_DINAMIC_H_INCLUDED
#define SLL_DINAMIC_H_INCLUDED
#include "stack_static.h"
#define t_elem_list stack*

typedef struct _sll_node
{
    t_elem_list value;
    struct _sll_node *next;
}sll_node;

sll_node* sll_new_node(t_elem_list element);
int sll_add_node(sll_node** head, sll_node* new_node);
void sll_add_day_measures(sll_node** head, t_elem_list element);

#endif // SLL_DINAMIC_H_INCLUDED
