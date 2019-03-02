/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 05:36:50 by hmuravch          #+#    #+#             */
/*   Updated: 2018/06/24 18:26:24 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*kostil(int len, char *str, int minus, intmax_t n)
{
	int		i;
	long	x;
	int		num;

	x = 1;
	i = 0;
	while (n / x >= 10)
	{
		x *= 10;
		len++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (len + 2))))
		return (NULL);
	if (minus != 0 && n != 0)
		str[i++] = '-';
	while (x > 0)
	{
		num = n / x;
		n = n % x;
		str[i] = num + '0';
		x /= 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_itoa(intmax_t n)
{
	int		len;
	int		minus;

	minus = 0;
	len = 0;
	if (n == 2147483647)
		return (ft_strdup("2147483647"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		minus++;
		n *= -1;
		len++;
	}
	return (kostil(len, 0, minus, n));
}
