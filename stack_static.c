#include <stdio.h>
#include <stdlib.h>
#include "stack_static.h"
#include "temperature_sensor.h"

stack* stack_new()
{
    stack* s = (stack*)malloc(sizeof(stack));
    if(s!=NULL)
    {
        s->count = 0;
    }
    return s;
}


void _node_free(stack_node* h)
{
    if(h != NULL)
    {
        stack_node* aux = h;
        h = h->next;
        aux->next = NULL;
        free(aux);
    }
}

void stack_free(stack* s)
{
    _node_free(s->head);
}


stack_node* _node_new(t_elems element)
{
    stack_node* new_node = (stack_node*)malloc(sizeof(stack_node));

    if (new_node != NULL)
    {
        new_node->value = element;
        new_node->next = NULL;
    }
    return new_node;
}

int stack_push(stack* s, t_elems value)
{
    stack_node* n = NULL;
    int result = 0;

    n = _node_new(value);
    if(n!=NULL)
    {
        n->next = s->head;
        s->head = n;
        s->count++;
        result = 1;
    }
    return result;
}

t_elems stack_pop(stack_node ** head)
{
    t_elems result = NULL;

    stack_node* next_node = NULL;

    if (*head == NULL)
    {
        printf("La pila está vacía\n");
    }

    next_node = (*head)->next;
    result = (*head)->value;
    free(*head);
    *head = next_node;
    return result;
}

t_elems stack_top(stack* s)
{
    return s->head->value;
}

int stack_get_size (stack* s)
{
    return s->count;
}
