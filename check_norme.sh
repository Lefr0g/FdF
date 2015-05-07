# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    check_norme.sh                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amulin <amulin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/07 13:42:42 by amulin            #+#    #+#              #
#    Updated: 2015/05/07 13:48:16 by amulin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh

# ls sources/ | grep -v main_v1.c | xargs norminette
find sources/ -name "*.c" -not -name "main_v1.c" | xargs norminette
norminette includes/fdf_v2.h
