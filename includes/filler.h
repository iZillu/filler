/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 02:40:31 by hmuravch          #+#    #+#             */
/*   Updated: 2018/09/07 06:46:02 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

typedef struct	s_coordinates
{
	int		x;
	int		y;

}				t_c;

typedef struct	s_piece_info
{
	int			stars;
	t_c			foe;
	t_c			coord;
	t_c			piece;
	t_c			min_star;
	t_c			max_star;
	t_c			valid_coord;
	t_c			output_coord;
	t_c			*star_coord;

}				t_pinfo;

typedef struct	s_filler
{
	char		protect;
	char		enemy;
	char		player;
	t_c			map_size;
	int			errnum;
	int			save_piece_y;
	short int	**heat_map;
	char		**map;
	char		**figure;
	t_pinfo		p;
}				t_fl;

void			algorithm(t_fl *fl);
void			initialize(t_fl *fl);
void			fill_heat_map(t_fl *fl);
void			valid_position(t_fl *fl);
void			take_min_stars(t_fl *fl);
void			take_max_stars(t_fl *fl);
void			take_stars_position(t_fl *fl);
void			count_of_stars(t_fl *fl);
void			got_enemy_positions(t_fl *fl);
void			fill_vertically(t_fl *fl, int y, int x, int i);
void			fill_horizontally(t_fl *fl, int y, int x, int i);
void			fill_diagonally_up_left(t_fl *fl, int y, int x, int i);
void			fill_diagonally_up_right(t_fl *fl, int y, int x, int i);
void			fill_diagonally_down_left(t_fl *fl, int y, int x, int i);
void			fill_diagonally_down_right(t_fl *fl, int y, int x, int i);

#endif
