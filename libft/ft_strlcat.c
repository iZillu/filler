/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 08:45:28 by hmuravch          #+#    #+#             */
/*   Updated: 2018/04/20 19:01:28 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		res;
	size_t		y;
	size_t		i;

	y = 0;
	res = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	i = ft_strlen(dst);
	if (i >= dstsize)
		return (dstsize + ft_strlen(src));
	while (dst[res] != '\0')
		res++;
	while (src[y] != '\0' && res < (dstsize - 1))
	{
		dst[res] = src[y];
		res++;
		y++;
	}
	y = ft_strlen(src);
	dst[res] = '\0';
	res = i + y;
	return (res);
}
