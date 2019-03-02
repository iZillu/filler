/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 06:21:24 by hmuravch          #+#    #+#             */
/*   Updated: 2018/08/15 09:58:36 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2, int first, int second)
{
	char	*str;
	int		len;
	int		i;
	int		x;

	if (s1 && s2)
	{
		i = -1;
		x = 0;
		len = ft_strlen(s1) + ft_strlen(s2);
		if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (s1[++i] != '\0')
			str[i] = s1[i];
		while (s2[x] != '\0')
			str[i++] = s2[x++];
		str[i] = '\0';
		if (first)
			ft_strdel(&s1);
		if (second)
			ft_strdel(&s2);
		return (str);
	}
	return (NULL);
}
