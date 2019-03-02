/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:18:26 by hmuravch          #+#    #+#             */
/*   Updated: 2018/04/10 13:14:04 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*temp_dst;
	const char	*temp_src;
	char		sign;

	temp_dst = (char *)dst;
	temp_src = (const char *)src;
	sign = (char)c;
	if (n)
		while (n--)
			if ((*(temp_dst++) = *(temp_src++)) == sign)
				return ((void *)temp_dst);
	return (NULL);
}
