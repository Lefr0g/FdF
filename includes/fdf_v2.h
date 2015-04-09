/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_v2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 11:06:47 by amulin            #+#    #+#             */
/*   Updated: 2015/04/07 17:32:48 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_V2_H
# define FDF_V2_H

# include <fcntl.h>
# include "libft.h"
# define BUF_SIZE 100
# define LIMIT_PRINT 5000

typedef struct	s_args
{
	char		*filename;
	char		*proj;
}				t_args;

typedef struct	s_data
{
	int			filesize;
	int			linecount;
	int			longestline;
	int			*meta;
	int			**rawmap;
}				t_data;

typedef struct	s_tmp
{
	int			i;
	int			j;
	int			k;
	int			fd;
	char		*buf;
}				t_tmp;

void			print_proto(void);
void			print_man(void);
void			print_meta(t_data *d);
void			print_rawmap(t_data *d);

int				my_open(char *filename);
char			*my_realloc(char **str, int newsize);

int				check_args(t_args *a, int argc, char **argv);
int				check_filesize(char *filename);
int				parse(char *filename, t_data *d);
void			my_getnbr(t_data *d, t_tmp *t);

#endif
