/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 15:54:51 by amulin            #+#    #+#             */
/*   Updated: 2015/06/24 16:38:27 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int	set_palette(t_data *d, int val)
{
	if (val == 1)
		d->palette = &(palette_1);
	else if (val == 2)
		d->palette = &(palette_2);
	else if (val == 3)
		d->palette = &(palette_3);
	return (0);
}
