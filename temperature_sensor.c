#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "temperature_sensor.h"
#include "stack_static.h"

/**
stack_set_temperature() SETEA LAS MEDICIONES DE TEMPERATURAS ALEATORIAS EN UNA PILA, EN UN RANGO DE -10 A 40 GRADOS EN MINUTOS ALEATORIOS
DURANTE EL DIA (DE 0 A 1440). LA FUNCION DEVUELVE UN PUNTERO A UNA PILA
**/

stack* stack_set_temperature()
{
    int measures = 1440;
    stack* sensor = stack_new();
    reading sample;

    srand(time(NULL));
    while( measures > 0 )
    {
        sample.minute = rand()%1441;
        //printf("minuto %d ", sample.minute);
        sample.temperature = rand()%41-10; // minimo -10 grados valor maximo 40 grados
        //printf("temperatura %d \n", sample.temperature);
        stack_push(sensor,sample);
        measures--;
    }
    return(sensor);
}






