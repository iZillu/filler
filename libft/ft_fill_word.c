/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 16:12:01 by hmuravch          #+#    #+#             */
/*   Updated: 2018/08/20 00:41:38 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fill_word(char const *s, char c, int *i)
{
	char	*word;
	int		len;
	int		start;

	len = 0;
	start = -1;
	word = 0;
	if (s[*i] != '\0')
	{
		while (s[*i] == c)
			(*i)++;
		while (s[*i] != c && s[*i] != '\0')
		{
			len++;
			(*i)++;
		}
		if (!(word = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (++start < len)
			word[start] = s[(*i - len) + start];
		word[start] = '\0';
	}
	return (word);
}
