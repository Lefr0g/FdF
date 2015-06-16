/*
 *
 *
 *
 *
 *
 *
 *
 *
 *
*/

#include "fdf_v2.h"

void	draw_web(t_tmp *t, t_data *d)
{
	/*
	ft_putnbr(t->x);
	ft_putchar('\n');
	ft_putnbr(t->y);
	ft_putchar('\n');
	*/
	draw_pixel(t, d, t->x, t->y);
	
	if (t->j > 0)
	{
		t->x_top = calc_x_iso(d, t->i, t->j - 1);
		t->y_top = calc_y_iso(d, t->i, t->j - 1);
		draw_line_atob(t, d, t->x_top, t->y_top);
	}
	if (t->i > 0)
	{
		t->x_left = calc_x_iso(d, t->i - 1, t->j);
		t->y_left = calc_y_iso(d, t->i - 1, t->j);
//		draw_line_atob(t, d, t->x_left, t->y_left);
	}
	
}

void 	draw_line_atob(t_tmp *t, t_data *d, float xb, float yb)
{
	(void)t;
	(void)d;
	if (ft_abs(t->x - xb) > ft_abs(t->y - yb))
		draw_line_vert(t, d, xb, yb);
//	else
//		draw_line_horz(t, d, xb, yb);
}

void	draw_line_horz(t_tmp *t, t_data *d, float xb, float yb)
{
	float	x;
	float	y;

	if (xb >= t->x)
	{
		x = t->x;
		while (x < xb)
		{
			y = (((x - t->x) * (yb - t->y)) / (xb - t->x)) + t->y;
			image_pixel_put(d->img, x, y, 0xFFFFFF);
			x++;
		}
	}
	else
	{
		x = xb;
		while (x < t->x)
		{
			y = ((x - xb) * (t->y - yb)) / (t->x - xb) + yb;
			image_pixel_put(d->img, x, y, 0xFFFFFF);
			x++;
		}
	}
}

void	draw_line_vert(t_tmp *t, t_data *d, float xb, float yb)
{
	float	x;
	float	y;

	if (yb <= t->y)
	{
		y = t->x;
		while (y < yb)
		{
			x = (((xb - t->x) * (y - t->y)) / (yb - t->y)) + t->x;
			image_pixel_put(d->img, x, y, 0xFFFFFF);
			y++;
		}
	}
	else
	{
		y = yb;
		while (y < t->y)
		{
			x = ((t->x - xb) * (y - yb)) / (t->y - yb) + xb;
			image_pixel_put(d->img, x, y, 0xFFFFFF);
			x++;
		}
	}

/*
	if (xb >= t->x && yb > t->y)
	{
		y = t->y;
		while (y < yb)
		{
			x = (((xb - t->x) * (y - t->y)) / (yb - t->y)) + t->x;
			image_pixel_put(d->img, x, y, 0xFFFFFF);
			y++;
		}
	}
	else if (xb >= 
	*/
}
