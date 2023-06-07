#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "search_bt.h"

/**
  BTN_NEW Crea un nodo de un BTN en base a un valor t_elem_btree
 **/
btn* btn_new(t_elem_btree value)
{
    btn* node = (btn*)malloc(sizeof(btn));

    node->value = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

/**
BTN_FREE LIBERA LA MEMORIA DE UN BTN
**/

void btn_free(btn** node)
{
    if(!*node)return;

    //Elimino los hijos primero
    btn_free(&(*node)->left);
    btn_free(&(*node)->right);

    //Despues elimino el nodo
    free(*node);
}

/**
BTN_MEASURES_CMP COMPARA 2 T_ELEM_BTREE, SI COINCIDEN EN EL MISMO MINUTO, DESEMPATAN EN LA COMPARACION DE SUS TEMPERATURAS
FUNCION AUXILIAR PARA ORDENAR Y CREAR EL SBT
**/

int btn_measures_cmp(t_elem_btree a, t_elem_btree b)
{
    if(a.minute == b.minute)
    {
        return(a.temperature - b.temperature);
    }
    else
        return(a.minute - b.minute);
}

/**
 * Funcion enmascarada
 * Agrega un valor a un árbol binario de búsqueda (SBT)
 * (agrega valores repetidos)
 * Parámetros:
 *          **node: debe ser la dirección de memoria (en la estructura del padre
 * o la raíz) que donde se encuentra el puntero al nodo del subárbol donde se
 * va a insertar
 *          value: t_elem_btree a agregar.
 *          cmp: funcion auxiliar con criterio para insertar los t_elem_btree
 */

void _sbt_insert_value(btn **node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree))
{
    if (node == NULL) return;

    if((*node)==NULL)
    {
        *node = btn_new(value);
    }
    else
    {
        if(cmp((*node)->value, value)<0)
        {
            _sbt_insert_value(&(*node)->left,value,cmp);
        }
        else if (cmp((*node)->value,value)>0)
        {
            _sbt_insert_value(&(*node)->right,value,cmp);
        }
    }
}

/**
Funcion similar a imprimir el contenido de una pila, el unico cambio que se realiza es el llamado en vez de a una funcion de impresion,
se realiza el llamado _sbt_insert_value el cual inserta los t_elem_btree

Se debe realizar esta funcion ya que recibe como parametro una pila, por ende hay que ir sacando elemento por elemento de pila sin perder la pila original
**/

void sbt_insert_value(btn **node, stack* day_measures, int cmp (t_elem_btree, t_elem_btree))
{
    stack* aux_stack = stack_new();
    t_elems aux;

    while(!stack_isempty(day_measures))
    {
        aux = stack_pop(day_measures);
        stack_push(aux_stack,aux);
        _sbt_insert_value(node,aux,cmp);
    }
    while(!stack_isempty(aux_stack))
    {
        stack_push(day_measures,stack_pop(aux_stack));
    }
}


/**
FUNCION RECURSIVA PARA MOSTRAR LOS ELEMENTOS DE UN ARBOL BT
**/

void sbt_print_tree(btn* node, char str[])
{
    printf("%d\n", node->value.minute);

    //Para el hijo izquierdo
    if(node->left != NULL)
    {
        char str2[1500];
        strcpy(str2,str);

        if(node->right != NULL)
        {
            printf("%s%c%c%c%c%c",str,195,196,196,196,196);
            char symb = 179;
            char aux[2];

            aux[0] = symb;
            aux[1] = '\0';
            strcat(str2,aux);
            strcat(str2,"     ");
            sbt_print_tree(node->left,str2);
        }
        else
        {
            printf("%s%c%c%c%c%c",str,195,196,196,196,196);
            strcat(str2,"     ");
            sbt_print_tree(node->left,str2);
        }
    }
    //Para el hijo derecho
    if(node->right != NULL)
    {
        char str3[1500];
        strcpy(str3,str);
        printf("%s%c%c%c%c%c",str,195,196,196,196,196);
        strcat(str3,"     ");
        sbt_print_tree(node->right,str3);
    }
}

void sbt_show_tree(btn* root)
{
    if(root == NULL)
    {
        printf("El arbol esta vacio\n");
    }
    else sbt_print_tree(root,"");
}
