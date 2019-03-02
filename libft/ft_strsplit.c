/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 05:02:28 by hmuravch          #+#    #+#             */
/*   Updated: 2018/07/24 03:47:41 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char**str;
	int	i;
	int	len;
	int	counter;

	i = 0;
	len = 0;
	str = 0;
	if (s)
	{
		counter = ft_num_of_words(s, c);
		if (!(str = (char **)malloc(sizeof(char *) * (counter + 1))))
			return (NULL);
		while (counter--)
		{
			str[i] = ft_fill_word(s, c, &len);
			i++;
		}
		str[i] = NULL;
		return (str);
	}
	return (NULL);
}
