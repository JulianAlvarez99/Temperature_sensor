#include <stdio.h>
#include <stdlib.h>
#include "stack_static.h"
#include "queue_static.h"
#include "sll_dinamic.h"
#include "search_bt.h"
#include "temperature_sensor.h"

/***
-LA FUNCION sbt_insert_value(..) [LINEA 21] ME TIRA UN ERROR DE QUE HAGO UN CASTEO DE UN PUNTERO PARA UN ENTERO, NO SE A QUE SE DEBE
EL WARNING SI EL TIPO DE DATO ES EL TIPO READING*

-AL MOMENTO DE DEBUGGEAR EL PROGRAMA ME PARA EN LA FUNCION DE ENQUEUE (QUEUE_STATIC.C) CUANDO VALIDA SI LA COLA ESTA COMPLETA.
SI YO HAGO UN LLAMADO A LA FUNCION QUEUE_NEW CUANDO CREO MI VARIABLE LINE_MEASURES EL PROGRAMA CORRE CORRECTAMENTE PERO AL MOMENTO DE HACER UN PRINT
DE LA COLA SOLO ME IMPRIME UN CERO***/

int main()
{
    stack* day_measures = NULL;
    sll_node* week_measures = NULL;
    btn* tree_measures = NULL;
    queue* line_measures = NULL;


    day_measures = stack_set_temperature();
    sll_add_day_measures(&week_measures,day_measures);
    sbt_insert_value(&tree_measures,stack_top(day_measures),btn_measures_cmp(stack_pop(&day_measures->head),stack_top(day_measures)));
    queue_measures_soarted(&line_measures,tree_measures);
    queue_print(line_measures);

    queue_free(line_measures);
    btn_free(&tree_measures);
    free(week_measures);
    stack_free(day_measures);

    return 0;
}
