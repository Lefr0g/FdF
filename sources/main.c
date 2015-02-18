/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 11:07:06 by amulin            #+#    #+#             */
/*   Updated: 2015/02/18 15:19:38 by amulin           ###   ########.fr       */
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

/*
int	my_store(char *filename, char ***str, int *fd)
{
	int		i;
	int		max;
	char	*tmp;

	tmp = ft_strnew(0);
	if (close_open(filename, fd))
		return (1);
	max = 0;
	while (get_next_line(*fd, &tmp) == 1)
		max++;
	*str = (char**)malloc(sizeof(char*) * max);
	if (close_open(filename, fd))
		return (1);
	i = 0;
	while (i < max)
	{
		str[0][i] = ft_strnew(0);
		get_next_line(*fd, &str[0][i]);
		ft_putendl(str[0][i]);
		i++;
	}
	return (0);
}
*/
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
	int		lenline;
	char	*tmp;

	tmp = ft_strnew(0);
	if (close_open(filename, fd))
		return (1);
	max = 0;
	while (get_next_line(*fd, &tmp) == 1)
		max++;
	*map = (int**)malloc(sizeof(int*) * max);
	if (close_open(filename, fd))
		return (1);
	i = 0;
	while (i < max)
	{
		get_next_line(*fd, &tmp);
		map[0][i] = (int*)malloc(sizeof(int) * ft_strlen(tmp));
		lenline = my_converttoint(tmp, map[0][i]);
		j = 0;
		while (j < lenline)
		{
			ft_putnbr(map[0][i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	return (0);
}

int	draw_rectangle(void *id, void *win)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < 200)
	{
		while (y < 100)
		{
			mlx_pixel_put(id, win, 400 + x, 300 + y, 0xFFFFFF);
			y += 2;
		}
		y = 0;
		x += 2;
	}
	return (0);
}
/*
int	draw_coordinates(void *id, void *win, int *map)
{
	int	x;
	int y;

	x = 0;
	while ()
	mlx_pixel_put(id, win, )
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
int	main(int argc, char **argv)
{
	int		fd;
	char	***str;
	int		***map;
	void	*id;
	void	*win;

	(void)map;
	(void)str;
	fd = 0;
	str = (char***)malloc(sizeof(char**));
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
	ft_putendl("Starting visuals...");
	id = mlx_init();
	if (id)
	{
		win = mlx_new_window(id, 800, 600, "Hello!");
		if (win)
		{
			draw_rectangle(id, win);
//			draw_coordinates(id, win, *map);
			sleep(5);
		}
	}
	fd = mlx_destroy_window(id, win);
	ft_putnbr(fd);
	ft_putchar('\n');
	ft_putendl("All fine.");
	return (0);
}
