/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:04:25 by hmuravch          #+#    #+#             */
/*   Updated: 2018/04/12 20:48:53 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*temp_s1;
	unsigned char	*temp_s2;

	temp_s1 = (unsigned char *)s1;
	temp_s2 = (unsigned char *)s2;
	i = 0;
	while (temp_s1[i] != '\0' && temp_s2[i] != '\0')
	{
		if ((temp_s1[i] - temp_s2[i]) != 0)
			return (temp_s1[i] - temp_s2[i]);
		i++;
	}
	return (temp_s1[i] - temp_s2[i]);
}
