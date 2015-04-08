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

void	print_proto(void)
{
	ft_putendl("Usage: ./fdf filename [projection type]\n");
}

void	print_man(void)
{
	print_proto();
	ft_putendl("       Projections available: iso (default), conic, parallel");
	ft_putendl("       Use the arrows to move the map");
	ft_putendl("       Use { to zoom in, and } to zoom out\n");
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

int		parse(char *filename, t_data *d)
{
	t_tmp	t;

	t.i = 0;
	d->rawmap = (int**)malloc(sizeof(int*) * d->linecount);
	d->meta = (int*)malloc(sizeof(int) * d->linecount);
	if ((t.fd = my_open(filename)) < 0)
		return (-1);
	while (get_next_line(t.fd, &(t.buf)) == 1)
		my_getnbr(d, &t);
	return (0);
}

void	my_getnbr(t_data *d, t_tmp *t)
{
	d->rawmap[t->i] = (int*)malloc(sizeof(int) * ft_strlen(t->buf));
	t->j = 0;
	t->k = 0;
	while (t->buf[t->j] && t->buf[t->j] != '\n')
	{
		while (!ft_isdigit(t->buf[t->j]) && (t->buf[t->j] != '-'))
			t->j++;
		d->rawmap[t->i][t->k] = ft_atoi(&(t->buf[t->j]));
		while (ft_isdigit(t->buf[t->j]) || t->buf[t->j] == '-')
			t->j++;
		t->j++;
		t->k++;
	}
	d->meta[t->i] = t->k;
	t->i++;
}

void	print_rawmap(t_data *d)
{
	t_tmp	t;

	ft_putendl("Printing converted map...");
	t.i = 0;
	while (t.i < d->linecount)
	{
		t.j = 0;
		while (t.j < d->meta[t.i])
		{
			ft_putnbr(d->rawmap[t.i][t.j]);
			ft_putchar(' ');
			t.j++;
		}
		ft_putchar('\n');
		t.i++;
	}
}

void	print_meta(t_data *d)
{
	int	i;

	i = 0;
	ft_putendl("\nThe data lines are composed as such:");
	while (i < d->linecount)
	{
		ft_putnbr(d->meta[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}
