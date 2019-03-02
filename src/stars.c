/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 12:05:16 by hmuravch          #+#    #+#             */
/*   Updated: 2018/09/07 05:01:50 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	count_of_stars(t_fl *fl)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < fl->p.piece.y)
	{
		while (x < fl->p.piece.x)
		{
			if (fl->figure[y][x] == '*')
				fl->p.stars++;
			x++;
		}
		x = 0;
		y++;
	}
}

void	take_stars_position(t_fl *fl)
{
	int	i;

	i = 0;
	while (i < fl->p.stars)
	{
		while (fl->p.star_coord[i].y < fl->p.piece.y)
		{
			while (fl->p.star_coord[i].x < fl->p.piece.x)
			{
				if (fl->figure[fl->p.star_coord[i].y]
				[fl->p.star_coord[i].x] == '*')
					break ;
				fl->p.star_coord[i].x++;
			}
			if (fl->figure[fl->p.star_coord[i].y]
			[fl->p.star_coord[i].x] == '*')
			{
				fl->figure[fl->p.star_coord[i].y][fl->p.star_coord[i].x] = '.';
				break ;
			}
			fl->p.star_coord[i].x = 0;
			fl->p.star_coord[i].y++;
		}
		i++;
	}
}

void	take_min_stars(t_fl *fl)
{
	int	i;

	i = 0;
	fl->p.min_star.x = fl->p.star_coord[i].x;
	fl->p.min_star.y = fl->p.star_coord[i].y;
	while (i < fl->p.stars)
	{
		if (fl->p.min_star.x > fl->p.star_coord[i].x)
			fl->p.min_star.x = fl->p.star_coord[i].x;
		i++;
	}
}

void	take_max_stars(t_fl *fl)
{
	int	i;

	i = 0;
	fl->p.max_star.x = fl->p.star_coord[i].x;
	fl->p.max_star.y = fl->p.star_coord[i].y;
	while (i < fl->p.stars)
	{
		if (fl->p.max_star.x < fl->p.star_coord[i].x)
			fl->p.max_star.x = fl->p.star_coord[i].x;
		if (fl->p.max_star.y < fl->p.star_coord[i].y)
			fl->p.max_star.y = fl->p.star_coord[i].y;
		i++;
	}
}
