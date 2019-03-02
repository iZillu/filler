/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 10:02:53 by hmuravch          #+#    #+#             */
/*   Updated: 2018/06/24 12:10:41 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	counter(uintmax_t num, int base)
{
	int ret;

	ret = 0;
	while (num != 0)
	{
		num /= base;
		ret++;
	}
	return (ret);
}

char		*ft_itoa_base(uintmax_t num, int base, int upper)
{
	char	*str;
	int		n;
	int		i;
	char	tab[17];

	if (num == 0)
		return (ft_strdup("0"));
	if (upper)
		ft_strcpy(tab, "0123456789ABCDEF");
	else
		ft_strcpy(tab, "0123456789abcdef");
	n = counter(num, base);
	str = (char *)malloc(sizeof(char) * (n + 1));
	i = 1;
	while (num != 0)
	{
		str[n - i] = tab[num % base];
		num /= base;
		i++;
	}
	str[n] = '\0';
	return (str);
}
