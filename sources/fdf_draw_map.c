/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 13:10:40 by amulin            #+#    #+#             */
/*   Updated: 2015/06/10 16:29:21 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_v2.h"

int	draw_map_raw(t_data *d)
{
	t_tmp	t;

	init_t_tmp(&t);
	d->img->str = mlx_get_data_addr(d->img->id, d->img->depth, 
		d->img->size_line, d->img->endian);
	t.j = 0;
	while (calc_y_flat(&t, d) < 0)
		t.j++;
	while (t.j < d->linecount && t.y1 <= WIN_Y)
	{
		t.i = 0;
		while (calc_x_flat(&t, d) < 0)
			t.i++;
		while (t.i < d->meta[t.j] && t.x1 <= WIN_X)
		{
			calc_x_flat(&t, d);
			if (t.x1 >= 0 && t.y1 >= 0)
				draw_pixel(&t, d, t.x1, t.y1);
			t.i++;
		}
		t.j++;
		calc_y_flat(&t, d);
	}
	expose_img(d, 0, 0);
	return (0);
}

int	draw_map_iso(t_data *d)
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
			t.x1 = calc_x_iso(d, t.i, t.j);
			t.y1 = calc_y_iso(d, t.i, t.j);
			if (t.x1 >= 0 - 2 * WIN_X && t.x1 < 3 * WIN_X && t.y1 >= 0 - WIN_Y - max_height && t.y1 <  2 * WIN_Y + max_height)
				draw_web(&t, d);
			t.i++;
		}
		t.j++;
	}
	expose_img(d, 0, 0);
	return (0);
}

int	my_clear_window(t_data *d)
{
	t_tmp	t;

	init_t_tmp(&t);
	while (t.j <= WIN_Y)
	{
		t.i = 0;
		while (t.i <= WIN_X)
		{
			mlx_pixel_put(d->mlx_id, d->win_id, t.i, t.j, 0x000000);
			t.i++;
		}
		t.j++;
	}
	return (0);
}
