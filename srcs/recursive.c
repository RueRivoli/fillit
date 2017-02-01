/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 14:24:09 by fgallois          #+#    #+#             */
/*   Updated: 2017/02/01 15:15:56 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

static int		check_checked_tetri(t_tetris *tetri)
{
	t_tetris *list;

	list = tetri;
	while (list && list->checked)
	{
		if (same_tetrim(list, tetri) == 0)
			return (0);
		list = list->next;
	}
	return (1);
}

static void		init_checked_tetri(t_tetris *tetri)
{
	t_tetris *list;
	list = tetri->next;
	while (list)
	{
		list->checked = 0;
		list = list->next;
	}
}



int		recursive(t_fillit f, t_tetris *tetri)
{
	if (tetri == NULL)
		return (_SUCCESS_);
	tetri->checked = 1;
	f.curr_y = -1;
	while (++f.curr_y < f.size)
	{
		f.curr_x = -1;
		while (++f.curr_x < f.size)
		{
			if (match_in_square(&f, tetri, f.curr_x, f.curr_y))
			{
				if (recursive(fill(f, tetri, f.curr_x, f.curr_y), tetri->next))
					return (_SUCCESS_);
				else
				{
					if (check_checked_tetri(tetri))
						return (_ERROR_);
					else
						init_checked_tetri(tetri);
				}
			}
		}
	}
	return (_ERROR_);
}
