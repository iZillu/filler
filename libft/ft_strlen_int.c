/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 03:35:00 by hmuravch          #+#    #+#             */
/*   Updated: 2018/07/24 03:35:01 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_int(intmax_t num)
{
	size_t		len;
	intmax_t	i;

	i = 10;
	len = 0;
	if (num < 0)
	{
		num *= -1;
		len++;
	}
	if ((num <= 9223372036854775807 && num > 999999999999999999)
		|| num < -9223372036854775807)
		return (19);
	if (num == 1 || num == 0)
		return (1 + len);
	while (num > 0)
	{
		num /= i;
		len++;
	}
	return (len);
}

size_t	ft_strlen_u_int(uintmax_t num)
{
	size_t		len;
	uintmax_t	i;

	i = 10;
	len = 0;
	if (num == 1 || num == 0)
		return (1 + len);
	while (num > 0)
	{
		num /= i;
		len++;
	}
	return (len);
}
