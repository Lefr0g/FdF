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

int		get_input(char *filename, int filesize)
{
	t_tmp	t;

	if (filesize < LIMIT_PRINT)
		ft_putendl("Loading & printing file...");
	else
		ft_putstr("Loading file...");
	t.i = 0;
	t.fd = my_open(filename);
	t.buf = ft_strnew(BUF_SIZE);
	if (!t.buf)
		return (-1);
	if (t.fd < 0)
		return (-1);
	while (get_next_line(t.fd, &(t.buf)) == 1)
	{
		if (filesize < LIMIT_PRINT)
			ft_putendl(t.buf);
		t.i++;
	}
	if (filesize < LIMIT_PRINT)
		ft_putendl(t.buf);
	if (close(t.fd))
		return (-1);
	return (t.i);
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
	d.filesize = check_filesize(argv[1]);
	d.linecount = get_input(argv[1], d.filesize);
	parse(a.filename, &d);
	print_meta(&d);
	ft_putchar('\n');
	return (0);
}
