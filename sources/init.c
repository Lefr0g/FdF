/* *****************************************************************************
 *
 *
 *
 *
 *
 *
 *
 *
 *
*/

#include "fdf_v2.h"

void	init_t_tmp(t_tmp *t)
{
	t->i = 0;
	t->j = 0;
	t->k = 0;
	t->pos = 0;
	t->prev = 0;
	t->x = 0;
	t->y = 0;
	t->z = 0;
}

void	init_draw(t_data *d)
{
	d->top_offset = WIN_Y / 2;
	d->left_offset = WIN_X / 2;
	d->spacing = 20;
	d->top_added = 0;
	d->left_added = 0;
}
