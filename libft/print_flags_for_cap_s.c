/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags_for_S.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 10:42:25 by hmuravch          #+#    #+#             */
/*   Updated: 2018/08/15 10:43:03 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_width_not_minus_cap_s(t_sym *sym)
{
	if (!sym->minus)
		while (sym->width-- > sym->arg_len)
		{
			write(1, " ", 1);
			sym->check++;
		}
}

void	print_width_yes_minus_cap_s(t_sym *sym)
{
	if (sym->minus)
		while (sym->width-- > sym->arg_len)
		{
			write(1, " ", 1);
			sym->check++;
		}
}
