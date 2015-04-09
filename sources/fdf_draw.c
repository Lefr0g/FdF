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

int	draw_map(t_data *d)
{
	t_tmp	t;

	if (!(d->mlx_id = mlx_init()))
		return (-1);
	if (!(d->win_id = mlx_new_window(d->mlx_id, WIN_X, WIN_Y, WIN_TITLE)))
		return (-1);
	t.y = 0;
	while (t.y < d->linecount)
	{
		t.x = 0;
		while (t.x < d->meta[t.y])
		{
			ft_putnbr(t.x);
			ft_putchar(' ');
			ft_putnbr(t.y);
			ft_putchar('\n');
			t.x++;
		}
		t.y++;
	}
	mlx_pixel_put(d->mlx_id, d->win_id, 400, 300, 0xFFFFFF);
	mlx_pixel_put(d->mlx_id, d->win_id, 401, 300, 0xFFFFFF);
	mlx_pixel_put(d->mlx_id, d->win_id, 401, 301, 0xFFFFFF);
	mlx_pixel_put(d->mlx_id, d->win_id, 400, 301, 0xFFFFFF);
	mlx_string_put(d->mlx_id, d->win_id, 400, 301, 0xFFFFFF, "Hello World !");
	mlx_string_put(d->mlx_id, d->win_id, 400, 301, 0xFFFFFF, "Hello World !");
	sleep(5);
	return (0);
}
