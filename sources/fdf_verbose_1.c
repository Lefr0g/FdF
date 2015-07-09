/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_verbose_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 16:35:53 by amulin            #+#    #+#             */
/*   Updated: 2015/06/24 17:45:16 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_proto(void)
{
	ft_putendl("Usage: ./fdf filename [projection type] [color palette]\n");
}

void	print_man(void)
{
	print_proto();
	ft_putendl("       Projections available: iso (default), flat, parallel");
	ft_putendl("       Use the arrows to move the map");
	ft_putendl("       Use { to zoom in, and } to zoom out\n");
}

void	print_filesize_onload(int filesize)
{
	ft_putendl("\t______________________________\n");
	if (filesize < LIMIT_PRINT)
	{
		ft_putstr("The file is small enough (");
		ft_putnbr(filesize);
		ft_putendl(" bytes) to be printed on terminal\n");
		ft_putendl("Counting & printing lines...");
	}
	else
	{
		ft_putstr("All fine, but the file is too big (");
		ft_putnbr(filesize);
		ft_putendl(" bytes) to be printed on terminal\n");
		ft_putstr("Counting lines...");
	}
}

void	print_rawmap(t_data *d)
{
	t_tmp	t;

	ft_putendl("\n\nPrinting converted map...");
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
	ft_putchar('\n');
}

void	print_meta(t_data *d)
{
	int	i;

	i = 0;
	d->longestline = 0;
	while (i < d->linecount)
	{
		if (d->meta[i] > d->longestline)
			d->longestline = d->meta[i];
		i++;
	}
	is_file_drawable(d);
	ft_putstr("\nThe map is ");
	ft_putnbr(d->longestline);
	ft_putstr(" by ");
	ft_putnbr(d->linecount);
	ft_putendl(" at its widest\n");
	ft_putstr("Altitude varies from ");
	ft_putnbr(d->min_value);
	ft_putstr(" to ");
	ft_putnbr(d->max_value);
	ft_putendl("\n");
}
