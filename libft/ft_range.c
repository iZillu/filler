/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 16:28:32 by hmuravch          #+#    #+#             */
/*   Updated: 2018/04/18 16:28:52 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_range(int min, int max)
{
	int *str;
	int len;
	int i;

	i = 0;
	len = (max - min) + 1;
	if ((max - min) <= 0)
		return (0);
	str = (int *)malloc(sizeof(int) * len);
	while (i < len)
	{
		str[i] = min;
		min++;
		i++;
	}
	return (str);
}
