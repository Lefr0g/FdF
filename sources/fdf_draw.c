/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 17:40:06 by amulin            #+#    #+#             */
/*   Updated: 2015/05/07 13:18:39 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_v2.h"

int	refresh(t_data *d)
{
	mlx_clear_window(d->mlx_id, d->win_id);
	expose_hook(d);
	return (0);
}

int	key_hook(int keycode, t_data *d)
{
	if (keycode == 53)
	{
		ft_putendl("\nProgram terminated by user");
		mlx_destroy_window(d->mlx_id, d->win_id);
		exit(0);
	}
	check_nav_keys(keycode, d);
	if (keycode == 48 && !d->menuflag)
		d->menuflag = 1;
	else if (keycode == 48 && d->menuflag)
		d->menuflag = 0;
	refresh(d);
	ft_putstr("Key press: ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	return (0);
}

int	expose_hook(t_data *d)
{
	draw_map_raw(d);
	return (0);
}

int	draw_loop(t_data *d)
{
	init_draw(d);
	if (!(d->mlx_id = mlx_init()))
		return (-1);
	if (!(d->win_id = mlx_new_window(d->mlx_id, WIN_X, WIN_Y, WIN_TITLE)))
		return (-1);
	mlx_expose_hook(d->win_id, &(expose_hook), d);
	mlx_key_hook(d->win_id, &(key_hook), d);
	mlx_loop(d->mlx_id);
	sleep(5);
	return (0);
}
