/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_v2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 11:07:06 by amulin            #+#    #+#             */
/*   Updated: 2015/04/07 17:38:40 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_v2.h"

int		my_open(char *filename)
{
	return (open(filename, O_RDONLY));
}

int		print_input(char *filename)
{
	int		fd;
	char	**line;
	int		i;

	ft_putendl("Printing input map...");
	i = 0;
	fd = my_open(filename);
	line = (char**)malloc(sizeof(char*));
	if (!line)
		return (-1);
	if (fd < 0)
		return (-1);
	while (get_next_line(fd, line) == 1)
	{
		ft_putendl(*line);
		i++;
	}
	ft_putendl(*line);
	if (close(fd))
		return (-1);
	return (i);
}

int		main(int argc, char **argv)
{
	t_args	a;
	t_data	d;

	if (check_args(&a, argc, argv) < 0)
	{
		print_proto();
		return (0);
	}
	print_man();
	d.linecount = print_input(argv[1]);
	parse(a.filename, &d);
	print_rawmap(&d);
	print_meta(&d);
	ft_putchar('\n');
	return (0);
}
