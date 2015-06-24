/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 15:49:59 by amulin            #+#    #+#             */
/*   Updated: 2015/06/24 17:32:05 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_web(t_tmp *t, t_data *d)
{
	t->z1 = d->rawmap[t->j][t->i];
	if (t->j > 0 && t->i < d->meta[t->j - 1])
	{
		t->x2 = d->method_calc_x(d, t->i, t->j - 1);
		t->y2 = d->method_calc_y(d, t->i, t->j - 1);
		t->z2 = d->rawmap[t->j - 1][t->i];
		draw_line_atob(t, d);
	}
	if (t->i > 0 && t->i < d->meta[t->j])
	{
		t->x2 = d->method_calc_x(d, t->i - 1, t->j);
		t->y2 = d->method_calc_y(d, t->i - 1, t->j);
		t->z2 = d->rawmap[t->j][t->i - 1];
		draw_line_atob(t, d);
	}
}

void	draw_line_atob(t_tmp *t, t_data *d)
{
	if (ft_abs(t->x2 - t->x1) < ft_abs(t->y2 - t->y1))
		draw_line_vert(t, d);
	else
		draw_line_horz(t, d);
}

void	draw_line_horz(t_tmp *t, t_data *d)
{
	if (t->x2 >= t->x1)
	{
		t->x = t->x1;
		while (t->x <= t->x2)
		{
			t->y = (((t->x - t->x1) * (t->y2 - t->y1)) / (t->x2 - t->x1)) +
				t->y1;
			t->alt = get_alt(t->x - t->x1, t->x2 - t->x1, t->z1, t->z2);
			image_pixel_put(d->img, t->x, t->y, d->palette(d, t->alt));
			t->x++;
		}
	}
	else
	{
		t->x = t->x2;
		while (t->x <= t->x1)
		{
			t->y = ((t->x - t->x2) * (t->y1 - t->y2)) / (t->x1 - t->x2) +
				t->y2;
			t->alt = get_alt(t->x - t->x2, t->x1 - t->x2, t->z2, t->z1);
			image_pixel_put(d->img, t->x, t->y, d->palette(d, t->alt));
			t->x++;
		}
	}
}

void	draw_line_vert(t_tmp *t, t_data *d)
{
	if (t->y2 < t->y1)
	{
		t->y = t->y2;
		while (t->y <= t->y1)
		{
			t->x = (((t->x2 - t->x1) * (t->y - t->y1)) / (t->y2 - t->y1)) +
				t->x1;
			t->alt = get_alt(t->y - t->y1, t->y2 - t->y1, t->z1, t->z2);
			image_pixel_put(d->img, t->x, t->y, d->palette(d, t->alt));
			t->y++;
		}
	}
	else
	{
		t->y = t->y1;
		while (t->y <= t->y2)
		{
			t->x = ((t->x1 - t->x2) * (t->y - t->y2)) / (t->y1 - t->y2) + t->x2;
			t->alt = get_alt(t->y - t->y2, t->y1 - t->y2, t->z2, t->z1);
			image_pixel_put(d->img, t->x, t->y, d->palette(d, t->alt));
			t->y++;
		}
	}
}

int		get_alt(int posseg, int lenseg, int alt1, int alt2)
{
	int	alt;

	if (!lenseg)
		lenseg = 1;
	alt = ((posseg * (alt2 - alt1)) / lenseg) + alt1;
	return (alt);
}
