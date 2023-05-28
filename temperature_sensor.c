#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "temperature_sensor.h"
#include "stack_static.h"

stack* stack_set_temperature()
{
    int measures = 1440;

    reading* sample = (reading*)malloc(measures*sizeof(reading));

    stack* sensor = stack_new(measures);

    srand(time(NULL));
    while( measures > 0 )
    {
        sample->minute = rand()%1441;
        sample->temperature = rand()%41-10; // minimo -10 grados valor maximo 40 grados
        stack_push(sensor,sample);
        measures--;
    }

    return sensor;
}






