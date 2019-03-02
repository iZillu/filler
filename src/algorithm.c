/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 08:06:28 by hmuravch          #+#    #+#             */
/*   Updated: 2018/09/07 06:47:05 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	initialize(t_fl *fl)
{
	int		tmp_y;

	tmp_y = 0;
	fl->protect = 'A';
	fl->heat_map = ft_memalloc(sizeof(short *) * fl->map_size.y);
	while (tmp_y < fl->map_size.y)
		fl->heat_map[tmp_y++] = ft_memalloc(sizeof(short) * fl->map_size.x);
}

void	algorithm(t_fl *fl)
{
	int	i;

	i = -1;
	fl->enemy = (fl->player == 'o') ? 'x' : 'o';
	if (!fl->protect)
		initialize(fl);
	got_enemy_positions(fl);
	fill_heat_map(fl);
	count_of_stars(fl);
	fl->p.star_coord = ft_memalloc(sizeof(t_c) * fl->p.stars);
	take_stars_position(fl);
	take_min_stars(fl);
	take_max_stars(fl);
	valid_position(fl);
	ft_printf("%i %i\n", fl->p.output_coord.y, fl->p.output_coord.x);
	fl->save_piece_y = fl->p.piece.y;
	while (++i < fl->map_size.y)
		ft_bzero(fl->heat_map[i], fl->map_size.x);
	free(fl->p.star_coord);
}
