/*
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

int	set_proj(t_data *d)
{
	if (!ft_strcmp(d->proj, "iso"))
	{
		d->method_calc_x = &(calc_x_iso);
		d->method_calc_y = &(calc_y_iso);
	}
	else if (!ft_strcmp(d->proj, "parallel"))
	{
		d->method_calc_x = &(calc_x_paral);
		d->method_calc_y = &(calc_y_paral);
	}
	else if (!ft_strcmp(d->proj, "flat"))
	{	
		d->method_calc_x = &(calc_x_flat);
		d->method_calc_y = &(calc_y_flat);
	}
	return (0);
}
