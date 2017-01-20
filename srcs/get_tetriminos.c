/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetriminos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 12:22:04 by cchameyr          #+#    #+#             */
/*   Updated: 2017/01/20 12:22:40 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

static int		create_chaine(t_tetris **list, char *str)
{
	static int	i = 0;
	static int	j = 1;

	if (str[0] == 0)
	{
		if (i != 0 || j != 0)
			return (_ERROR_);
		else
			j = j + 1;
	}
	else
	{
		if (i == 0 && j == 0)
			return (_ERROR_);
		if (i == 0 && j == 1)
		{
			(*list)->next = ft_memalloc(sizeof(t_tetris));
			(*list) = (*list)->next;
			(*list)->next = NULL;
		}
		j = 0;
		ft_strncpy((*list)->form[i++], str, 4);
		if (i == 4)
		{
			i = 0;
		}
	}
	return (_SUCCESS_);
}

int				get_tetriminos(t_fillit *f, char *path)
{
	char	*str;
	int		fd;
	t_tetris	*list;

	if ((fd = open(path, O_RDONLY)) == -1)
		return (_ERROR_);
//	f->tetri = ft_memalloc(sizeof(t_tetris));
//	list = f->tetri;
	while (get_next_line(fd, &str))
	{
		if (create_chaine(&list, str) == _ERROR_)
			return (_ERROR_);
	}
	return (_SUCCESS_);
}

