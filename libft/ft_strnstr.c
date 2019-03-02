/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 19:13:28 by hmuravch          #+#    #+#             */
/*   Updated: 2018/04/24 17:41:32 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	int			z;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (i < len && haystack[i])
	{
		j = 0;
		z = i;
		while (i < len && haystack[i] && (haystack[i] == needle[j]))
		{
			i++;
			if (needle[++j] == '\0')
				return ((char *)(haystack + z));
		}
		i = z;
		i++;
	}
	return (NULL);
}
