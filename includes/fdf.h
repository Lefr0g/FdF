/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 11:06:47 by amulin            #+#    #+#             */
/*   Updated: 2015/07/01 16:36:54 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "libft.h"
# include "mlx.h"

# define BUF_SIZE 100
# define LIMIT_PRINT 5000
# define MAX_FILE_SIZE 1000000000
# define WIN_X 800
# define WIN_Y 600
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
# define KEY_I 34
# define KEY_P 35
# define KEY_F 3
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20
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
	int			text_height;
}				t_image;

typedef struct	s_data
{
	int			i;
	int			fd;
	char		*filename;
	char		*proj;
	int			filesize;
	int			linecount;
	int			longestline;
	int			*meta;
	int			**rawmap;
	int			min_value;
	int			max_value;
	int			range;
	float		alt_factor;
	int			(*palette)(struct s_data*, int);
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
	float		cte3;
	int			menuflag;
	int			startflag;
	int			starttimer;
	int			menu_x_anchor;
	int			menu_y_anchor;
	t_image		*img;
	t_image		*menu_bg;
	float		(*method_calc_x)(struct s_data*, int, int);
	float		(*method_calc_y)(struct s_data*, int, int);
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
	int			x;
	int			y;
	int			alt;
	float		x1;
	float		y1;
	float		z1;
	float		x2;
	float		y2;
	int			z2;
	int			flag;
	char		*buf;
}				t_tmp;

/*
**	fdf_preliminary.c
*/
int				check_valid_data(char *filename, t_data *d);
int				check_filesize(char *filename);
int				check_args(t_data *d, int argc, char **argv);
int				check_palette(t_data *d, char *str);
int				check_proj(t_data *d, char *str);

/*
**	fdf_data_processing.c
*/
int				my_open(char *filename);
int				count_lines(char *filename, int filesize);
int				parse(char *filename, t_data *d);
int				my_getnbr(t_data *d, t_tmp *t);
int				my_get_min_max(int nbr, t_data *d, int *flag);

/*
**	fdf_verbose_1.c
*/
void			print_proto(void);
void			print_man(void);
void			print_filesize_onload(int filesize);
void			print_rawmap(t_data *d);
void			print_meta(t_data *d);

/*
**	fdf_verbose_2.c
*/
int				my_print_loadbar(int pos, int end, int prev, char *mode);

/*
**	fdf_init.c
*/
void			init_t_tmp(t_tmp *t);
void			init_draw(t_data *d);
t_image			image_init(void *mlx_id, int width, int height);
int				menu_init(t_data *d);

/*
**	fdf_set.c
*/
int				set_proj(t_data *d);
int				set_palette(t_data *d, int val);

/*
**	fdf_draw_loop.c
*/
int				key_hook(int keycode, t_data *d);
int				expose_hook(t_data *d);
int				loop_hook(t_data *d);
int				draw_loop(t_data *d);

/*
**	fdf_draw_textframes.c
*/
void			draw_menu(t_data *d);
void			draw_instructions(t_data *d);
void			draw_string_center(t_data *d, t_image *item,
				int color, char *str);
void			draw_string_left(t_data *d, t_image *item,
				int color, char *str);

/*
**	fdf_draw_colorpix.c
*/
int				palette_1(struct s_data *d, int alt);
int				palette_2(struct s_data *d, int alt);
int				palette_3(struct s_data *d, int alt);
void			draw_pixel(t_tmp *t, t_data *d, float x, float y);

/*
**	fdf_draw_map.c
*/
int				draw_map(t_data *d);

/*
**	fdf_images.c
*/
int				expose_img(t_data *d, int x, int y);
int				image_pixel_put(t_image *img, int x, int y, int color);
t_uint32		my_endian_swap(unsigned int input);
t_uint32		rgb_to_mlx(t_image *img, int color);

/*
**	fdf_calc_1.c
*/
float			calc_x_flat(t_data *d, int i, int j);
float			calc_y_flat(t_data *d, int i, int j);
float			calc_x_paral(t_data *d, int i, int j);
float			calc_y_paral(t_data *d, int i, int j);

/*
**	fdf_calc_2.c
*/
float			calc_x_iso(t_data *d, int i, int j);
float			calc_y_iso(t_data *d, int i, int j);

/*
**	fdf_lines.c
*/
void			draw_web(t_tmp *t, t_data *d);
int				get_alt(int posseg, int lenseg, int alt1, int alt2);
void			draw_line_atob(t_tmp *t, t_data *d);
void			draw_line_horz(t_tmp *t, t_data *d);
void			draw_line_vert(t_tmp *t, t_data *d);

/*
**	fdf_keys.c
*/
void			reinit_pos(t_data *d);
int				check_all_keys(int keycode, t_data *d);
int				check_nav_keys(int keycode, t_data *d);
int				check_proj_keys(int keycode, t_data *d);
int				check_palette_keys(int keycode, t_data *d);

/*
**	fdf_ending.c
*/
void			ending_routine(t_data *d);

/*
**	fdf_misc.c
*/
char			*my_realloc(char **str, int newsize);
int				my_get_min(int i, int j);
int				my_min_one(int num, int denom);
void			is_file_drawable(t_data *d);

#endif
