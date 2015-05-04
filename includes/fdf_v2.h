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
# define LOADBAR_MODE "bar"
# define SPACING_INIT 20

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
	int			spacing;
	int			spacing_init;
	int			top_offset;
	int			left_offset;
	int			top_added;
	int			left_added;
	int			menuflag;
}				t_data;

typedef struct	s_tmp
{
	int			i;
	int			j;
	int			k;
	int			fd;
	int			pos;
	int			prev;
	int			x;
	int			y;
	int			z;
	char		*buf;
}				t_tmp;

void			init_t_tmp(t_tmp *t);
void			init_draw(t_data *d);

void			print_proto(void);
void			print_man(void);
void			print_meta(t_data *d);
void			print_rawmap(t_data *d);
void			print_filesize_onload(int filesize);

int				my_check_args(int min, int max, int argc, char **argv);
int				my_print_loadbar(int pos, int end, int prev, char *mode);
int				my_open(char *filename);
char			*my_realloc(char **str, int newsize);
int				my_get_min(int i, int j);

int				check_args(t_args *a, int argc, char **argv);
int				check_valid_data(char *filename, t_data *d);
int				check_filesize(char *filename);
int				count_lines(char *filename, int filesize);
int				parse(char *filename, t_data *d);
void			my_getnbr(t_data *d, t_tmp *t);

int				pick_color(t_tmp *t, t_data *d);
void			draw_pixel(t_tmp *t, t_data *d);
int				draw_map(t_data *d);
void			draw_menu(t_data *d);
int				expose_hook(t_data *d);
int				key_hook(int keycode, t_data *d);
void			check_nav_keys(int keycode, t_data *d);
int				refresh(t_data *d);

int				calc_x(t_tmp *t, t_data *d);
int				calc_y(t_tmp *t, t_data *d);

#endif
