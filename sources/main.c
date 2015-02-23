/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 11:07:06 by amulin            #+#    #+#             */
/*   Updated: 2015/02/18 16:23:33 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_open(char *filename, int *fd)
{
	if (*fd)
	{
		if (close(*fd) == -1)
			return (1);
	}
	*fd = open(filename, O_RDONLY);
	if (*fd == -1)
	{
		ft_putstr(filename);
		ft_putendl(": No such file or directory");
		return (1);
	}
	return (0);
}

int	tbd_displayraw(char *filename, int *fd)
{
	char	*tmp;

	tmp = ft_strnew(0);
	if (close_open(filename, fd))
		return (1);
	while (get_next_line(*fd, &tmp) == 1)
		ft_putendl(tmp);
	return (0);
}

int	my_converttoint(char *str, int	*line)
{
	int	i[4];
	
	i[0] = 0;
	i[1] = 0;
	while (str[i[0]])
	{
		if (ft_isdigit(str[i[0]]))
		{
			line[i[1]] = ft_atoi(&str[i[0]]);
			i[2] = 1;
			i[3] = line[i[1]];
			while (i[3] >= 10)
			{
				i[3] = i[3] / 10;
				i[2]++;
			}
			i[1]++;
			i[0] = i[0] + i[2];
			while (str[i[0]] == '0')
				i[0]++;
		}
		i[0]++;
	}
	return (i[1]);
}

int	my_storeasint(char *filename, int ***map, int *fd)
{
	int		i;
	int		j;
	int		max;
	char	*tmp;

	tmp = ft_strnew(0);
	if (close_open(filename, fd))
		return (1);
	max = 0;
	while (get_next_line(*fd, &tmp) == 1)
		max++;
	*map = (int**)malloc(sizeof(int*) * (max + 1));
	if (close_open(filename, fd))
		return (1);
	map[0][0] = (int*)malloc(sizeof(int) * (max + 1));
	map[0][0][0] = max;
	i = 1;
	while (i <= max)
	{
		get_next_line(*fd, &tmp);
		map[0][i] = (int*)malloc(sizeof(int) * ft_strlen(tmp));
		map[0][0][i] = my_converttoint(tmp, map[0][i]);
		j = 0;
		while (j < map[0][0][i])
		{
			ft_putnbr(map[0][i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
//		ft_putnbr(map[0][0][i]);
//		ft_putendl(" points above");
		i++;
	}
//	ft_putstr("There are ");
//	ft_putnbr(map[0][0][0]);
//	ft_putendl(" lines in this map");
	return (0);
}

int	draw_line(t_params *p)
{
	int	i;

	if (ft_abs(p->X2 - p->X1) >= ft_abs(p->Y2 - p->Y1))
	{
		if (p->X2 - p->X1 >= 0)
		{
			i = p->X1;
			while (i < p->X2)
			{
				mlx_pixel_put(p->id, p->win, i, (i - p->X1) * \
						(p->Y2 - p->Y1) / (p->X2 - p->X1)  \
						+ p->Y1, 0x00FFFF);
				i++;
			}
		}
		else
		{
			i = p->X2;
			while (i < p->X1)
			{
				mlx_pixel_put(p->id, p->win, i, (i - p->X2) * \
						(p->Y1 - p->Y2) / (p->X1 - p->X2)  \
						+ p->Y2, 0xFF00FF);
				i++;
			}
		}
	}
	else
	{
		if (p->Y2 - p->Y1 >= 0)
		{
			i = p->Y1;
			while (i < p->Y2)
			{
				mlx_pixel_put(p->id, p->win, (i - p->Y1) * (p->X2 - p->X1) / \
						(p->Y2 - p->Y1) + p->X1, i, 0xFFFF00);
				i++;
			}
		}
		else
		{
			i = p->Y2;
			while (i < p->Y1)
			{
				mlx_pixel_put(p->id, p->win, (i - p->Y2) * (p->X1 - p->X2) / \
						(p->Y1 - p->Y2) + p->X2, i, 0xFFFFFF);
				i++;
			}
		}
	}
	p->tbd_flag++;
	return (0);
}

int	place_X(int x, int y, t_params *p)
{
	return ((p->cte1 * x - p->cte2 * y) * p->spacing + p->left_offset);
}

int	place_Y(int x, int y, int z, t_params *p)
{
	return (-z + (p->cte1 / 2 * x + p->cte2 / 2 * y) * \
			p->spacing + p->top_offset);
}

int	draw_web(int x, int y, t_params *p)
{
	if (x > 0)
	{
		p->X2 = place_X(x - 1, y, p);
		p->Y2 = place_Y(x - 1, y, p->mapcpy[0][y][x - 1], p);
		draw_line(p);
	}
//	if (x < p->mapcpy[0][0][y + 1])
//		draw_right_line();
	if (y > 1 && x < p->mapcpy[0][0][y - 1])
	{
		p->X2 = place_X(x, y - 1, p);
		p->Y2 = place_Y(x, y - 1, p->mapcpy[0][y - 1][x], p);
		draw_line(p);
	}
//	if (y < p->mapcpy[0][0][0])
//		draw_bottom_line();
	return (0);
}

int	draw_iso(t_params *p)
{
	int			x;
	int 		y;

	y = 1;
	while (y <= p->mapcpy[0][0][0])
	{
		x = 0;
		while (x < p->mapcpy[0][0][y])
		{
			p->X1 = place_X(x, y, p);
			p->Y1 = place_Y(x, y, p->mapcpy[0][y][x], p);
			draw_web(x, y, p);
			if (p->mapcpy[0][y][x] == 0)
			{
				mlx_pixel_put(p->id, p->win, p->X1, p->Y1, 0xFF0000);
			}
			else
			{
				mlx_pixel_put(p->id, p->win, p->X1, p->Y1, 0x00FF00);
			}
			x++;
		}
		y++;
	}
	return (0);
}
/*
int	draw_parall(void *id, void *win, int **map)
{
	int			x;
	int 		y;
	const int	spacing = 20;
	const int	offset = 200;
	const int	cst = 1;

	y = 1;
	while (y <= map[0][0])
	{
		x = 0;
		while (x < map[0][y])
		{
			if (map[y][x] == 0)
			{
				mlx_pixel_put(id, win, (x * spacing) + offset + cst * map[y][x], (y * spacing) + offset + cst / 2 * map[y][x], 0xFF0000);
			}
			else
			{
				mlx_pixel_put(id, win, (x * spacing) + offset + cst * map[y][x], (y * spacing) + offset + cst / 2 * map[y][x], 0x00FF00);
			}
			x++;
		}
		y++;
	}
	return (0);
}
*/
/*
int	draw_coordinates(void *id, void *win, int **map)
{
	int			x;
	int 		y;
	const int	spacing = 20;
	const int	offset = 200;

	y = 1;
	while (y <= map[0][0])
	{
		x = 0;
		while (x < map[0][y])
		{
			if (map[y][x] == 0)
			{
				mlx_pixel_put(id, win, (x * spacing) + offset, (y * spacing) + offset, 0x0000FF);
				mlx_pixel_put(id, win, (x * spacing) + offset, (y * spacing) + offset + 1, 0x0000FF);
				mlx_pixel_put(id, win, (x * spacing) + offset + 1, (y * spacing) + offset + 1, 0x0000FF);
				mlx_pixel_put(id, win, (x * spacing) + offset + 1, (y * spacing) + offset, 0x0000FF);
			}
			else
			{
				mlx_pixel_put(id, win, (x * spacing) + offset, (y * spacing) + offset, 0xFFFFFF);
				mlx_pixel_put(id, win, (x * spacing) + offset, (y * spacing) + offset + 1, 0xFFFFFF);
				mlx_pixel_put(id, win, (x * spacing) + offset + 1, (y * spacing) + offset + 1, 0xFFFFFF);
				mlx_pixel_put(id, win, (x * spacing) + offset + 1, (y * spacing) + offset, 0xFFFFFF);
			}
			x++;
//			usleep(5000);
		}
		y++;
	}
	return (0);
}
*/

/*
 * Structure de la map :
 *
 * | nombre de lignes | nombre d'ints entete | nb de points ligne 1 | nb pts ligne 2 | ... |
 * | p1 | p2 | p3 |
 * | p4 | p5 | p6 | p7 | p8 |
 * | p9 | ... |
 * | ... | pn |
 *
*/

int	expose_hook(t_params *p)
{
//	draw_coordinates(p->id, p->win, *(p->mapcpy));
//	draw_parall(p->id, p->win, *(p->mapcpy));
	draw_iso(p);
	return (0);
}

int	key_hook(int keycode, t_params *p)
{
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == 65307)
	{
		mlx_destroy_window(p->id, p->win);
		ft_putchar('\n');
		ft_putendl("All fine.");
		exit(0);
	}
	if (keycode == 65362)
		p->top_offset = p->top_offset - p->arrow_step;
	if (keycode == 65364)
		p->top_offset = p->top_offset + p->arrow_step;
	if (keycode == 65363)
		p->left_offset = p->left_offset + p->arrow_step;
	if (keycode == 65361)
		p->left_offset = p->left_offset - p->arrow_step;
	if (keycode == 93)
		p->spacing = p->spacing * p->zoom_step;
	if (keycode == 91)
		p->spacing = p->spacing / p->zoom_step;
	mlx_clear_window(p->id, p->win);
	expose_hook(p);
	return (0);
}

int	params_init(t_params *p)
{
	p->spacing = 20;
	p->left_offset = 300;
	p->top_offset = 200;
	p->cte1 = 1;
	p->cte2 = 1;
	p->tbd_flag = 0;
	p->arrow_step = 10;
	p->zoom_step = 2;
	return (0);
}

int	main(int argc, char **argv)
{
	int			fd;
	int			***map;
	t_params	p;

	params_init(&p);
	(void)map;
	fd = 0;
	map = (int***)malloc(sizeof(int**));
	if (argc == 1)
	{
		ft_putstr("usage : ./fdf file1\n");
		return (0);
	}
	if (close_open(argv[1], &fd))
		return (1);
	ft_putendl("Printing input file...");
	tbd_displayraw(argv[1], &fd);
	ft_putchar('\n');
	ft_putendl("Converting map...");
	if (my_storeasint(argv[1], map, &fd))
		return (1);
	ft_putendl("\nStarting visuals...");
	p.id = mlx_init();
	p.mapcpy = map;
	if (p.id)
	{
		p.win = mlx_new_window(p.id, 800, 600, "FdF");
		if (p.win)
		{
			mlx_key_hook(p.win, &(key_hook), &p);
			mlx_expose_hook(p.win, &(expose_hook), &p);
			mlx_loop(p.id);
		}
	}
	return (0);
}
