/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_v2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 11:07:06 by amulin            #+#    #+#             */
/*   Updated: 2015/02/27 14:36:08 by amulin           ###   ########.fr       */
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

int		**convert_map(char *filename)
{
//	Check filename is a file
//	Check map is valid
//	Copy map
}

int		main(int argc, char **argv)
{
	int	**map;

	if (argc > 1 && argc < 4)
	{
		map = convert_map(argv[1]);
//	Parse
//	Draw
	}
	else
		print_man();
	return (0);
}
