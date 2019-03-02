/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_missing_options.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 17:41:21 by hmuravch          #+#    #+#             */
/*   Updated: 2018/08/18 17:41:22 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	checking_sizes(const char *format, t_sym *sym)
{
	while (format[sym->i] == 'h' || format[sym->i] == 'l'
		|| format[sym->i] == 'j' || format[sym->i] == 'z')
	{
		if (ft_strncmp("hh", &format[sym->i], 2) == 0 && sym->size < 1)
		{
			sym->size = 1;
			sym->i++;
		}
		else if (ft_strncmp("ll", &format[sym->i], 2) == 0 && sym->size < 4)
		{
			sym->size = 4;
			sym->i++;
		}
		else if (format[sym->i] == 'h' && sym->size < 2)
			sym->size = 2;
		else if (format[sym->i] == 'l' && sym->size < 3)
			sym->size = 3;
		else if (format[sym->i] == 'j' && sym->size < 5)
			sym->size = 5;
		else if (format[sym->i] == 'z' && sym->size < 6)
			sym->size = 6;
		sym->i++;
	}
}

char	*take_number(const char *format, t_sym *sym)
{
	char	*str;
	int		len;
	int		num;

	num = 0;
	len = 0;
	while (format[++sym->i] >= '0' && format[sym->i] <= '9')
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	sym->i -= len;
	while (len--)
		str[num++] = format[sym->i++];
	return (str);
}

void	missing_width_and_precision(const char *format, t_sym *sym)
{
	char	*tmp;

	if (format[sym->i] >= '0' && format[sym->i] <= '9' && sym->i--)
	{
		tmp = take_number(format, sym);
		sym->width = ft_atoi(tmp);
		ft_strdel(&tmp);
	}
	if (format[sym->i] == '.' && ++sym->dot)
	{
		tmp = take_number(format, sym);
		sym->precision = ft_atoi(tmp);
		ft_strdel(&tmp);
	}
}

void	missing_flags(const char *format, t_sym *sym)
{
	while (format[sym->i] == '+'
		|| format[sym->i] == ' ' || format[sym->i] == '-'
		|| format[sym->i] == '#' || format[sym->i] == '0')
	{
		if (format[sym->i] == '+')
			sym->sign = 1;
		if (format[sym->i] == ' ')
			if (sym->sign != 1)
				sym->sign = 2;
		if (format[sym->i] == '#')
			sym->sharp = 1;
		if (format[sym->i] == '-')
			sym->minus = 1;
		if (format[sym->i] == '0')
			sym->zero = 1;
		sym->i++;
	}
	sym->minus ? sym->zero = 0 : 0;
	missing_width_and_precision(format, sym);
}
