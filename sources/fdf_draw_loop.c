/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 17:40:06 by amulin            #+#    #+#             */
/*   Updated: 2015/07/01 16:34:11 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_data *d)
{
	if (keycode == ESC)
		ending_routine(d);
	if (!d->menuflag)
		check_all_keys(keycode, d);
	if (keycode == TAB && !d->menuflag)
		d->menuflag = 1;
	else if (keycode == TAB && d->menuflag)
		d->menuflag = 0;
	expose_hook(d);
	return (0);
}

int	expose_hook(t_data *d)
{
	if (d->img->id)
		mlx_destroy_image(d->mlx_id, d->img->id);
	set_proj(d);
	if ((d->img->id = mlx_new_image(d->mlx_id, d->img->width,
					d->img->height)))
		draw_map(d);
	if (d->startflag)
		draw_instructions(d);
	if (d->menuflag)
		draw_menu(d);
	return (0);
}

int	loop_hook(t_data *d)
{
	if (d->startflag)
	{
		d->starttimer++;
		if (d->starttimer > 100000)
		{
			d->startflag = 0;
			expose_hook(d);
		}
	}
	return (0);
}

int	draw_loop(t_data *d)
{
	if (!(d->mlx_id = mlx_init()))
		return (-1);
	init_draw(d);
	if (menu_init(d))
		return (-1);
	if (!(d->win_id = mlx_new_window(d->mlx_id, WIN_X, WIN_Y, WIN_TITLE)))
		return (-1);
	mlx_key_hook(d->win_id, &(key_hook), d);
	mlx_expose_hook(d->win_id, &(expose_hook), d);
	mlx_loop_hook(d->mlx_id, &(loop_hook), d);
	mlx_loop(d->mlx_id);
	return (0);
}
