#ifndef SEARCH_BT_H_INCLUDED
#define SEARCH_BT_H_INCLUDED
#include "temperature_sensor.h"
#define t_elem_btree reading*

typedef struct _btn
{
    t_elem_btree value;
    struct _btn *left;
    struct _btn *right;

}btn;

int btn_measures_cmp(t_elem_btree a, t_elem_btree b);
t_elem_btree _max_elem (t_elem_btree a, t_elem_btree b, int cmp (t_elem_btree, t_elem_btree));
btn* btn_new(t_elem_btree value);
void btn_free(btn** node);
int sbt_insert_value(btn **node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree));
t_elem_btree sbt_get_max_value(btn *node);
btn* sbt_findr(btn *node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree));
int _btn_print(btn *tree, int is_left, int offset, int depth, char s[20][255], void toStr (btn*, char*));
void btn_print(btn *tree, void toStr (btn*, char*));

#endif // SEARCH_BT_H_INCLUDED
