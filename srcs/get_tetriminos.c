/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetriminos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 12:22:04 by cchameyr          #+#    #+#             */
/*   Updated: 2017/01/23 12:58:08 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

t_tetris	*last_maillon(t_tetris **begin)
{
	t_tetris	*list;

	list = *begin;
	if (!list)
	{
<<<<<<< HEAD
		*begin = ft_memalloc(sizeof(t_tetris));
=======
		(*begin) = ft_memalloc(sizeof(t_tetris));
>>>>>>> b2e0c1c3b80c98ed0a795f65646b10f27e85af9b
		(*begin)->next = NULL;
		return (*begin);
	}
	else
	{
		while (list->next)// list = list->next
			list = list->next;
		list->next = ft_memalloc(sizeof(t_tetris));
		list = list->next;
		list->next = NULL;
	}
	return (list);
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
<<<<<<< HEAD
				list = last_maillon(begin);
=======
		{
			list = last_maillon(begin);
			// faire une fonction qui prend l'adresse de fillit->tetri (begin)
			// Si arrivé dans la fonction, begin vaut NULL -> le malloc;
			// Si arrivé dans la fonction, begin n'est pas NULL -> aller a la fin, et malloc le dernier maillon
			// La fonction retourne le dernier maillon.
			//
		}
>>>>>>> b2e0c1c3b80c98ed0a795f65646b10f27e85af9b
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

	if ((fd = open(path, O_RDONLY)) == -1)
		return (_ERROR_);
<<<<<<< HEAD
	f->tetri = NULL;
=======
	f->tetri = ft_memalloc(sizeof(t_tetris));
	if (f->tetri== NULL)
		exit(0);
>>>>>>> b2e0c1c3b80c98ed0a795f65646b10f27e85af9b
	while (get_next_line(fd, &str))
	{
		if (create_chaine(&f->tetri, str) == _ERROR_)
			return (_ERROR_);
	}
	return (_SUCCESS_);
}

