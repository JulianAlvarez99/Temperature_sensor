#include <stdio.h>
#include <stdlib.h>
#include "queue_static.h"
#include "search_bt.h"

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

void queue_free (queue* q)
{
    free(q->a);
    free(q);
}

int queue_getmaxsize(queue* q)
{
    return q->maxsize;
}

int queue_getsize(queue* q)
{
    return q->count;
}

int queue_isfull (queue* q)
{
    return (q->count == q->maxsize)?1:0;
    //return q->count == q->maxsize;
}

int queue_isempty (queue* q)
{
    //return (q->count == 0)?1:0;
    return q->count == 0;
}

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

t_elemq peek (queue* q)
{
    if (queue_isempty(q))
    {
        printf("Queue underflow\n");
        exit(1);
    }
    return q->a[q->head];
}

void queue_print(queue* q)
{
    if(!q)return;

    queue *aux = q;

    while(!queue_isempty(aux))
    {
        printf("%d", q->head);
        dequeue(aux);
    }
    printf("\n\n");
}

void queue_measures_soarted(queue** queue_measures, btn* node)
{
    if(!node)return;

    queue_measures_soarted(queue_measures, node->left);
    enqueue(*queue_measures, node->value);
    queue_measures_soarted(queue_measures, node->right);

}


