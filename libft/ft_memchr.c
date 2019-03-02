/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 01:13:43 by hmuravch          #+#    #+#             */
/*   Updated: 2018/04/15 18:08:30 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*temp_arr;
	unsigned char	temp_c;
	size_t			i;

	i = 0;
	temp_arr = (unsigned char *)arr;
	temp_c = (unsigned char)c;
	while (i < n)
	{
		if (temp_arr[i] == temp_c)
			return (&temp_arr[i]);
		i++;
	}
	return (0);
}
