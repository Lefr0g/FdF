/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 10:58:39 by amulin            #+#    #+#             */
/*   Updated: 2015/05/27 16:06:42 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_v2.h"

int	calc_x_flat(t_tmp *t, t_data *d)
{
	t->x1 = (t->i - (d->longestline / 2) + d->left_added) * d->spacing +
		d->left_offset;
	return (t->x1);
}

int	calc_y_flat(t_tmp *t, t_data *d)
{
	t->y1 = (t->j - (d->linecount / 2) + d->top_added) * d->spacing + 
		d->top_offset;
	return (t->y1);
}

float	calc_x_iso(t_data *d, int i, int j)
{
	float	x;

	x = (d->cte1 * i) - (d->cte2 * j);
	x = (x + d->left_added - (d->longestline / 4)) * d->spacing + d->left_offset;
	return (x);
}

float	calc_y_iso(t_data *d, int i, int j)
{
	float	y;

	y = -(d->rawmap[j][i] * d->alt_factor) + ((d->cte1 / 2) * i) + ((d->cte2 / 2) * j);
	y = (y + d->top_added - (d->linecount / 2)) * d->spacing + d->top_offset;
	return (y);
}

float	calc_x_paral(t_data *d, int i, int j)
{
	float	x;

	x = i + d->cte3 * -(d->rawmap[j][i] * d->alt_factor);
	x = (x + d->left_added - (d->longestline / 4)) * d->spacing + d->left_offset;
	return (x);
}

float	calc_y_paral(t_data *d, int i, int j)
{
	float	y;

	y = j + (d->cte3 / 2) * -(d->rawmap[j][i] * d->alt_factor);
	y = (y + d->top_added - (d->linecount / 2)) * d->spacing + d->top_offset;
	return (y);
}

/*
// WIP
int	calc_x_y_iso(t_tmp *t, t_data *d)
{
	int	x_tmp;
	int	y_tmp;

	x_tmp = calc_x_flat(t, d);
	y_tmp = calc_y_flat(t, d);

	t->x = (d->cte1 * t->i) - (d->cte2 * t->j);
	t->y = -(d->rawmap[t->j][t->i] * 0.08) + ((d->cte1 / 2) * t->i) + ((d->cte2 / 2) * t->j);
	return (0);
}
*/
