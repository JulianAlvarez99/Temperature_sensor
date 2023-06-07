#ifndef STACK_STATIC_H_INCLUDED
#define STACK_STATIC_H_INCLUDED
#include "temperature_sensor.h"
#define t_elems reading

typedef struct _node
{
    t_elems value;
    struct _node* next;
} stack_node;

typedef struct _stack
{
    stack_node *head;
    int count;
} stack;


stack* stack_new();
void _node_free(stack_node* h);
void stack_free(stack* s);
stack_node* _node_new(t_elems element);
int stack_push(stack* s, t_elems value);
t_elems stack_pop(stack* s);
t_elems stack_top(stack* s);
int stack_get_size (stack* s);
stack* stack_set_temperature();
int stack_isempty (stack* s);
void prt(t_elems e);
void stack_print(stack *s);

#endif // STACK_STATIC_H_INCLUDED
