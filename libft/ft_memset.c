/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 23:19:58 by hmuravch          #+#    #+#             */
/*   Updated: 2018/04/09 18:33:34 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int sym, size_t len)
{
	unsigned char	*temp_dest;
	char			temp_sym;

	temp_dest = (unsigned char *)dest;
	temp_sym = (char)sym;
	while (len--)
		*temp_dest++ = temp_sym;
	return (dest);
}
