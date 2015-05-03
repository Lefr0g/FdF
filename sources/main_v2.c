/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_v2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 11:07:06 by amulin            #+#    #+#             */
/*   Updated: 2015/04/09 17:59:36 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_v2.h"

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
	if (check_valid_data(argv[1], &d) < 0)
		return (-1);
	parse(a.filename, &d);
	if (draw_map(&d) < 0)
		return (-1);
	return (0);
}
