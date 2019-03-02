/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 09:25:20 by hmuravch          #+#    #+#             */
/*   Updated: 2018/04/10 13:36:21 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		len;

	if (s)
	{
		len = ft_strlen(s);
		if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		str[len] = '\0';
		while (len--)
			str[len] = f(s[len]);
		return (str);
	}
	return (NULL);
}
