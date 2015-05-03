/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preliminary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 17:23:22 by amulin            #+#    #+#             */
/*   Updated: 2015/04/09 17:19:03 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_v2.h"

int		check_valid_data(char *filename, t_data *d)
{
	d->filesize = check_filesize(filename);
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
	return (filesize);
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
