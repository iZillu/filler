/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_C_s_c_d_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 05:20:12 by hmuravch          #+#    #+#             */
/*   Updated: 2018/07/27 00:18:27 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	print_i_or_d(va_list arg, t_sym *sym, intmax_t *d)
{
	*d = cast_int(arg, sym);
	sym->save_width = sym->width;
	sym->save_precision = sym->precision;
	sym->arg_len = ft_strlen_int(*d);
	print_space_d(d, sym);
	if (*d < 0 && sym->width && sym->precision)
		sym->width--;
	print_zero_d(d, sym);
	if (sym->minus == 0)
		print_width_d(d, sym);
	if (sym->sign == 1 && *d >= 0 && !sym->zero)
		print_plus_d(sym);
	print_precision_d(d, sym);
	if (sym->dot && !sym->precision && *d == 0 && sym->save_width)
		write(1, " ", 1);
	else if (!(sym->dot && !sym->precision && *d == 0))
		ft_putnbr(*d);
	else
		sym->check--;
	if (sym->minus == 1)
		print_width_d(d, sym);
	return (sym->arg_len + sym->check);
}

size_t	print_cap_d(va_list arg, intmax_t *cap_d, t_sym *sym)
{
	if (sym->size < 3)
		sym->size = 3;
	return (print_i_or_d(arg, sym, cap_d));
}

size_t	print_c(va_list arg, char *c, t_sym *sym)
{
	*c = (char)va_arg(arg, int);
	if (c)
		sym->arg_len++;
	if (!sym->minus)
		while (sym->width-- > sym->arg_len)
		{
			write(1, " ", 1);
			sym->check++;
		}
	write(1, c, 1);
	if (sym->minus)
		while (sym->width-- > sym->arg_len)
		{
			write(1, " ", 1);
			sym->check++;
		}
	return (sym->arg_len + sym->check);
}

size_t	print_cap_c(va_list arg, wint_t *cap_c, t_sym *sym)
{
	char	*u_code;

	*cap_c = va_arg(arg, wint_t);
	if (cap_c)
		u_code = ft_putchar_unicode(*cap_c, sym);
	if (!sym->minus)
		while (sym->width-- > sym->arg_len)
		{
			write(1, " ", 1);
			sym->check++;
		}
	ft_putstr(u_code);
	ft_strdel(&u_code);
	if (sym->minus)
		while (sym->width-- > sym->arg_len)
		{
			write(1, " ", 1);
			sym->check++;
		}
	return (sym->arg_len + sym->check);
}

size_t	print_p(va_list arg, void *p, t_sym *sym)
{
	char	*str;

	p = va_arg(arg, void *);
	str = ft_itoa_base((uintmax_t)p, 16, 0);
	sym->arg_len += ft_strlen(str) + 2;
	if (!sym->minus)
		while (sym->width-- > sym->arg_len)
		{
			write(1, " ", 1);
			sym->check++;
		}
	write(1, "0x", 2);
	if (!(p == NULL && sym->dot))
		ft_putstr(str);
	ft_strdel(&str);
	if (sym->minus)
		while (sym->width-- > sym->arg_len)
		{
			write(1, " ", 1);
			sym->check++;
		}
	return (sym->arg_len + sym->check);
}
