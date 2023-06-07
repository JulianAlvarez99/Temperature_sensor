#include <stdio.h>
#include <stdlib.h>
#include "sll_dinamic.h"

/**
Crea un nuevo nodo a la lista simplemente enlazada con un t_elem_list
**/
sll_node* sll_new_node(t_elem_list element) //Create a new node for single linked list.
{
    sll_node* new_node = (sll_node*)malloc(sizeof(sll_node));

    if (new_node != NULL)
    {
        new_node->value = element;
        new_node->next = NULL;
    }

    return new_node;
}

/**
Agrega un nuevo nodo a la lista simplemente enlazada con un t_elem_list
**/

int sll_add_node(sll_node** head, sll_node* new_node) //Add a new node to the end of the list.
{
    if (new_node == NULL) return 0;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        sll_node* aux = *head;
        while (aux->next != NULL)
        {
            aux = aux->next;
        }
        aux->next = new_node;
    }

    return 1;
}

/**
Agrega un t_elem_list al final de la lista simplemente enlazada
**/
void sll_add_day_measures(sll_node** head, t_elem_list element) //Add a element to the end of de list (recursive).
{
    sll_node* new_node = sll_new_node(element);
    sll_add_node(head, new_node);
}

