/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 05:09:34 by hmuravch          #+#    #+#             */
/*   Updated: 2018/08/20 07:21:45 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			main_thing(char **line, t_list *elem)
{
	char	*string;
	char	*new;

	string = ft_strchr(elem->content, '\n');
	if (string)
	{
		ft_strdel(line);
		*line = ft_strsub(elem->content, 0, (string - (char*)elem->content));
		new = ft_strsub(elem->content, string - (char*)elem->content + 1,
			ft_strlen(string));
		ft_memdel(&elem->content);
		elem->content = new;
	}
	else
	{
		*line = ft_strdup(elem->content);
		ft_memdel(&elem->content);
	}
}

static t_list	*get_buffer(t_list **start, int fd)
{
	t_list	*tmp;

	tmp = *start;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(start, tmp);
	tmp = *start;
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	t_list			*elem;
	static t_list	*start;
	char			buf[BUFF_SIZE + 1];
	int				brain;
	void			*tmp;

	if ((fd < 0 || fd > 4864 || !line || BUFF_SIZE < 1 || read(fd, buf, 0) < 0))
		return (-1);
	PROTECT((*line = ft_strnew(1)));
	elem = get_buffer(&start, fd);
	while ((brain = read(fd, buf, BUFF_SIZE)))
	{
		tmp = ft_strdup(elem->content);
		buf[brain] = '\0';
		ft_memdel(&elem->content);
		elem->content = ft_strjoin(tmp, buf);
		ft_memdel(&tmp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if ((brain < BUFF_SIZE && !(char*)elem->content)
		|| !ft_strlen(elem->content))
		return (0);
	main_thing(line, elem);
	return (1);
}
