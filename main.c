#include <stdio.h>
#include <stdlib.h>
#include "stack_static.h"
#include "queue_static.h"
#include "sll_dinamic.h"
#include "search_bt.h"
#include "temperature_sensor.h"

/**CAMBIÉ LOS T_ELEM DE TODAS LAS ESTRUCTURAS, EN VEZ DE SER READING* LO LLAMÉ READING  **/
/**SE CORRIGIÓ EL PARAMETRO DE sbt_insert_value, AHORA PASA LA PILA ENTERA A UNA FUNCION QUE LLAMA A OTRA ENMASCARADA*/
/** SE AGREGÓ UNA NUEVA FUNCION DE IMPRESION PARA EL SBT **/
/** CODIGO FUNCIONANDO CORRECTAMENTE **/

int main()
{
    stack* day_measures = stack_new();
    sll_node* week_measures = NULL;
    btn* tree_measures = NULL;
    queue* line_measures = queue_new(1440);

    day_measures = stack_set_temperature();

    stack_print(day_measures); /// PILA CORRECTA

    sll_add_day_measures(&week_measures,day_measures); /// LISTA CORRECTA

    sbt_insert_value(&tree_measures,day_measures,btn_measures_cmp);

    sbt_show_tree(tree_measures); /// ARBOL CORRECTO

    queue_measures_soarted(&line_measures,tree_measures);

    queue_print(line_measures); /// COLA CORRECTA

    queue_free(line_measures);
    btn_free(&tree_measures);
    free(week_measures);
    stack_free(day_measures);

    return 0;
}



