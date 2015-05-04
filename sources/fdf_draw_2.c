/* *****************************************************************************
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

void	draw_menu(t_data *d)
{
	char	*str;

	str = ft_strdup("---- MENU ----");
	t_tmp	t;
	
	init_t_tmp(&t);
	t.j = WIN_Y / 3;
	while (t.j <= 2 * WIN_Y / 3)
	{
		t.i = WIN_X / 4;
		while (t.i <= 3 * WIN_X / 4)
		{
			mlx_pixel_put(d->mlx_id, d->win_id, t.i, t.j, 0xCCCCCC);
			t.i = t.i + 2;
		}
		t.j = t.j + 2;
	}
	mlx_string_put(d->mlx_id, d->win_id, 0, 0, 0xFFFFFF, str);
}

void	check_nav_keys(int keycode, t_data *d)
{
	if (keycode == 123)
		d->left_added++;
	if (keycode == 124)
		d->left_added--;
	if (keycode == 125)
		d->top_added--;
	if (keycode == 126)
		d->top_added++;
	if (keycode == 30)
		d->spacing = d->spacing * 2;
	if (keycode == 33)
	{	
		d->spacing = d->spacing / 2;
		if (d->spacing < 1)
			d->spacing = 1;
	}
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
