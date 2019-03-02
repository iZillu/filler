/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 18:30:00 by hmuravch          #+#    #+#             */
/*   Updated: 2018/04/10 13:22:12 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dst, const char *add)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (dst[i] != '\0')
		i++;
	while (add[count] != '\0')
	{
		dst[i] = add[count];
		i++;
		count++;
	}
	dst[i] = '\0';
	return (dst);
}
