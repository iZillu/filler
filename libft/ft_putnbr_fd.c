/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 05:34:46 by hmuravch          #+#    #+#             */
/*   Updated: 2018/04/10 13:16:10 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int				num;
	int				i;
	unsigned int	r;

	num = 1;
	r = (unsigned int)n;
	i = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		r = (unsigned int)(n * -1);
	}
	while ((r / i) > 9)
		i *= 10;
	while (i > 0)
	{
		num = r / i;
		r = r % i;
		ft_putchar_fd((char)num + '0', fd);
		i /= 10;
	}
}
