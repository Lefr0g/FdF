/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_v2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 11:06:47 by amulin            #+#    #+#             */
/*   Updated: 2015/06/10 16:31:27 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_V2_H
# define FDF_V2_H

# include <fcntl.h>
# include "libft.h"
# include "mlx.h"

# define BUF_SIZE 100
# define LIMIT_PRINT 5000
# define WIN_X 1100
# define WIN_Y 700
# define WIN_TITLE "FdF"
# define LOADBAR_MODE "text"
# define SPACING_INIT 20
# define ESC 53
# define TAB 48
# define TOP_ARROW 126
# define DOWN_ARROW 125
# define RIGHT_ARROW 124
# define LEFT_ARROW 123
# define OPEN_BRACKET 33
# define CLOSE_BRACKET 30
# define SPACEBAR 49

typedef unsigned int	t_uint32;

typedef struct	s_image
{
	void		*mlx;
	void		*id;
	char		*str;
	int			width;
	int			height;
	int			bytes_per_pixel;
	int			*depth;
	int			*size_line;
	int			*endian;
	int			x;
	int			y;
}				t_image;

typedef struct	s_data
{
	char		*filename;
	char		*proj;
	int			filesize;
	int			linecount;
	int			longestline;
	int			*meta;
	int			**rawmap;
	int			min_value;
	int			max_value;
	void		*mlx_id;
	void		*win_id;
	int			spacing;
	int			spacing_init;
	int			top_offset;
	int			left_offset;
	int			top_added;
	int			left_added;
	float		cte1;
	float		cte2;
	int			menuflag;
	int			menu_y_anchor;
	int			menu_x_anchor;
	t_image		*img;
	t_image		*menu_bg;
}				t_data;

typedef struct	s_tmp
{
	int			i;
	int			j;
	int			k;
	int			l;
	int			i_start;
	int			fd;
	int			pos;
	int			prev;
	float		x;
	float		y;
	float		z;
	float		x_top;
	float		y_top;
	float		x_left;
	float		y_left;
	int			flag;
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
int				my_min_one(int num, int denom);
int				my_get_min_max(int nbr, t_data *d, int *flag);

int				check_args(t_data *d, int argc, char **argv);
int				check_valid_data(char *filename, t_data *d);
int				check_filesize(char *filename);
int				count_lines(char *filename, int filesize);
int				parse(char *filename, t_data *d);
int				my_getnbr(t_data *d, t_tmp *t);

int				pick_color(t_tmp *t, t_data *d);

void			draw_pixel(t_tmp *t, t_data *d, float x, float y);
void			draw_web(t_tmp *t, t_data *d);
void			draw_line_horz(t_tmp *t, t_data *d, float xb, float yb);
void			draw_line_vert(t_tmp *t, t_data *d, float xb, float yb);
void			draw_line_atob(t_tmp *t, t_data *d, float xb, float yb);

int				draw_loop(t_data *d);
int				draw_map_raw(t_data *d);
int				draw_map_iso(t_data *d);
void			draw_menu(t_data *d);
void			draw_string_center(t_data *d, int pos_y, int color, char *str);
int				expose_hook(t_data *d);
int				key_hook(int keycode, t_data *d);
int				check_nav_keys(int keycode, t_data *d);
int				refresh(t_data *d);
int				my_clear_window(t_data *d);

int				calc_x_flat(t_tmp *t, t_data *d);
int				calc_y_flat(t_tmp *t, t_data *d);
float			calc_x_iso(t_data *d, int i, int j);
float			calc_y_iso(t_data *d, int i, int j);
int				calc_x_y_iso(t_tmp *t, t_data *d);

t_uint32		my_endian_swap(unsigned int input);
t_uint32		rgb_to_mlx(t_image *img, int color);
t_image			image_init(void *mlx_id, int width, int height);
int				menu_init(t_data *d);
int				image_pixel_put(t_image *img, int x, int y, int color);
int				expose_img(t_data *d, int x, int y);

#endif
