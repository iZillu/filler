/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 05:23:00 by hmuravch          #+#    #+#             */
/*   Updated: 2018/07/27 00:19:20 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	detect_sign(va_list arg, const char *format, t_sym *sym)
{
	t_type	type;
	int		end;

	end = 0;
	if (*format == 's' && ++end)
		sym->size == 3 ? (sym->bits += print_cap_s(arg, type.cap_s, sym))
	: (sym->bits += print_s(arg, sym, type.s));
	if (*format == 'c' && ++end)
		sym->size == 3 ? (sym->bits += print_cap_c(arg, &type.cap_c, sym))
	: (sym->bits += print_c(arg, &type.c, sym));
	*format == 'i' || *format == 'd' ?
	sym->bits += print_i_or_d(arg, sym, &type.d) : end++;
	*format == 'p' ? sym->bits += print_p(arg, &type.p, sym) : end++;
	*format == '%' ? sym->bits += print_percent(sym) : end++;
	*format == 'C' ? sym->bits += print_cap_c(arg, &type.cap_c, sym) : end++;
	*format == 'S' ? sym->bits += print_cap_s(arg, type.cap_s, sym) : end++;
	*format == 'D' ? sym->bits += print_cap_d(arg, &type.cap_d, sym) : end++;
	*format == 'o' ? sym->bits += print_o(arg, &type.o, sym) : end++;
	*format == 'O' ? sym->bits += print_cap_o(arg, &type.cap_o, sym) : end++;
	*format == 'u' ? sym->bits += print_u(arg, &type.u, sym) : end++;
	*format == 'U' ? sym->bits += print_cap_u(arg, &type.cap_u, sym) : end++;
	*format == 'x' ? sym->bits += print_x(arg, &type.x, sym) : end++;
	*format == 'X' ? sym->bits += print_cap_x(arg, &type.cap_x, sym) : end++;
	if (end == 12)
		--sym->crutch;
}

int		ft_printf(const char *format, ...)
{
	va_list	arg;
	t_sym	sym;

	sym.i = -1;
	sym.bits = 0;
	initializer(&sym);
	va_start(arg, format);
	while (format[++sym.i] != '\0')
	{
		while (format[sym.i] == '%')
		{
			if (format[++sym.i] == '\0')
				break ;
			missing_flags(format, &sym);
			checking_sizes(format, &sym);
			detect_sign(arg, &format[sym.i++], &sym);
			!sym.crutch ? sym.i-- : 0;
			initializer(&sym);
			va_end(arg);
		}
		if (format[sym.i] == '\0')
			break ;
		write(1, &format[sym.i], 1) && sym.bits++;
	}
	return (sym.bits);
}
