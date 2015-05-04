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

void	draw_string_center(t_data *d, int posY, int color, char *str)
{
	int	posX;
	int	len;

	len = ft_strlen(str);
	posX	= WIN_X / 2 - (len * 10 / 2);
	mlx_string_put(d->mlx_id, d->win_id, posX, posY, color, str);
}

void	draw_menu(t_data *d)
{
	char	*str;

	str = ft_strdup("---- MENU ----");
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
	draw_string_center(d, d->menu_y_anchor, 0xFFFFFF, str);
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
