/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 12:03:26 by hmuravch          #+#    #+#             */
/*   Updated: 2018/09/07 05:52:25 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_one_figure(t_fl *fl)
{
	int	check;
	int	i;

	i = 0;
	check = 0;
	while (i < fl->p.stars)
	{
		if (fl->map[fl->p.valid_coord.y + fl->p.star_coord[i].y]
			[fl->p.valid_coord.x + fl->p.star_coord[i].x] == fl->player)
			check++;
		i++;
	}
	if (check == 1)
		return (1);
	return (0);
}

int		check_no_enemy_figure(t_fl *fl)
{
	int	check;
	int	i;

	i = 0;
	check = 0;
	while (i < fl->p.stars)
	{
		if (fl->map[fl->p.valid_coord.y + fl->p.star_coord[i].y]
			[fl->p.valid_coord.x + fl->p.star_coord[i].x] == fl->enemy)
			check++;
		i++;
	}
	if (check == 0)
		return (1);
	return (0);
}

int		calculate_distance(t_fl *fl)
{
	int	distance;
	int	i;

	i = 0;
	distance = 0;
	while (i < fl->p.stars)
	{
		distance += fl->heat_map[fl->p.star_coord[i].y + fl->p.valid_coord.y]
		[fl->p.star_coord[i].x + fl->p.valid_coord.x];
		i++;
	}
	return (distance);
}

void	valid_position(t_fl *fl)
{
	int	validation;
	int	distance;

	distance = 99999;
	fl->p.valid_coord.x = 0 - fl->p.min_star.x;
	fl->p.valid_coord.y = 0 - fl->p.min_star.y;
	while (fl->p.valid_coord.y + fl->p.max_star.y < fl->map_size.y)
	{
		while (fl->p.valid_coord.x + fl->p.max_star.x < fl->map_size.x)
		{
			validation = 0;
			check_one_figure(fl) ? validation++ : false;
			check_no_enemy_figure(fl) ? validation++ : false;
			if (validation == 2)
				if (distance > calculate_distance(fl))
				{
					distance = calculate_distance(fl);
					fl->p.output_coord.x = fl->p.valid_coord.x;
					fl->p.output_coord.y = fl->p.valid_coord.y;
				}
			fl->p.valid_coord.x++;
		}
		fl->p.valid_coord.x = 0 - fl->p.min_star.x;
		fl->p.valid_coord.y++;
	}
}
