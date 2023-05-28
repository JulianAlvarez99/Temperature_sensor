#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "search_bt.h"

int btn_measures_cmp(t_elem_btree a, t_elem_btree b)
{
    if(a->minute == b->minute)
    {
        return(a->temperature - b->temperature);
    }
    else
        return(a->minute - b->minute);
}

/**
 * Devuelve el valor máximo entre 2 enteros.
 * Función auxiliar utilizada en height.
 */
t_elem_btree _max_elem (t_elem_btree a, t_elem_btree b, int cmp (t_elem_btree, t_elem_btree) )
{
    return (cmp(a, b) > 0) ? a : b;
}


/**
 * Crea un nodo de un BTN en base a un valor t_elem_btree
 */
btn* btn_new(t_elem_btree value)
{
    btn* node = (btn*)malloc(sizeof(btn));

    node->value = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

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
 * Agrega un valor a un árbol binario de búsqueda (SBT)
 * (no agrega valores repetidos)
 * Parámetros:
 *          **node: debe ser la dirección de memoria (en la estructura del padre
 * o la raíz) que donde se encuentra el puntero al nodo del subárbol donde se
 * va a insertar
 *          value: el valor a agregar.
 * Devuelve:
 *  1 si pudo insertar
 *  0 si no pudo insertar
 */

int sbt_insert_value(btn **node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree))
{
    if (node == NULL) return 0;
    int result;

    if((*node)==NULL)
    {
        *node = btn_new(value);
        result = 1;
    }
    else
    {
        if(cmp((*node)->value, value)>0)
        {
            result = sbt_insert_value(&(*node)->left,value,cmp);
        }
        else if (cmp((*node)->value,value)<0)
        {
            result = sbt_insert_value(&(*node)->right,value,cmp);
        }
        else
            result = 0;
    }
    return result;
}

/**
 * Obtiene el puntero al nodo con el valor solicitado de
 * un SBT. (Versión recursiva)
 * Parámetros:
 *          value: el valor que se busca en el SBT.
 *          *node: el puntero al nodo del sub-árbol donde se
 * va a buscar.
 */
btn* sbt_findr(btn *node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree))
{
    if(node == NULL || cmp(node->value,value)== 0)
    {
        return node;
    }
    else if(cmp(node->value,value)<0)
    {
        return (sbt_findr(node->left,value,cmp));
    }
    else
    {
        return (sbt_findr(node->right,value,cmp));
    }
}

/**
 * DE USO INTERNO para dibujar un árbol.
 */
int _btn_print(btn *tree, int is_left, int offset, int depth, char s[20][255], void toStr (btn*, char*))
{
    char b[200];
    int width = 5;

    if (!tree) return 0;
    toStr(tree, b);
    //sprintf(b, "%s", str);


    int left = _btn_print(tree->left, 1, offset, depth + 1, s, toStr);
    int right = _btn_print(tree->right, 0, offset + left + width, depth + 1, s, toStr);

    // for (int i = 0; i < width; i++) s[2 * depth][offset + left + i] = b[i];
    for (int i = 0; i < strlen(b); i++) s[2 * depth][offset + left + i] = b[i];

    if (depth && is_left)
    {
        for (int i = 0; i < width + right; i++)
            s[2 * depth - 1][offset + left + width / 2 + i] = '-';

        s[2 * depth - 1][offset + left + width / 2] = '+';
        s[2 * depth - 1][offset + left + width + right + width / 2] = '+';

    }
    else if (depth && !is_left)
    {
        for (int i = 0; i < left + width; i++)
            s[2 * depth - 1][offset - width / 2 + i] = '-';

        s[2 * depth - 1][offset + left + width / 2] = '+';
        s[2 * depth - 1][offset - width / 2 - 1] = '+';
    }

    return left + width + right;
}

/**
 * Dibuja un árbol binario con caracteres
 * (Los valores de los nodos deben estar entre 0 y 999).
 */
void btn_print(btn *tree, void toStr (btn*, char*))
{
    char s[20][255];
    for (int i = 0; i < 20; i++) sprintf(s[i], "%80s", " ");

    _btn_print(tree, 0, 0, 0, s, toStr);

    for (int i = 0; i < 20; i++)
    {
        int j = 0;
        while (s[i][j] != '\0' && s[i][j] == ' ')
        {
            j++;
        }
        if (s[i][j] != '\0')
        {
            printf("%s\n", s[i]);
        }
    }
}
