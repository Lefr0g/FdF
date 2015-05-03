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
	if (keycode == 123)
		d->left_added--;
	if (keycode == 124)
		d->left_added++;
	if (keycode == 125)
		d->top_added = d->top_added + 1;
	if (keycode == 126)
		d->top_added = d->top_added - 1;
	if (keycode == 49)
	{
		d->top_added = 0;
		d->left_added = 0;
	}
	refresh(d);
	ft_putstr("Key press: ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	return (0);
}

int	expose_hook(t_data *d)
{
	t_tmp	t;

	t.j = 0;
	while (calc_y(&t, d) < 0)
		t.j++;
	while (t.j < d->linecount && t.y <= WIN_Y)
	{
		t.i = 0;
		while (calc_x(&t, d) < 0)
			t.i++;
		while (t.i < d->meta[t.j] && t.x <= WIN_X)
		{
			if (t.x >= 0 && t.y >= 0)
				draw_pixel(&t, d);
			t.i++;
			calc_x(&t, d);
		}
		t.j++;
		calc_y(&t, d);
	}
	return (0);
}

int	draw_map(t_data *d)
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
