/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_textframes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 10:54:32 by amulin            #+#    #+#             */
/*   Updated: 2015/06/24 17:13:44 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_string_center(t_data *d, t_image *item, int color, char *str)
{
	int	pos_x;
	int	len;

	len = ft_strlen(str);
	pos_x = item->width - (len * 10 / 2);
	mlx_string_put(d->mlx_id, d->win_id, pos_x, item->text_height,
			color, str);
	item->text_height += 20;
}

void	draw_string_left(t_data *d, t_image *item, int color, char *str)
{
	mlx_string_put(d->mlx_id, d->win_id, item->x + 10, item->text_height,
			color, str);
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
	draw_string_left(d, d->menu_bg, 0xFFFFFF, "   ]    : zoom in");
	draw_string_left(d, d->menu_bg, 0xFFFFFF, "   [    : zoom out");
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
