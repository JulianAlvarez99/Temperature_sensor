#ifndef QUEUE_STATIC_H_INCLUDED
#define QUEUE_STATIC_H_INCLUDED
#include "temperature_sensor.h"
#include "search_bt.h"
#define t_elemq reading

typedef struct _queue{
    t_elemq* a;
    int head;   //mark the first element
    int tail;   //mark the next empty position
    int maxsize;
    int count;
} queue;

queue* queue_new(int maxsize);
void queue_free (queue* q);
int queue_getmaxsize(queue* q);
int queue_isfull (queue* q);
int queue_isempty (queue* q);
void enqueue (queue* q, t_elemq elem);
t_elemq dequeue (queue* q);
void queue_print(queue* q);
void queue_measures_soarted(queue** queue_measures, btn* node);

#endif // QUEUE_STATIC_H_INCLUDED
