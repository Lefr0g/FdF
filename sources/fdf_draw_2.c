/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 10:54:32 by amulin            #+#    #+#             */
/*   Updated: 2015/05/07 12:15:22 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_v2.h"

void	draw_string_center(t_data *d, int pos_y, int color, char *str)
{
	int	pos_x;
	int	len;

	len = ft_strlen(str);
	pos_x = WIN_X / 2 - (len * 10 / 2);
	mlx_string_put(d->mlx_id, d->win_id, pos_x, pos_y, color, str);
}

void	draw_menu(t_data *d)
{
	t_tmp	t;

	init_t_tmp(&t);
	d->menu_y_anchor = WIN_Y / 3;
	d->menu_x_anchor = WIN_X / 4;
	t.j = d->menu_y_anchor + 1;
	while (t.j <= 2 * d->menu_y_anchor)
	{
		t.i = d->menu_x_anchor + 1;
		while (t.i <= 3 * d->menu_x_anchor)
		{
			mlx_pixel_put(d->mlx_id, d->win_id, t.i, t.j, 0x656565);
			t.i = t.i + 2;
		}
		t.j = t.j + 2;
	}
	draw_string_center(d, d->menu_y_anchor, 0xFFFFFF, "---- MENU ----");
}

void	check_nav_keys(int keycode, t_data *d)
{
	if (keycode == 123)
		d->left_added = d->left_added + my_min_one(my_min_one(d->longestline,
					10), my_min_one(d->spacing, d->spacing_init));
	if (keycode == 124)
		d->left_added = d->left_added - my_min_one(my_min_one(d->longestline,
					10), my_min_one(d->spacing, d->spacing_init));
	if (keycode == 125)
		d->top_added = d->top_added - my_min_one(my_min_one(d->longestline,
					10), my_min_one(d->spacing, d->spacing_init));
	if (keycode == 126)
		d->top_added = d->top_added + my_min_one(my_min_one(d->longestline,
					10), my_min_one(d->spacing, d->spacing_init));
	if (keycode == 30)
		d->spacing = d->spacing * 2;
	if (keycode == 33)
		d->spacing = my_min_one(d->spacing, 2);
	if (keycode == 49)
	{
		d->spacing = d->spacing_init;
		d->top_added = 0;
		d->left_added = 0;
	}
}

int		pick_color(t_tmp *t, t_data *d)
{
	if (d->rawmap[t->j][t->i] > 0)
		return (0xFF0000);
	else if (d->rawmap[t->j][t->i] < 0)
		return (0x00FFAA);
	else
		return (0xFFFFFF);
}

void	draw_pixel(t_tmp *t, t_data *d)
{
	mlx_pixel_put(d->mlx_id, d->win_id, t->x, t->y, pick_color(t, d));
}
