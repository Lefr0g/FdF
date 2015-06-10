/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 13:10:40 by amulin            #+#    #+#             */
/*   Updated: 2015/05/27 16:06:53 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_v2.h"

int	draw_map_raw(t_data *d)
{
	t_tmp	t;

	t.j = 0;
	while (calc_y_flat(&t, d) < 0)
		t.j++;
	while (t.j < d->linecount && t.y <= WIN_Y)
	{
		t.i = 0;
		while (calc_x_flat(&t, d) < 0)
			t.i++;
		while (t.i < d->meta[t.j] && t.x <= WIN_X)
		{
			calc_x_flat(&t, d);
			if (t.x >= 0 && t.y >= 0)
				draw_pixel(&t, d);
			t.i++;
		}
		t.j++;
		calc_y_flat(&t, d);
	}
	return (0);
}

int	draw_map_iso(t_data *d)
{
	t_tmp	t;

	init_t_tmp(&t);
	while (t.j < d->linecount)
	{
		t.i = 0;
		while (t.i < d->meta[t.j])
		{
			calc_x_iso(&t, d);
			calc_y_iso(&t, d);
			if (t.x >= 0 && t.x <= WIN_X && t.y >= 0 && t.y <= WIN_Y)
				draw_pixel(&t, d);
			t.i++;
		}
		t.j++;
	}
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
/*
int	draw_map_iso(t_data *d)
{
	t_tmp	t;
//	d->spacing = 20;

	t.j = 0;
//	while (calc_y_iso(&t, d) < 0)
//		t.j++;
	while (t.j < d->linecount)
	{
		t.i = 0;
//		while (calc_x_iso(&t, d) < 0)
//			t.i++;
		while (t.i < d->meta[t.j])
		{
			calc_x_y_iso(&t, d);
//			if (t.x >= 0 && t.y >= 0)
				draw_pixel(&t, d);
			t.i++;
		}
		t.j++;
	}
	if (d->menuflag)
		draw_menu(d);
	return (0);
}
*/