/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 17:40:06 by amulin            #+#    #+#             */
/*   Updated: 2015/04/09 19:01:44 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_v2.h"

int	key_hook(int keycode, t_data *d)
{
	if (keycode == 53)
	{
		ft_putendl("Program terminated by user");
		mlx_destroy_window(d->mlx_id, d->win_id);
		exit(0);
	}
	ft_putstr("Key press: ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	return (0);
}

int	expose_hook(t_data *d)
{
	t_tmp	t;

	t.y = 0;
	while (t.y < d->linecount)
	{
		t.x = 0;
		while (t.x < d->meta[t.y])
		{
			mlx_pixel_put(d->mlx_id, d->win_id, t.x, t.y, 0xFFFFFF);
			t.x++;
		}
		t.y++;
	}
	return (0);
}

int	draw_map(t_data *d)
{

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
