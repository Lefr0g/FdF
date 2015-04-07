/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_v2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 11:07:06 by amulin            #+#    #+#             */
/*   Updated: 2015/04/07 17:16:58 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_v2.h"

void	print_man(void)
{
	ft_putendl("Usage: ./FdF filename [projection type]");
	ft_putendl("       Projections available: iso (default), conic, parallel");
	ft_putendl("       Use the arrows to move the map");
	ft_putendl("       Use { to zoom in, and } to zoom out");
}

int		my_open(char *filename)
{
	return (open(filename, O_RDONLY));
}

int		tbd_print_input(char *filename)
{
	int		fd;
	char	**line;

	fd = my_open(filename);
	line = (char**)malloc(sizeof(char*));
	if (!line)
		return (-1);
	if (fd < 0)
		return (-1);
	while (get_next_line(fd, line) == 1)
		ft_putendl(*line);
	ft_putendl(*line);
	return (0);
}

int		check_args(t_args *a, int argc, char **argv)
{
	int	fd;

	if (argc < 2 || argc > 3)
		return (-1);
	if ((fd = my_open(argv[1])) >= 0 && !close(fd))
		a->filename = argv[1];
	else
	{
		ft_putendl("Error: unknown file name\n");
		return (-2);
	}
	if (argc == 3)
	{
		if (!ft_strcmp(argv[2], "iso") || !ft_strcmp(argv[2], "conic")
					|| !ft_strcmp(argv[2], "parallel"))
			a->proj = argv[2];
		else
		{
			ft_putendl("Error: projection type unknown");
			ft_putendl("       Try 'iso', 'conic' or 'parallel' instead\n");
			return (-3);
		}
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_args	a;

	if (check_args(&a, argc, argv) < 0)
	{
		print_man();
		ft_putchar('\n');
		return (0);
	}
	if (argc > 1 && argc < 4)
	{
		ft_putendl("Printing input map...");
		tbd_print_input(argv[1]);
	}
	return (0);
}
