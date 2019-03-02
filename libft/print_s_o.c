/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_S_D_o_O_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 05:20:24 by hmuravch          #+#    #+#             */
/*   Updated: 2018/06/27 05:20:25 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	print_s(va_list arg, t_sym *sym, char *s)
{
	s = va_arg(arg, char *);
	if (!s)
		s = "(null)";
	sym->arg_len = ft_strlen(s);
	if (sym->precision < sym->arg_len && sym->dot)
		sym->arg_len = sym->precision;
	sym->save_arg_len = sym->arg_len;
	if (sym->minus == 0)
		while (sym->width > sym->arg_len)
		{
			write(1, " ", 1);
			sym->width--;
			sym->check++;
		}
	while (sym->arg_len--)
		write(1, s++, 1);
	if (sym->minus == 1)
		while (sym->width > sym->save_arg_len)
		{
			write(1, " ", 1);
			sym->width--;
			sym->check++;
		}
	return (sym->save_arg_len + sym->check);
}

size_t	print_cap_s(va_list arg, wchar_t *cap_s, t_sym *sym)
{
	char	*u_code;

	cap_s = va_arg(arg, wchar_t *);
	u_code = ft_strnew(0);
	if (cap_s)
		while (*cap_s)
		{
			sym->tmp = ft_strdup(u_code);
			sym->tmp2 = ft_putchar_unicode(*cap_s++, sym);
			ft_strdel(&u_code);
			u_code = ft_strjoin_free(sym->tmp, sym->tmp2, 1, 1);
		}
	else
	{
		u_code = "(null)";
		sym->arg_len = 6;
	}
	print_width_not_minus_cap_s(sym);
	ft_putstr(u_code);
	if (cap_s)
		ft_strdel(&u_code);
	print_width_yes_minus_cap_s(sym);
	return (sym->arg_len + sym->check);
}

size_t	print_o(va_list arg, uintmax_t *o, t_sym *sym)
{
	char	*str;

	*o = cast_uint(arg, sym);
	sym->save_precision = sym->precision;
	if (sym->sharp == 1 && !sym->precision && !sym->zero && *o != 0)
		str = ft_strjoin_free("0", (ft_itoa_base(*o, 8, 0)), 0, 0);
	else
		str = ft_itoa_base(*o, 8, 0);
	if (sym->dot && !sym->precision && *o == 0)
		str = NULL;
	sym->arg_len = ft_strlen(str);
	sym->save_width = sym->width;
	if (sym->precision < sym->width && sym->width && sym->precision)
		sym->width = sym->width - sym->precision + sym->arg_len;
	print_zero_o(o, sym);
	if (sym->minus == 0)
		print_width_o(sym);
	print_precision_o(o, sym);
	ft_putstr(str);
	ft_strdel(&str);
	if (sym->minus == 1)
		print_width_o(sym);
	return (sym->arg_len + sym->check);
}

size_t	print_cap_o(va_list arg, uintmax_t *cap_o, t_sym *sym)
{
	if (sym->size < 3)
		sym->size = 3;
	return (print_o(arg, cap_o, sym));
}
