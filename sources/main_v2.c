/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_v2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 11:07:06 by amulin            #+#    #+#             */
/*   Updated: 2015/04/07 16:07:08 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_v2.h"

void	print_man(void)
{
	ft_putendl("Usage: ./FdF filename [projection type]");
	ft_putendl("       Projection types available : iso, conic, parallel");
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

int		main(int argc, char **argv)
{
	if (argc > 1 && argc < 4)
	{
		ft_putendl("Printing input map...");
		tbd_print_input(argv[1]);
	}
	else
		print_man();
	return (0);
}
