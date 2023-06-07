#ifndef SEARCH_BT_H_INCLUDED
#define SEARCH_BT_H_INCLUDED
#include "temperature_sensor.h"
#include "stack_static.h"
#define t_elem_btree reading

typedef struct _btn
{
    t_elem_btree value;
    struct _btn *left;
    struct _btn *right;

}btn;

btn* btn_new(t_elem_btree value);
void btn_free(btn** node);
int btn_measures_cmp(t_elem_btree a, t_elem_btree b);
void _sbt_insert_value(btn **node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree));
void sbt_insert_value(btn **node, stack* day_measures, int cmp (t_elem_btree, t_elem_btree));
void sbt_print_tree(btn* node, char str[]);
void sbt_show_tree(btn* root);

#endif // SEARCH_BT_H_INCLUDED
