/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preliminary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 17:23:22 by amulin            #+#    #+#             */
/*   Updated: 2015/04/07 17:29:06 by amulin           ###   ########.fr       */
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
