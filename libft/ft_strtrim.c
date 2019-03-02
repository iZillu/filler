/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 02:34:44 by hmuravch          #+#    #+#             */
/*   Updated: 2018/04/15 15:42:04 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char*cpy;
	int	len;
	int start;
	int end;

	if (!s)
		return (NULL);
	start = -1;
	end = ft_strlen(s);
	while (s[++start] != '\0')
		if (s[start] != ' ' && s[start] != '\t' && s[start] != '\n')
			break ;
	while (--end >= 0)
		if (s[end] != ' ' && s[end] != '\t' && s[end] != '\n')
			break ;
	len = end - start + 1;
	if (len < 0)
		len = 0;
	if (!(cpy = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	cpy = ft_strncpy(cpy, &s[start], len);
	cpy[len] = '\0';
	return (cpy);
}
