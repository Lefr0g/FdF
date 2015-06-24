/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_v2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 11:07:06 by amulin            #+#    #+#             */
/*   Updated: 2015/06/24 16:39:06 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_data	d;

	if (check_args(&d, argc, argv) < 0)
	{
		print_proto();
		return (0);
	}
	print_man();
	if (check_valid_data(argv[1], &d) < 0)
		return (-1);
	parse(d.filename, &d);
	if (draw_loop(&d) < 0)
		return (-1);
	return (0);
}
