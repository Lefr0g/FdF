/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 16:28:56 by amulin            #+#    #+#             */
/*   Updated: 2015/04/09 17:01:46 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_v2.h"

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
	t.buf = ft_strnew(BUF_SIZE);
	if (!t.buf || t.fd < 0)
		return (-1);
	while (get_next_line(t.fd, &(t.buf)) == 1)
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
	while (get_next_line(t.fd, &(t.buf)) == 1)
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
