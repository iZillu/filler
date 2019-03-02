/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_diagonally.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 06:28:28 by hmuravch          #+#    #+#             */
/*   Updated: 2018/09/05 08:15:03 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	fill_diagonally_up_left(t_fl *fl, int y, int x, int i)
{
	int	tmp_y;
	int	tmp_x;
	int	tmp_i;

	tmp_i = i;
	if (y - 1 >= 0 && x - 1 >= 0)
	{
		tmp_y = y - 1;
		tmp_x = x - 1;
		while (tmp_y >= 0 && tmp_x >= 0)
		{
			if (tmp_i <= fl->heat_map[tmp_y][tmp_x]
			|| fl->heat_map[tmp_y][tmp_x] == 0)
			{
				fill_horizontally(fl, tmp_y, tmp_x, tmp_i + 1);
				fill_vertically(fl, tmp_y, tmp_x, tmp_i + 1);
				fl->heat_map[tmp_y--][tmp_x--] = tmp_i;
				tmp_i += i;
			}
			else
				break ;
		}
	}
}

void	fill_diagonally_down_right(t_fl *fl, int y, int x, int i)
{
	int	tmp_y;
	int	tmp_x;
	int	tmp_i;

	tmp_i = i;
	if (y + 1 < fl->map_size.y && x + 1 < fl->map_size.x)
	{
		tmp_y = y + 1;
		tmp_x = x + 1;
		while (tmp_y < fl->map_size.y && tmp_x < fl->map_size.x)
		{
			if (tmp_i <= fl->heat_map[tmp_y][tmp_x]
			|| fl->heat_map[tmp_y][tmp_x] == 0)
			{
				fill_horizontally(fl, tmp_y, tmp_x, tmp_i + 1);
				fill_vertically(fl, tmp_y, tmp_x, tmp_i + 1);
				fl->heat_map[tmp_y++][tmp_x++] = tmp_i;
				tmp_i += i;
			}
			else
				break ;
		}
	}
}

void	fill_diagonally_up_right(t_fl *fl, int y, int x, int i)
{
	int	tmp_y;
	int	tmp_x;
	int	tmp_i;

	tmp_i = i;
	if (y - 1 >= 0 && x + 1 < fl->map_size.x)
	{
		tmp_y = y - 1;
		tmp_x = x + 1;
		while (tmp_y >= 0 && tmp_x < fl->map_size.x)
		{
			if (tmp_i <= fl->heat_map[tmp_y][tmp_x]
			|| fl->heat_map[tmp_y][tmp_x] == 0)
			{
				fill_horizontally(fl, tmp_y, tmp_x, tmp_i + 1);
				fill_vertically(fl, tmp_y, tmp_x, tmp_i + 1);
				fl->heat_map[tmp_y--][tmp_x++] = tmp_i;
				tmp_i += i;
			}
			else
				break ;
		}
	}
}

void	fill_diagonally_down_left(t_fl *fl, int y, int x, int i)
{
	int	tmp_y;
	int	tmp_x;
	int	tmp_i;

	tmp_i = i;
	if (y + 1 < fl->map_size.y && x - 1 >= 0)
	{
		tmp_y = y + 1;
		tmp_x = x - 1;
		while (tmp_y < fl->map_size.y && tmp_x >= 0)
		{
			if (tmp_i <= fl->heat_map[tmp_y][tmp_x]
			|| fl->heat_map[tmp_y][tmp_x] == 0)
			{
				fill_horizontally(fl, tmp_y, tmp_x, tmp_i + 1);
				fill_vertically(fl, tmp_y, tmp_x, tmp_i + 1);
				fl->heat_map[tmp_y++][tmp_x--] = tmp_i;
				tmp_i += i;
			}
			else
				break ;
		}
	}
}
