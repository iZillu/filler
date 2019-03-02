/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags_for_u.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 05:40:47 by hmuravch          #+#    #+#             */
/*   Updated: 2018/08/15 10:41:48 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_space_u(t_sym *sym)
{
	if (sym->sign == 2 && sym->minus == 1)
	{
		write(1, " ", 1);
		sym->arg_len++;
	}
}

void	print_zero_u(t_sym *sym)
{
	if (sym->zero && !sym->precision)
	{
		while (sym->width > sym->arg_len)
		{
			write(1, "0", 1);
			sym->check++;
			sym->width--;
		}
	}
}

void	print_width_u(t_sym *sym)
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

void	print_precision_u(t_sym *sym)
{
	while (sym->precision > sym->arg_len)
	{
		write(1, "0", 1);
		sym->check++;
		sym->precision--;
	}
}
