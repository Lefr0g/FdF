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

int	draw_iso(void *id, void *win, int **map)
{
	int			x;
	int 		y;
	int			X;
	int			Y;
	const int	spacing = 20;
	const int	left_offset = 300;
	const int	top_offset = 200;
	const float	cte1 = 1;
	const float	cte2 = 1;

	y = 1;
	while (y <= map[0][0])
	{
		x = 0;
		while (x < map[0][y])
		{
			X = (cte1 * x - cte2 * y) * spacing + left_offset;
			Y = -map[y][x] + (cte1 / 2 * x + cte2 / 2 * y) * spacing + top_offset;
			if (map[y][x] == 0)
			{
				mlx_pixel_put(id, win, X, Y, 0xFF0000);
			}
			else
			{
				mlx_pixel_put(id, win, X, Y, 0x00FF00);
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
	draw_iso(p->id, p->win, *(p->mapcpy));
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
	return (0);
}
int	main(int argc, char **argv)
{
	int			fd;
	int			***map;
	t_params	p;

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
