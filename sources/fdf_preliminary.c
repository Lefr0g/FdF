/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_preliminary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 17:23:22 by amulin            #+#    #+#             */
/*   Updated: 2015/07/01 16:18:16 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_valid_data(char *filename, t_data *d)
{
	d->filesize = check_filesize(filename);
	if (d->filesize > MAX_FILE_SIZE)
	{
		ft_putendl("Error: file is too big.");
		return (-1);
	}
	d->linecount = count_lines(filename, d->filesize);
	if (d->filesize < 0 || d->linecount < 0)
	{
		ft_putendl("Error: data processing fail");
		return (-1);
	}
	return (0);
}

int		check_filesize(char *filename)
{
	int		fd;
	int		ret;
	char	*buf;
	int		filesize;

	filesize = 0;
	buf = ft_strnew(BUF_SIZE);
	if ((fd = my_open(filename)) < 0)
		return (-1);
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
		filesize = filesize + ret;
	if (close(fd))
		return (-1);
	ft_strdel(&buf);
	return (filesize);
}

int		check_args(t_data *d, int argc, char **argv)
{
	d->proj = ft_strdup("iso");
	if (argc < 2 || argc > 4)
		return (-1);
	if ((d->fd = my_open(argv[1])) >= 0 && !close(d->fd))
		d->filename = argv[1];
	else
	{
		ft_putendl("Error: unknown file name\n");
		return (-2);
	}
	d->palette = &(palette_1);
	if ((argc == 3 || argc == 4) && check_proj(d, argv[2]) == -1)
		return (-3);
	if (argc == 4 && check_palette(d, argv[3]) == -1)
		return (-4);
	return (0);
}

int		check_palette(t_data *d, char *str)
{
	int	val;

	val = ft_atoi(str);
	if (val < 1 || val > 3)
	{
		ft_putendl("Error: incorrect palette number");
		ft_putendl("       Try '1' (default), '2', or '3' instead\n");
		return (-1);
	}
	else
		set_palette(d, val);
	return (0);
}

int		check_proj(t_data *d, char *str)
{
	if (!ft_strcmp(str, "iso") || !ft_strcmp(str, "flat")
			|| !ft_strcmp(str, "parallel"))
	{
		ft_strdel(&(d->proj));
		d->proj = ft_strdup(str);
	}
	else
	{
		ft_putendl("Error: projection type unknown");
		ft_putendl("       Try 'iso', 'flat' or 'parallel' instead\n");
		return (-1);
	}
	return (0);
}
