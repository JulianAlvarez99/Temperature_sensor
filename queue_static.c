#include <stdio.h>
#include <stdlib.h>
#include "queue_static.h"
#include "search_bt.h"

/**
Crea una nueva cola
**/

queue* queue_new(int maxsize)
{
    queue* q = (queue*)malloc(sizeof(queue));
    q->a = (t_elemq*)malloc(sizeof(t_elemq)*maxsize);
    q->head = 0;
    q->tail = 0;
    q->maxsize = maxsize;
    q->count = 0;
    return q;
}

/**
Libera una cola
**/
void queue_free (queue* q)
{
    free(q->a);
    free(q);
}

/**
Devuelve el tamaño total de una cola
**/
int queue_getmaxsize(queue* q)
{
    return q->maxsize;
}

/**
Chequea si la cola esta llena, devuelve un entero para confirmar
**/

int queue_isfull (queue* q)
{
    return (q->count == q->maxsize)?1:0;
    //return q->count == q->maxsize;
}

/**
Chequea si la cola esta vacia, devuelve un entero para confirmar
**/

int queue_isempty (queue* q)
{
    return (q->count == 0)?1:0;
    //return q->count == 0;
}

/**
Inserta un t_elemq en la cola
**/

void enqueue (queue* q, t_elemq elem)
{
    if (queue_isfull(q))
    {
        printf("Queue overflow\n");
        exit(1);
    }

    q->a[q->tail] = elem;
    q->tail = (q->tail+1)%(q->maxsize);
    q->count++;
}

/**
Remueve un t_elemq en la cola, retorna el t_elemq removido
**/

t_elemq dequeue (queue* q)
{

    if (queue_isempty(q))
    {
        printf("Queue underflow\n");
        exit(1);
    }

    t_elemq result = (t_elemq) q->a[q->head];
    q->head = (q->head+1)%(q->maxsize);
    q->count--;
    return result;
}

/**
Imprime una cola
**/

void queue_print(queue* q)
{
    if(!q)return;

    queue *aux = q;

    while(!queue_isempty(aux))
    {
        printf("%d ", q->head);
        dequeue(aux);
    }
    printf("\n\n");
}

/**
Inserta todos los t_elem de un arbol binario de busqueda en una cola de manera ordenada ascendente por minuto
Se insertan en in-orden
**/

void queue_measures_soarted(queue** queue_measures, btn* node)
{
    if(!node)return;

    queue_measures_soarted(queue_measures, node->left);
    enqueue(*queue_measures, node->value);
    queue_measures_soarted(queue_measures, node->right);
}


