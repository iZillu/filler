/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_caster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 15:26:04 by hmuravch          #+#    #+#             */
/*   Updated: 2018/08/15 09:57:46 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	cast_int(va_list arg, t_sym *sym)
{
	if (sym->size == 1)
		return ((char)va_arg(arg, int));
	else if (sym->size == 2)
		return ((short)va_arg(arg, int));
	else if (sym->size == 3)
		return (va_arg(arg, long int));
	else if (sym->size == 4)
		return (va_arg(arg, long long int));
	else if (sym->size == 5)
		return (va_arg(arg, intmax_t));
	else if (sym->size == 6)
		return (va_arg(arg, ssize_t));
	else
		return (va_arg(arg, int));
}

intmax_t	cast_uint(va_list arg, t_sym *sym)
{
	if (sym->size == 1)
		return ((unsigned char)va_arg(arg, int));
	else if (sym->size == 2)
		return ((unsigned short)va_arg(arg, int));
	else if (sym->size == 3)
		return (va_arg(arg, unsigned long int));
	else if (sym->size == 4)
		return (va_arg(arg, uintmax_t));
	else if (sym->size == 5)
		return (va_arg(arg, uintmax_t));
	else if (sym->size == 6)
		return (va_arg(arg, size_t));
	else
		return (va_arg(arg, unsigned int));
}

void		initializer(t_sym *sym)
{
	sym->sign = 0;
	sym->len = 0;
	sym->sharp = 0;
	sym->minus = 0;
	sym->zero = 0;
	sym->dot = 0;
	sym->check = 0;
	sym->width = 0;
	sym->save_width = 0;
	sym->save_precision = 0;
	sym->save_arg_len = 0;
	sym->arg_len = 0;
	sym->size = 0;
	sym->precision = 0;
	sym->crutch = 1;
	sym->tmp = NULL;
	sym->tmp2 = NULL;
}
