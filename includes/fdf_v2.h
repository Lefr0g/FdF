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

typedef struct	s_args
{
	char		*filename;
	char		*proj;
	int			linecount;
}				t_args;

void			print_man(void);
int				my_open(char *filename);
int				check_args(t_args *a, int argc, char **argv);

#endif
