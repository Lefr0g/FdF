/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 11:06:47 by amulin            #+#    #+#             */
/*   Updated: 2015/02/17 14:34:21 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "libft.h"
# include <mlx.h>

typedef	struct	s_params
{
	void		*id;
	void		*win;
	int			***mapcpy;
	const int	spacing = 20;
	const int	left_offset = 300;
	const int	top_offset = 200;
	const float	cte1 = 1;
	const float	cte2 = 1;
	int			buf_X;
	int			buf_Y;
}				t_params;

#endif
