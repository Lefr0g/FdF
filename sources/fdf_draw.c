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
		ft_putendl("\nProgram terminated by user");
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

	d->top_offset = WIN_Y / 2;
	d->left_offset = WIN_X / 2;
	t.j = 0;
	while ((t.y = (t.j - (d->linecount / 2)) * d->spacing + d->top_offset) < 0)
		t.j++;
	d->spacing = 10;
	while (t.j < d->linecount && t.y <= WIN_Y)
	{
		t.i = 0;
		while ((t.x = (t.i - (d->longestline / 2)) * d->spacing + d->left_offset) < 0)
			t.i++;
		while (t.i < d->meta[t.j] && t.x <= WIN_X)
		{
			if (t.x >= 0 && t.y >= 0)
				mlx_pixel_put(d->mlx_id, d->win_id, t.x, t.y, 0xFFFFFF);
			t.i++;
			t.x = (t.i - (d->longestline / 2)) * d->spacing + d->left_offset;
		}
		t.j++;
		t.y = (t.j - (d->linecount / 2)) * d->spacing + d->top_offset;
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
