/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 12:15:21 by cchameyr          #+#    #+#             */
/*   Updated: 2017/01/19 18:21:26 by fgallois         ###   ########.fr       */
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

static int		get_tetriminos(t_fillit *f, char *path)
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

int		check_tetriminos(t_tetris *tetri)
{
	(void)tetri;
	return (1);
}

void	display_list(t_tetris *list)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (list)
	{
		while (j < 4)
		{
			i = 0;
			while (i < 4)
			{
				ft_putchar(list->form[j][i++]);
			}
			ft_putchar('\n');
			j++;
		}
		j = 0;
		ft_putchar('\n');
		list = list->next;
	}
}

int				main(int argc, char **argv)
{
	t_fillit f;

	if (argc != 2)
		ft_putstr("usage :\t./fillit [-V --Visual] [source_file].fillit\n");
	else
	{
		if (get_tetriminos(&f, argv[1]) == _ERROR_)
			ft_putstr("Error\n");
		display_list(f.tetri);
		if (check_tetriminos(f.tetri) == _ERROR_)
			ft_putstr("Error\n");
	}

	(void)f;
	(void)argc;
	(void)argv;
	return (0);
}
