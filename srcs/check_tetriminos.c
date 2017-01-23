/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 12:26:45 by cchameyr          #+#    #+#             */
/*   Updated: 2017/01/23 14:33:29 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

static int	check_valid_char(t_tetris *tetri)
{
	int		x;
	int		y;

	y = -1;
	while (tetri)
	{
		while (++y < 4)
		{
			x = -1;
			while (++x < 4)
			{
				if (tetri->form[y][x] != '.' && tetri->form[y][x] != '#')
					return (_ERROR_);
			}
		}
		tetri = tetri->next;
	}
	return (_SUCCESS_);
}

static int	check_valid_link(t_tetris *tetri)
{
	(void)tetri;
	return (_SUCCESS_);
}

int		check_tetriminos(t_tetris *tetri)
{
	if (check_valid_char(tetri) == _ERROR_)
		return (_ERROR_);
	if (check_valid_link(tetri) == _ERROR_)
		return (_ERROR_);
	return (_SUCCESS_);
}
