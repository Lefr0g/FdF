/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 17:40:06 by amulin            #+#    #+#             */
/*   Updated: 2015/06/10 16:28:07 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_v2.h"

int	refresh(t_data *d)
{
	(void)d;
//	mlx_clear_window(d->mlx_id, d->win_id);
//	expose_hook(d);
	return (0);
}

int	key_hook(int keycode, t_data *d)
{
	if (keycode == ESC)
	{
		ft_putendl("\nProgram terminated by user");
		mlx_destroy_window(d->mlx_id, d->win_id);
		exit(0);
	}
	if (!d->menuflag)
		check_nav_keys(keycode, d);
	if (keycode == TAB && !d->menuflag)
		d->menuflag = 1;
	else if (keycode == TAB && d->menuflag)
		d->menuflag = 0;
//	mlx_clear_window(d->mlx_id, d->win_id);
//	ft_putendl("Running keyhook");
	expose_hook(d);
//	ft_putstr("Key press: ");
//	ft_putnbr(keycode);
//	ft_putchar('\n');
	return (0);
}

int	expose_hook(t_data *d)
{
//	draw_map_raw(d);
	if (d->img->id)
		mlx_destroy_image(d->mlx_id, d->img->id);
	if ((d->img->id = mlx_new_image(d->mlx_id, d->img->width,
					d->img->height)))
		draw_map(d);
//	ft_putstr("Expose check\n");
	if (d->menuflag)
		draw_menu(d);
	return (0);
}

int	draw_loop(t_data *d)
{
	if (!(d->mlx_id = mlx_init()))
		return (-1);
	init_draw(d);
	if (menu_init(d))
		return (-1);
//	mlx_do_key_autorepeatoff(d->mlx_id);
	if (!(d->win_id = mlx_new_window(d->mlx_id, WIN_X, WIN_Y, WIN_TITLE)))
		return (-1);
	mlx_key_hook(d->win_id, &(key_hook), d);
	mlx_expose_hook(d->win_id, &(expose_hook), d);
//	ft_putendl("Loop Check");
	mlx_loop(d->mlx_id);
	return (0);
}
