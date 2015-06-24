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

void	reinit_pos(t_data *d)
{
	d->spacing = d->spacing_init;
	d->top_added = 0;
	d->left_added = 0;
}

int		check_nav_keys(int keycode, t_data *d)
{
	if (keycode == LEFT_ARROW)
		d->left_added = d->left_added + my_min_one(my_min_one(d->longestline,
					10), my_min_one(d->spacing, d->spacing_init));
	else if (keycode == RIGHT_ARROW)
		d->left_added = d->left_added - my_min_one(my_min_one(d->longestline,
					10), my_min_one(d->spacing, d->spacing_init));
	else if (keycode == DOWN_ARROW)
		d->top_added = d->top_added - my_min_one(my_min_one(d->longestline,
					10), my_min_one(d->spacing, d->spacing_init));
	else if (keycode == TOP_ARROW)
		d->top_added = d->top_added + my_min_one(my_min_one(d->longestline,
					10), my_min_one(d->spacing, d->spacing_init));
	else if (keycode == CLOSE_BRACKET && d->spacing < WIN_X)
		d->spacing = d->spacing * 2;
	else if (keycode == OPEN_BRACKET)
		d->spacing = my_min_one(d->spacing, 2);
	else if (keycode == SPACEBAR)
		reinit_pos(d);
	else
		return (1);
	return (0);
}

int		check_proj_keys(int keycode, t_data *d)
{
	if (keycode == KEY_I)
	{
		free(d->proj);
		d->proj = ft_strdup("iso");
	}
	else if (keycode == KEY_P)
	{
		free(d->proj);
		d->proj = ft_strdup("parallel");
	}
	else if (keycode == KEY_F)
	{
		free(d->proj);
		d->proj = ft_strdup("flat");
	}
	return (0);
}

int		check_palette_keys(int keycode, t_data *d)
{
	if (keycode == KEY_1)
		d->palette = 1;
	else if (keycode == KEY_2)
		d->palette = 2;
	else if (keycode == KEY_3)
		d->palette = 3;
	return (0);
}

int		check_keys(int keycode, t_data *d)
{
	check_nav_keys(keycode, d);
	check_proj_keys(keycode, d);
	check_palette_keys(keycode, d);
	return (0);
}
