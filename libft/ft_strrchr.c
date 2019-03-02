/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 19:56:44 by hmuravch          #+#    #+#             */
/*   Updated: 2018/04/10 14:08:26 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	to_find;
	char			*save;

	to_find = (unsigned char)c;
	save = 0;
	while (*s)
	{
		if (*s == to_find)
			save = (char *)s;
		s++;
	}
	if (to_find == 0)
		return ((char *)s++);
	if (save)
		return (save);
	else
		return (0);
}
