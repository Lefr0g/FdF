/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 13:24:56 by amulin            #+#    #+#             */
/*   Updated: 2015/06/10 15:58:44 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_v2.h"

void	init_t_tmp(t_tmp *t)
{
	t->i = 0;
	t->j = 0;
	t->k = 0;
	t->pos = 0;
	t->prev = 0;
	t->x = 0;
	t->y = 0;
	t->z = 0;
	t->flag = 0;
}

void	init_draw(t_data *d)
{
	d->top_offset = WIN_Y / 2;
	d->left_offset = WIN_X / 2;
	d->spacing_init = my_min_one(WIN_X, d->longestline);
	d->spacing = d->spacing_init;
	d->top_added = 0;
	d->left_added = 0;
	d->menuflag = 0;
	d->cte1 = 1;
	d->cte2 = 1;
	d->img = (t_image*)malloc(sizeof(t_image));
	*(d->img) = image_init(WIN_X, WIN_Y);
}
