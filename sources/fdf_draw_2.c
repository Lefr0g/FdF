/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 10:54:32 by amulin            #+#    #+#             */
/*   Updated: 2015/06/10 16:28:00 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_v2.h"

void	draw_string_center(t_data *d, t_image *item, int color, char *str)
{
	int	pos_x;
	int	len;

	len = ft_strlen(str);
	pos_x = item->width - (len * 10 / 2);
	mlx_string_put(d->mlx_id, d->win_id, pos_x, item->text_height, color, str);
	item->text_height += 20;
}

void	draw_string_left(t_data *d, t_image *item, int color, char *str)
{
	mlx_string_put(d->mlx_id, d->win_id, item->x + 10, item->text_height, color, str);
	item->text_height += 20;
}

void	draw_menu(t_data *d)
{
	if (d->startflag)
	{
		d->startflag = 0;
		expose_hook(d);
	}
	d->menu_bg->text_height = d->menu_bg->y;
	mlx_put_image_to_window(d->mlx_id, d->win_id, d->menu_bg->id, 
			d->menu_x_anchor, d->menu_y_anchor);
	draw_string_center(d, d->menu_bg, 0xFFFFFF, "---- MENU ----");
	d->menu_bg->text_height += 20;
	draw_string_left(d, d->menu_bg, 0xFFFFFF, "   [    : zoom in");
	draw_string_left(d, d->menu_bg, 0xFFFFFF, "   ]    : zoom out");
	draw_string_left(d, d->menu_bg, 0xFFFFFF, "< ^ v > : navigate");
	draw_string_left(d, d->menu_bg, 0xFFFFFF, "(space) : reset navigation");
	draw_string_left(d, d->menu_bg, 0xFFFFFF, "   i    : isometric view");
	draw_string_left(d, d->menu_bg, 0xFFFFFF, "   p    : parallel view");
	draw_string_left(d, d->menu_bg, 0xFFFFFF, "   f    : flat view");
	draw_string_left(d, d->menu_bg, 0xFFFFFF, " 1 - 3  : color palette");
}

void	draw_instructions(t_data *d)
{
	d->menu_bg->text_height = WIN_Y / 2 - 20;
	mlx_put_image_to_window(d->mlx_id, d->win_id, d->menu_bg->id, 
			d->menu_x_anchor, d->menu_y_anchor);
	draw_string_center(d, d->menu_bg, 0xFFFFFF, "Press 'tab' to show menu");
}
/*
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
*/

int		pick_color(t_data *d, int alt)
{
	if (d->palette == 1)
	{
		if (alt > d->range / 3)
			return (0xFFFFFF);
		else if (alt > d->range / 6)
			return (0xA47C48);
		else if (alt > d->range / 20)
			return (0x004D00);
		else if (alt <= 0)
			return (0x000099);
		return (0x008000);
	}
	else if (d->palette == 2)
	{	
		if (alt > d->range / 2)
			return (0x00FFFF);
		else if (alt > d->range / 6)
			return (0x00FF00);
		return (0xFF0000);
	}
	else if (d->palette == 3)
		return (0xFFFFFF);
	return (0x000000);
}

void	draw_pixel(t_tmp *t, t_data *d, float x, float y)
{
	image_pixel_put(d->img, x, y, pick_color(d, d->rawmap[t->j][t->i]));
}
