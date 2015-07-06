/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_data_processing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 16:28:56 by amulin            #+#    #+#             */
/*   Updated: 2015/07/01 18:11:05 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		my_open(char *filename)
{
	return (open(filename, O_RDONLY));
}

int		count_lines(char *filename, int filesize)
{
	t_tmp	t;

	init_t_tmp(&t);
	print_filesize_onload(filesize);
	t.fd = my_open(filename);
	if (!t.buf || t.fd < 0)
		return (-1);
	while (get_next_line(t.fd, &(t.buf)) > 0)
	{
		if (filesize <= LIMIT_PRINT)
			ft_putendl(t.buf);
		else
			t.prev = my_print_loadbar(t.pos, filesize, t.prev, LOADBAR_MODE);
		t.pos = t.pos + ft_strlen(t.buf) + 1;
		t.i++;
	}
	if (filesize <= LIMIT_PRINT)
		ft_putendl(t.buf);
	else
		t.prev = my_print_loadbar(t.pos, filesize, t.prev, LOADBAR_MODE);
	if (close(t.fd))
		return (-1);
	ft_strdel(&(t.buf));
	return (t.i);
}

int		parse(char *filename, t_data *d)
{
	t_tmp	t;

	init_t_tmp(&t);
	d->rawmap = (int**)malloc(sizeof(int*) * d->linecount);
	d->meta = (int*)malloc(sizeof(int) * d->linecount);
	if ((t.fd = my_open(filename)) < 0)
		return (-1);
	ft_putstr("\nParsing file...");
	while (get_next_line(t.fd, &(t.buf)) > 0)
	{
		if (d->filesize > LIMIT_PRINT)
		{
			t.prev = my_print_loadbar(t.pos, d->filesize, t.prev, LOADBAR_MODE);
			t.pos = t.pos + ft_strlen(t.buf) + 1;
		}
		my_getnbr(d, &t);
	}
	if (d->filesize <= LIMIT_PRINT)
		print_rawmap(d);
	else
		t.prev = my_print_loadbar(t.pos, d->filesize, t.prev, LOADBAR_MODE);
	print_meta(d);
	ft_strdel(&(t.buf));
	return (0);
}

int		my_getnbr(t_data *d, t_tmp *t)
{
	d->rawmap[t->i] = (int*)malloc(sizeof(int) * ft_strlen(t->buf));
	t->j = 0;
	t->k = 0;
	while (t->buf[t->j] && t->buf[t->j] != '\n')
	{
		while (!ft_isdigit(t->buf[t->j]) && (t->buf[t->j] != '-'))
			t->j++;
		d->rawmap[t->i][t->k] = my_get_min_max(ft_atoi(&(t->buf[t->j])),
				d, &(t->flag));
		while (ft_isdigit(t->buf[t->j]) || t->buf[t->j] == '-')
			t->j++;
		t->j++;
		t->k++;
	}
	d->meta[t->i] = t->k;
	t->i++;
	return (0);
}

int		my_get_min_max(int nbr, t_data *d, int *flag)
{
	if (*flag == 0)
	{
		d->min_value = nbr;
		d->max_value = nbr;
		*flag = 1;
	}
	if (nbr < d->min_value)
		d->min_value = nbr;
	if (nbr > d->max_value)
		d->max_value = nbr;
	d->range = d->max_value - d->min_value;
	return (nbr);
}
