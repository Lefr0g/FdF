/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 13:10:40 by amulin            #+#    #+#             */
/*   Updated: 2015/07/01 16:19:10 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	draw_map(t_data *d)
{
	t_tmp	t;
	int		max_height;

	max_height = d->range * d->spacing;
	init_t_tmp(&t);
	d->img->str = mlx_get_data_addr(d->img->id, d->img->depth,
		d->img->size_line, d->img->endian);
	while (t.j < d->linecount)
	{
		t.i = 0;
		while (t.i < d->meta[t.j])
		{
			t.x1 = d->method_calc_x(d, t.i, t.j);
			t.y1 = d->method_calc_y(d, t.i, t.j);
			if (t.x1 >= 0 - max_height / 2 &&
					t.x1 < WIN_X + max_height / 2 &&
					t.y1 >= 0 - max_height / 2 &&
					t.y1 < WIN_Y + max_height / 2)
				draw_web(&t, d);
			t.i++;
		}
		t.j++;
	}
	expose_img(d, 0, 0);
	return (0);
}
