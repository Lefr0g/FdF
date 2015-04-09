/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_v2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 11:06:47 by amulin            #+#    #+#             */
/*   Updated: 2015/04/09 18:07:08 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_V2_H
# define FDF_V2_H

# include <fcntl.h>
# include "libft.h"
# include "mlx.h"

# define BUF_SIZE 100
# define LIMIT_PRINT 5000
# define WIN_X 800
# define WIN_Y 600
# define WIN_TITLE "FdF"

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
	void		*mlx_id;
	void		*win_id;
}				t_data;

typedef struct	s_tmp
{
	int			i;
	int			j;
	int			k;
	int			x;
	int			y;
	int			z;
	int			fd;
	char		*buf;
}				t_tmp;

void			print_proto(void);
void			print_man(void);
void			print_meta(t_data *d);
void			print_rawmap(t_data *d);
void			print_filesize_onload(int filesize);

int				my_open(char *filename);
char			*my_realloc(char **str, int newsize);

int				check_args(t_args *a, int argc, char **argv);
int				check_valid_data(char *filename, t_data *d);
int				check_filesize(char *filename);
int				get_input(char *filename, int filesize);
int				parse(char *filename, t_data *d);
void			my_getnbr(t_data *d, t_tmp *t);

int				draw_map(t_data *d);

#endif
