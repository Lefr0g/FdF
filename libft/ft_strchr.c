/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 16:21:07 by amulin            #+#    #+#             */
/*   Updated: 2015/02/13 18:04:01 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	const char	*new;

	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == c)
		{
			new = &s[i];
			return ((char*)new);
		}
		i++;
	}
	return (NULL);
}
