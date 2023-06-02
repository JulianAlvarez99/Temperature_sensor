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

/*t_elems stack_pop(stack_node ** head)
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
}*/

t_elems stack_pop(stack* s)
{
    t_elems result = NULL;

    if (s != NULL)
    {
        stack_node* aux = s->head;
        result = aux->value;
        s->head = aux->next;
        free(aux);

        s->count--;
    }
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

int stack_isempty (stack* s)
{
    return (s->count == 0)?1:0;

}


void prt(t_elems e)
{
    printf("temperatura = %d \t minuto = %d\n", e->temperature, e->minute);
}

/*void stack_print(stack* s, void prt (t_elems))
{
    if (!stack_isempty(s))
    {
        t_elems e = (t_elems)malloc(sizeof(reading));
        e = stack_pop(s);
        prt(e);
        stack_print(s, prt);
        stack_push(s, e);
    }
}*/

void stack_print(stack* s)
{
    stack* aux_stack = stack_new();

    if(!stack_isempty(s))
    {
        stack_push(aux_stack,stack_top(s));
        prt(stack_pop(s));
        stack_print(s);
    }

    while(!stack_isempty(aux_stack))
    {
        stack_push(s,stack_pop(aux_stack));
    }
}
