/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 02:31:44 by hmuravch          #+#    #+#             */
/*   Updated: 2018/09/07 09:31:02 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void				put_error(void)
{
	ft_putstr_fd("ERROR", 2);
	exit(1);
}

static inline void	parse_figure(t_fl *fl, char *tmp)
{
	char			*line;
	int				i;

	i = -1;
	fl->p.piece.y = ft_atoi(tmp);
	while (ft_is_whitespace(*tmp))
		tmp++;
	tmp = ft_strchr(tmp, ' ');
	fl->p.piece.x = ft_atoi(tmp);
	if (fl->figure != NULL)
		while (++i < fl->save_piece_y)
			ft_strdel(&fl->figure[i]);
	fl->figure != NULL ? free(fl->figure) : false;
	fl->figure = (char **)ft_memalloc(sizeof(char *) * (fl->p.piece.y + 1));
	i = -1;
	while (++i < fl->p.piece.y)
		fl->figure[i] = (char *)ft_memalloc(sizeof(char) * (fl->p.piece.x + 1));
	i = -1;
	while (++i < fl->p.piece.y && (fl->errnum = get_next_line(0, &line)))
	{
		if (fl->errnum == -1 || ft_strlen(line) != (size_t)fl->p.piece.x)
			put_error();
		ft_strcpy(fl->figure[i], line);
		ft_strdel(&line);
	}
}

static inline void	parse_map(t_fl *fl, char *tmp, int i, int j)
{
	char			*line;

	fl->map_size.y = ft_atoi(tmp);
	while (ft_is_whitespace(*tmp))
		tmp++;
	tmp = ft_strchr(tmp, ' ');
	fl->map_size.x = ft_atoi(tmp);
	fl->errnum = get_next_line(0, &line);
	(fl->errnum == -1) ? put_error() : free(line);
	if (fl->map == NULL)
	{
		fl->map = (char **)ft_memalloc(sizeof(char *) * (fl->map_size.y + 1));
		while (++j < fl->map_size.y)
			fl->map[j] = ft_memalloc(sizeof(char) * (fl->map_size.x + 1));
	}
	while (++i < fl->map_size.y && (fl->errnum = get_next_line(0, &line)))
	{
		if (fl->errnum == -1 || ft_strlen(line) != (size_t)fl->map_size.x + 4)
			put_error();
		ft_strcpy(fl->map[i], line + 4);
		ft_strdel(&line);
		j = -1;
		while (fl->map[i][++j])
			fl->map[i][j] = ft_tolower(fl->map[i][j]);
	}
}

int					main(void)
{
	t_fl				fl;
	char				*line;

	ft_bzero(&fl, sizeof(fl));
	while ((fl.errnum = get_next_line(0, &line)))
	{
		ft_bzero(&fl.p, sizeof(fl.p));
		if (fl.errnum == -1)
			put_error();
		else if (ft_strstr(line, "hmuravch.filler]"))
			fl.player = (ft_strstr(line, "p1")) ? 'o' : 'x';
		else if (ft_strstr(line, "Plateau "))
			parse_map(&fl, ft_strchr(line, ' '), -1, -1);
		else if (ft_strstr(line, "Piece "))
		{
			parse_figure(&fl, ft_strchr(line, ' '));
			algorithm(&fl);
		}
		free(line);
	}
	return (0);
}
