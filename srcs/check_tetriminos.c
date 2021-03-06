/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 12:26:45 by cchameyr          #+#    #+#             */
/*   Updated: 2017/02/15 14:46:33 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

static int		check_link(int lines[4], int column[4])
{
	int i;
	int j;
	int cpt;

	cpt = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if ((i != j) && ((lines[i] == lines[j] &&
						ft_abs(column[i] - column[j]) == 1) ||
						(column[i] == column[j] &&
						ft_abs(lines[i] - lines[j]) == 1)))
				cpt++;
		}
	}
	if (cpt == 6 || cpt == 8)
		return (_SUCCESS_);
	else
		return (_ERROR_);
}

static	int		get_coordinate(t_tetris *tetri)
{
	int lines[4];
	int column[4];
	int	x;
	int	y;
	int cpt;

	cpt = 0;
	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (tetri->form[y][x] == '#')
			{
				lines[cpt] = y;
				column[cpt] = x;
				cpt++;
			}
		}
	}
	if (check_link(lines, column) == _ERROR_)
		return (_ERROR_);
	return (_SUCCESS_);
}

static int		check_valid_link(t_tetris *tetri)
{
	while (tetri)
	{
		if (get_coordinate(tetri) == _ERROR_)
			return (_ERROR_);
		tetri = tetri->next;
	}
	return (_SUCCESS_);
}

int				check_tetriminos(t_tetris *tetri)
{
	if (check_valid_char(tetri) == _ERROR_)
		return (_ERROR_);
	if (check_valid_link(tetri) == _ERROR_)
		return (_ERROR_);
	return (_SUCCESS_);
}
