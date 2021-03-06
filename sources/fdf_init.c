/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 13:24:56 by amulin            #+#    #+#             */
/*   Updated: 2015/07/01 18:10:41 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		init_t_tmp(t_tmp *t)
{
	t->buf = ft_strnew(BUF_SIZE);
	t->i = 0;
	t->j = 0;
	t->k = 0;
	t->pos = 0;
	t->prev = 0;
	t->x1 = 0;
	t->y1 = 0;
	t->z1 = 0;
	t->x2 = 0;
	t->y2 = 0;
	t->z2 = 0;
	t->flag = 0;
}

void		init_draw(t_data *d)
{
	d->top_offset = WIN_Y / 2;
	d->left_offset = WIN_X / 2;
	d->spacing_init = my_min_one(WIN_X, d->longestline);
	d->spacing = d->spacing_init;
	d->top_added = 0;
	d->left_added = 0;
	d->startflag = 1;
	d->menuflag = 0;
	d->starttimer = 0;
	d->cte1 = 1;
	d->cte2 = 1;
	d->cte3 = 1;
	d->img = (t_image*)malloc(sizeof(t_image));
	*(d->img) = image_init(d->mlx_id, WIN_X, WIN_Y);
	set_proj(d);
	d->alt_factor = (d->longestline + d->linecount);
	d->alt_factor = d->alt_factor / (d->range * 50);
}

t_image		image_init(void *mlx_id, int width, int height)
{
	t_image	img;

	img.mlx = mlx_id;
	img.x = 0;
	img.y = 0;
	img.endian = (int*)malloc(sizeof(int));
	*(img.endian) = 0;
	img.width = width;
	img.height = height;
	img.id = NULL;
	img.bytes_per_pixel = 4;
	img.depth = (int*)malloc(sizeof(int));
	*(img.depth) = img.bytes_per_pixel * 8;
	img.size_line = (int*)malloc(sizeof(int));
	*(img.size_line) = img.bytes_per_pixel * img.width;
	return (img);
}

int			menu_init(t_data *d)
{
	d->menu_x_anchor = WIN_X / 4;
	d->menu_y_anchor = WIN_Y / 3;
	d->menu_bg = (t_image*)malloc(sizeof(t_image));
	*(d->menu_bg) = image_init(d->mlx_id, WIN_X / 2, WIN_Y / 3 + 20);
	d->menu_bg->id = mlx_new_image(d->menu_bg->mlx, d->menu_bg->width,
			d->menu_bg->height);
	d->menu_bg->str = mlx_get_data_addr(d->menu_bg->id,
			d->menu_bg->depth, d->menu_bg->size_line,
			d->menu_bg->endian);
	d->menu_bg->text_height = d->menu_bg->y;
	d->menu_bg->x = 0;
	d->menu_bg->y = 0;
	while (d->menu_bg->y < (WIN_Y / 3) + 20)
	{
		d->menu_bg->x = 0;
		while (d->menu_bg->x++ < WIN_X / 2)
			image_pixel_put(d->menu_bg, d->menu_bg->x,
					d->menu_bg->y, 0x60000000);
		d->menu_bg->y++;
	}
	d->menu_bg->x = d->menu_x_anchor;
	d->menu_bg->y = d->menu_y_anchor;
	return (0);
}
