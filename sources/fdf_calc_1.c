/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_calc_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 10:58:39 by amulin            #+#    #+#             */
/*   Updated: 2015/06/24 16:37:05 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	calc_x_flat(t_data *d, int i, int j)
{
	float	x;

	(void)j;
	x = i;
	x = (x + d->left_added - (d->longestline / 4)) * d->spacing +
		d->left_offset;
	return (x);
}

float	calc_y_flat(t_data *d, int i, int j)
{
	float	y;

	(void)i;
	y = j;
	y = (y + d->top_added - (d->linecount / 2)) * d->spacing +
		d->top_offset;
	return (y);
}

float	calc_x_paral(t_data *d, int i, int j)
{
	float	x;

	x = i + d->cte3 * -(d->rawmap[j][i] * d->alt_factor);
	x = (x + d->left_added - (d->longestline / 4)) * d->spacing +
		d->left_offset;
	return (x);
}

float	calc_y_paral(t_data *d, int i, int j)
{
	float	y;

	y = j + (d->cte3 / 2) * -(d->rawmap[j][i] * d->alt_factor);
	y = (y + d->top_added - (d->linecount / 2)) * d->spacing +
		d->top_offset;
	return (y);
}
