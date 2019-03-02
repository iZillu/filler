/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 18:28:06 by hmuravch          #+#    #+#             */
/*   Updated: 2018/08/20 01:52:59 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	kostil(int i, size_t nmbr, int minus, const char *str)
{
	while ((str[i] > 47) && (str[i] < 58))
	{
		if (nmbr > 2147483647 && minus == 0)
			return (-1);
		if (nmbr > 2147483648 && minus == 1)
			return (0);
		nmbr *= 10;
		nmbr += ((int)str[i] - 48);
		i++;
	}
	if (minus)
		return (-nmbr);
	return (nmbr);
}

size_t			ft_atoi(const char *str)
{
	int		i;
	size_t	nmbr;
	int		minus;

	i = 0;
	nmbr = 0;
	minus = 0;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v')
			|| (str[i] == '\f') || (str[i] == '\r') || (str[i] == ' '))
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			minus = 1;
		i++;
	}
	return (kostil(i, nmbr, minus, str));
}
