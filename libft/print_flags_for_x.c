/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags_for_x.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 01:49:47 by hmuravch          #+#    #+#             */
/*   Updated: 2018/08/15 10:41:38 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_zero_x(intmax_t *x, t_sym *sym)
{
	if (sym->zero && !sym->precision)
	{
		if (sym->sharp == 1 && *x != 0)
		{
			write(1, "0x", 2);
			sym->check += 2;
		}
		while (sym->width > sym->arg_len)
		{
			write(1, "0", 1);
			sym->check++;
			sym->width--;
		}
	}
}

void	print_width_x(t_sym *sym)
{
	sym->precision = sym->save_precision;
	if (sym->save_width > sym->precision && sym->width > sym->arg_len
	&& sym->precision > sym->arg_len)
		while (sym->width > sym->arg_len)
		{
			write(1, " ", 1);
			sym->check++;
			sym->width--;
		}
	else if (sym->save_width > sym->precision && sym->width > sym->arg_len)
		while (sym->save_width > sym->arg_len)
		{
			write(1, " ", 1);
			sym->check++;
			sym->save_width--;
		}
}

void	print_precision_x(intmax_t *x, t_sym *sym)
{
	if ((sym->sharp == 1 && sym->precision && *x != 0))
	{
		write(1, "0x", 2);
		sym->check += 2;
	}
	while (sym->precision > sym->arg_len)
	{
		write(1, "0", 1);
		sym->check++;
		sym->precision--;
	}
}
