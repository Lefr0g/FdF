/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 13:10:40 by amulin            #+#    #+#             */
/*   Updated: 2015/05/07 15:34:29 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_v2.h"

int	draw_map_raw(t_data *d)
{
	t_tmp	t;

	t.j = 0;
	while (calc_y(&t, d) < 0)
		t.j++;
	while (t.j < d->linecount && t.y <= WIN_Y)
	{
		t.i = 0;
		while (calc_x(&t, d) < 0)
			t.i++;
		while (t.i < d->meta[t.j] && t.x <= WIN_X)
		{
			if (t.x >= 0 && t.y >= 0)
				draw_pixel(&t, d);
			t.i++;
			calc_x(&t, d);
		}
		t.j++;
		calc_y(&t, d);
	}
	if (d->menuflag)
		draw_menu(d);
	return (0);
}

int	draw_map_iso(t_data *d)
{
	(void)d;
	return (0);
}
