/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:25:20 by hmuravch          #+#    #+#             */
/*   Updated: 2018/04/17 20:27:35 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*temp_s1;
	unsigned char	*temp_s2;

	temp_s1 = (unsigned char *)s1;
	temp_s2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (temp_s1[i] != '\0' && temp_s2[i] != '\0' && i < n)
	{
		if (temp_s1[i] - temp_s2[i] != 0)
			return (temp_s1[i] - temp_s2[i]);
		if (i == n - 1)
			return (temp_s1[i] - temp_s2[i]);
		i++;
	}
	return (0);
}
