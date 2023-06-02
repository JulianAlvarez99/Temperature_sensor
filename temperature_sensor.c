#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "temperature_sensor.h"
#include "stack_static.h"

void stack_set_temperature(stack** sensor)
{
    int measures = 1440;

    reading* sample = (reading*)malloc(measures*sizeof(reading));

    //stack* sensor = stack_new(measures);

    srand(time(NULL));
    while( measures > 0 )
    {
        sample->minute = rand()%1441;
        //printf("minuto %d ", sample->minute);
        sample->temperature = rand()%41-10; // minimo -10 grados valor maximo 40 grados
        //printf("temperatura %d \n", sample->temperature);
        stack_push(*sensor,sample);
        //stack_print(*sensor);
        measures--;
    }
}






