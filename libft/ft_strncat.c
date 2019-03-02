/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 18:55:28 by hmuravch          #+#    #+#             */
/*   Updated: 2018/04/10 13:37:17 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *add, size_t n)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (dst[i] != '\0')
		i++;
	while (add[count] != '\0' && n--)
	{
		dst[i] = add[count];
		i++;
		count++;
	}
	dst[i] = '\0';
	return (dst);
}
