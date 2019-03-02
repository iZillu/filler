/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 07:09:51 by hmuravch          #+#    #+#             */
/*   Updated: 2018/09/05 08:07:23 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	got_enemy_positions(t_fl *fl)
{
	while (fl->p.foe.y < fl->map_size.y && fl->p.foe.x < fl->map_size.x)
	{
		while (fl->p.foe.y < fl->map_size.y)
		{
			while (fl->p.foe.x < fl->map_size.x)
			{
				if (fl->map[fl->p.foe.y][fl->p.foe.x] == fl->enemy)
					fl->heat_map[fl->p.foe.y][fl->p.foe.x] = -1;
				fl->p.foe.x++;
			}
			fl->p.foe.x = 0;
			fl->p.foe.y++;
		}
	}
}

void	fill_vertically(t_fl *fl, int y, int x, int i)
{
	int	tmp_y;
	int tmp_i;

	tmp_i = i;
	if (y - 1 >= 0)
	{
		tmp_y = y - 1;
		while (tmp_y >= 0)
			if (tmp_i <= fl->heat_map[tmp_y][x] || fl->heat_map[tmp_y][x] == 0)
				fl->heat_map[tmp_y--][x] = tmp_i++;
			else
				break ;
	}
	tmp_i = i;
	if (y + 1 < fl->map_size.y)
	{
		tmp_y = y + 1;
		while (tmp_y < fl->map_size.y)
			if (tmp_i <= fl->heat_map[tmp_y][x] || fl->heat_map[tmp_y][x] == 0)
				fl->heat_map[tmp_y++][x] = tmp_i++;
			else
				break ;
	}
}

void	fill_horizontally(t_fl *fl, int y, int x, int i)
{
	int	tmp_x;
	int tmp_i;

	tmp_i = i;
	if (x - 1 >= 0)
	{
		tmp_x = x - 1;
		while (tmp_x >= 0)
			if (tmp_i <= fl->heat_map[y][tmp_x] || fl->heat_map[y][tmp_x] == 0)
				fl->heat_map[y][tmp_x--] = tmp_i++;
			else
				break ;
	}
	tmp_i = i;
	if (x + 1 < fl->map_size.x)
	{
		tmp_x = x + 1;
		while (tmp_x < fl->map_size.x)
			if (tmp_i <= fl->heat_map[y][tmp_x] || fl->heat_map[y][tmp_x] == 0)
				fl->heat_map[y][tmp_x++] = tmp_i++;
			else
				break ;
	}
}

void	fill_heat_map(t_fl *fl)
{
	while (fl->p.coord.y < fl->map_size.y)
	{
		while (fl->p.coord.x < fl->map_size.x)
		{
			if (fl->heat_map[fl->p.coord.y][fl->p.coord.x] == -1)
			{
				fill_horizontally(fl, fl->p.coord.y, fl->p.coord.x, 1);
				fill_vertically(fl, fl->p.coord.y, fl->p.coord.x, 1);
				fill_diagonally_down_left(fl, fl->p.coord.y, fl->p.coord.x, 2);
				fill_diagonally_down_right(fl, fl->p.coord.y, fl->p.coord.x, 2);
				fill_diagonally_up_left(fl, fl->p.coord.y, fl->p.coord.x, 2);
				fill_diagonally_down_right(fl, fl->p.coord.y, fl->p.coord.x, 2);
			}
			fl->p.coord.x++;
		}
		fl->p.coord.x = 0;
		fl->p.coord.y++;
	}
}
