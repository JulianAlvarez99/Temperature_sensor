#include <stdio.h>
#include <stdlib.h>
#include "stack_static.h"
#include "temperature_sensor.h"

/**
STACK_NEW() CREA UNA NUEVA PILA SETEANDO EL CONTADOR DE ELEMENTOS EN 0, DEVUELVE UNA PILA VACIA
**/

stack* stack_new()
{
    stack* s = (stack*)malloc(sizeof(stack));
    if(s!=NULL)
    {
        s->count = 0;
    }
    return s;
}

/**
_NODE_NEW(T_ELEMS ) FUNCIÓN ENMASCARADA. CREA UN NUEVO NODO Y SETEA EL ELEMENTO T_ELEMS DENTRO DE ÉL EN LA PILA EN CUESTIÓN
**/

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

/**
_NODE_FREE LIBERA EL NODO CABECERA DE UNA PILA Y SE ASIGNA LA CABEZA AL SIGUIENTE ELEMENTO.
**/
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

/**
STACK_FREE LIBERA UNA PILA
**/

void stack_free(stack* s)
{
    _node_free(s->head);
}

/**
STACK_PUSH INSERTA UN ELEMENTO EN UNA PILA
**/

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

/**
STACK_POP REMUEVE UN ELEMENTO EN UNA PILA
**/

t_elems stack_pop(stack* s)
{
    t_elems result;

    if (s != NULL)
    {
        stack_node* aux_removed = s->head;
        result = s->head->value;
        s->head = s->head->next;
        _node_free(aux_removed);

        s->count--;
    }
    return result;
}

/**
STACK_TOP RETORNA EL ELEMENTO CABECERA DE UNA PILA
**/
t_elems stack_top(stack* s)
{
    return s->head->value;
}

/**
STACK_GET_SIZE RETORNA LA CANTIDAD DE ELEMENTOS DENTRO DE UNA PILA
**/
int stack_get_size (stack* s)
{
    return s->count;
}

/**
STACK_ISEMPTY VERIFICA SI LA PILA ESTA VACIA
**/

int stack_isempty (stack* s)
{
    return (s->count == 0)?1:0;

}

/**
FUNCION AUXILIAR PARA IMPRIMIR EL TIPO DE ELEMENTO DE UNA PILA
**/

void prt(t_elems e)
{
    printf("temperatura = %d \t minuto = %d\n", e.temperature, e.minute);
}

/**
STACK_PRINT IMPRIME EL CONTENIDO DE UNA PILA
**/

void stack_print(stack* s)
{
    stack* aux_stack = stack_new();
    t_elems aux;

    while(!stack_isempty(s))
    {
        aux = stack_pop(s);
        stack_push(aux_stack,aux);
        prt(aux);
    }
    while(!stack_isempty(aux_stack))
    {
        stack_push(s,stack_pop(aux_stack));
    }
}
