/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetriminos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 12:22:04 by cchameyr          #+#    #+#             */
/*   Updated: 2017/02/01 15:44:03 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

static t_tetris		*new_maillon(int index)
{
	t_tetris		*list;

	list = ft_memalloc(sizeof(t_tetris));
	list->next = NULL;
	list->index = index + 1;
	ft_bzero(list->coord_x, 4);
	ft_bzero(list->coord_y, 4);
	ft_bzero(list->pos, 2);
	list->pos[0] = -1;
	list->pos[1] = -1;
	list->checked = 0;
	return (list);
}

static t_tetris		*last_maillon(t_tetris **begin)
{
	t_tetris	*list;

	list = *begin;
	if (!list)
	{
		*begin = new_maillon(0);
		return (*begin);
	}
	else
	{
		while (list->next)
			list = list->next;
		list->next = new_maillon(list->index);
		return (list->next);
	}
}

static int		create_chaine(t_tetris **begin, char *str)
{
	static t_tetris	*list;
	static int	i = 0;
	static int	j = 1;

	if (str[0] == 0)
	{
		if (i != 0 || j != 0)
			return (_ERROR_);
		else
			j++;
	}
	else
	{
		if (i == 0 && j == 0)
			return (_ERROR_);
		if (i == 0 && j == 1)
				list = last_maillon(begin);
		j = 0;
		ft_strncpy(list->form[i++], str, 4);
		if (i == 4)
			i = 0;
	}
	return (_SUCCESS_);
}

int				get_tetriminos(t_fillit *f, char *path)
{
	char	*str;
	int		fd;
	int		i;
	int ret;

	if ((fd = open(path, O_RDONLY)) == -1)
		return (_ERROR_);
	f->tetri = NULL;
	i = 0;
	while ((ret = get_next_line(fd, &str)))
	{
		if (ret == -1)
			 display_error();
		if (str[0] != 0 && ft_strlen(str) != 4)
			return (_ERROR_);
		if (create_chaine(&f->tetri, str) == _ERROR_)
			return (_ERROR_);
		if (i == 4)
			i = 0;
		else
			i++;
	}
	if (i != 4)
		return (_ERROR_);
	return (_SUCCESS_);
}

