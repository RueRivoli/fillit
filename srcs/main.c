/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 12:15:21 by cchameyr          #+#    #+#             */
/*   Updated: 2017/01/19 14:58:43 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

static int		create_chaine(t_tetris **list, char *str)
{
	static int i = 0;
	static int j = 0;

		if (str[0] == '\n')
		{
			if (i != 0 || j != 0)
				return (_ERROR_);
			else
				j = j + 1;
		}
		else
		{
			j = 0;
			(*list)->form[i++] = str;
			if (i == 4)
			{
				i = 0;
				(*list)->next = ft_memalloc(sizeof(t_tetris));
				(*list) = (*list)->next;
				(*list)->next = NULL;
			}
		}
	return (_SUCCESS_);
}

static int		get_tetriminos(t_fillit *f, char *path)
{
	char	*str;
	int		fd;
	t_tetris	*list;

	if ((fd = open(path, O_RDONLY)) == -1)
		return (_ERROR_);
	f->tetri = ft_memalloc(sizeof(t_tetris *));
	list = f->tetri;
	while (get_next_line(fd, &str))
	{
		if (create_chaine(&list, str) == _ERROR_)
			return (_ERROR_);
	}
	return (_SUCCESS_);
}


int				main(int argc, char **argv)
{
	if (argc != 2)
		ft_putstr("usage :\t./fillit [-V --Visual] [source_file].fillit\n");
	else
	{
		if (get_tetriminos(&f, argv[1]) == _ERROR_)
			ft_putstr("Error\n");
	}

	(void)f;
	(void)argc;
	(void)argv;
	return (0);
}
