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

int		pick_color(t_tmp *t, t_data *d)
{
	if (d->rawmap[t->j][t->i] > 0)
		return (0xFF0000);
	else
		return (0xFFFFFF);
}

void	draw_pixel(t_tmp *t, t_data *d)
{
	mlx_pixel_put(d->mlx_id, d->win_id, t->x, t->y, pick_color(t, d));
}
