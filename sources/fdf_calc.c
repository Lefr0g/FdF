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
	t->x = (t->i - (d->longestline / 2) + d->left_added) * d->spacing +
		d->left_offset;
	return (t->x);
}

int	calc_y_flat(t_tmp *t, t_data *d)
{
	t->y = (t->j - (d->linecount / 2) + d->top_added) * d->spacing + 
		d->top_offset;
	return (t->y);
}

int	calc_x_iso(t_tmp *t, t_data *d)
{
//	int	x_tmp;

//	x_tmp = calc_x(t, d);
	t->x = (d->cte1 * t->i) - (d->cte2 * t->j);
	t->x = (t->x + d->left_added) * d->spacing + d->left_offset;
	return (t->x);
}

int	calc_y_iso(t_tmp *t, t_data *d)
{
//	int y_tmp;

//	y_tmp = calc_y(t, d);
	t->y = -(d->rawmap[t->j][t->i] / 10) + ((d->cte1 / 2) * t->i) + ((d->cte2 / 2) * t->j);
	t->y = (t->y + d->top_added - (d->linecount / 2)) * d->spacing + d->top_offset;
	return (t->y);
}


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
