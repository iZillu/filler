/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_U_x_X.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 06:11:52 by hmuravch          #+#    #+#             */
/*   Updated: 2018/07/30 06:19:05 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	print_u(va_list arg, uintmax_t *u, t_sym *sym)
{
	*u = cast_uint(arg, sym);
	sym->save_width = sym->width;
	sym->save_precision = sym->precision;
	sym->arg_len = ft_strlen_u_int(*u);
	print_space_u(sym);
	if (sym->precision < sym->width && sym->width && sym->precision)
		sym->width = sym->width - sym->precision + sym->arg_len;
	print_zero_u(sym);
	if (sym->minus == 0)
		print_width_u(sym);
	print_precision_u(sym);
	if (sym->dot && !sym->precision && *u == 0 && sym->save_width)
		write(1, " ", 1);
	else if (!(sym->dot && !sym->precision && *u == 0))
		ft_putnbr_u(*u);
	else
		sym->check--;
	if (sym->minus == 1)
		print_width_u(sym);
	return (sym->arg_len + sym->check);
}

size_t	print_cap_u(va_list arg, uintmax_t *cap_u, t_sym *sym)
{
	if (sym->size < 3)
		sym->size = 3;
	return (print_u(arg, cap_u, sym));
}

size_t	print_x(va_list arg, intmax_t *x, t_sym *sym)
{
	*x = cast_uint(arg, sym);
	sym->save_precision = sym->precision;
	if (sym->sharp == 1 && !sym->precision && !sym->zero && *x != 0)
		sym->tmp = ft_strjoin_free("0x", (ft_itoa_base(*x, 16, 0)), 0, 0);
	else
		sym->tmp = ft_itoa_base(*x, 16, 0);
	if (sym->dot && !sym->precision && *x == 0)
		sym->tmp = NULL;
	sym->arg_len = ft_strlen(sym->tmp);
	if (((sym->sharp == 1 && sym->precision) || (sym->sharp == 1 && sym->zero))
		&& sym->width)
		sym->width -= 2;
	sym->save_width = sym->width;
	if (sym->precision < sym->width && sym->width && sym->precision)
		sym->width = sym->width - sym->precision + sym->arg_len;
	print_zero_x(x, sym);
	if (sym->minus == 0)
		print_width_x(sym);
	print_precision_x(x, sym);
	ft_putstr(sym->tmp);
	ft_strdel(&sym->tmp);
	if (sym->minus == 1)
		print_width_x(sym);
	return (sym->arg_len + sym->check);
}

size_t	print_cap_x(va_list arg, intmax_t *cap_x, t_sym *sym)
{
	*cap_x = cast_uint(arg, sym);
	sym->save_precision = sym->precision;
	if (sym->sharp == 1 && !sym->precision && !sym->zero && *cap_x != 0)
		sym->tmp = ft_strjoin_free("0X", (ft_itoa_base(*cap_x, 16, 1)), 0, 1);
	else
		sym->tmp = ft_itoa_base(*cap_x, 16, 1);
	if (sym->dot && !sym->precision && *cap_x == 0)
		sym->tmp = NULL;
	sym->arg_len = ft_strlen(sym->tmp);
	if (((sym->sharp == 1 && sym->precision) || (sym->sharp == 1 && sym->zero))
		&& sym->width)
		sym->width -= 2;
	sym->save_width = sym->width;
	if (sym->precision < sym->width && sym->width && sym->precision)
		sym->width = sym->width - sym->precision + sym->arg_len;
	print_zero_x(cap_x, sym);
	if (sym->minus == 0)
		print_width_x(sym);
	print_precision_x(cap_x, sym);
	ft_putstr(sym->tmp);
	ft_strdel(&sym->tmp);
	if (sym->minus == 1)
		print_width_x(sym);
	return (sym->arg_len + sym->check);
}

size_t	print_percent(t_sym *sym)
{
	int check;

	check = 1;
	if (sym->minus == 1)
		write(1, "%", 1);
	while (sym->width-- > 1)
	{
		if (sym->zero == 0)
			write(1, " ", 1);
		else
			write(1, "0", 1);
		check++;
	}
	if (sym->minus == 0)
		write(1, "%", 1);
	return (check);
}
