/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_colorpix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 10:54:32 by amulin            #+#    #+#             */
/*   Updated: 2015/06/24 17:17:39 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		palette_1(struct s_data *d, int alt)
{
	if (alt > d->range / 3)
		return (0xFFFFFF);
	else if (alt > d->range / 6)
		return (0xA47C48);
	else if (alt > d->range / 20)
		return (0x004D00);
	else if (alt > d->range / 40)
		return (0x008000);
	else if (alt <= 0)
		return (0x000099);
	return (0x75B029);
}

int		palette_2(struct s_data *d, int alt)
{
	if (alt <= 0)
		return (0xFFFF00);
	if (alt > d->range / 2)
		return (0x0000FF);
	if (alt > d->range / 4)
		return (0x00FFFF);
	else if (alt > d->range / 6)
		return (0x00FF00);
	return (0xFF0000);
}

int		palette_3(struct s_data *d, int alt)
{
	(void)d;
	if (alt > 0)
		return (0xFFFFFF);
	return (0x000000);
}

void	draw_pixel(t_tmp *t, t_data *d, float x, float y)
{
	image_pixel_put(d->img, x, y, d->palette(d, d->rawmap[t->j][t->i]));
}
