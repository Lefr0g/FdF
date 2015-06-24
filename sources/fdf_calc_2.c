/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_calc_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 10:58:39 by amulin            #+#    #+#             */
/*   Updated: 2015/06/24 16:36:57 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	calc_x_iso(t_data *d, int i, int j)
{
	float	x;

	x = (d->cte1 * i) - (d->cte2 * j);
	x = (x + d->left_added - (d->longestline / 4)) * d->spacing +
		d->left_offset;
	return (x);
}

float	calc_y_iso(t_data *d, int i, int j)
{
	float	y;

	y = -(d->rawmap[j][i] * d->alt_factor) + ((d->cte1 / 2) * i) +
		((d->cte2 / 2) * j);
	y = (y + d->top_added - (d->linecount / 2)) * d->spacing +
		d->top_offset;
	return (y);
}
