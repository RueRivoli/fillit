/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 12:26:45 by cchameyr          #+#    #+#             */
/*   Updated: 2017/01/23 16:01:04 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

static int	check_valid_char(t_tetris *tetri)
{
	int		x;
	int		y;
	int		nb_sharp;

	y = -1;
	while (tetri)
	{
		nb_sharp = 0;
		while (++y < 4)
		{
			x = -1;
			while (++x < 4)
			{
				if (tetri->form[y][x] == '#')
					nb_sharp++;
				else if (tetri->form[y][x] != '.')
					return (_ERROR_);
			}
		}
		if (nb_sharp != 4)
			return (_ERROR_);
		tetri = tetri->next;
	}
	return (_SUCCESS_);
}

static	int	get_coordinate(t_tetris *tetri)
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

static int	check_valid_link(t_tetris *tetri)
{
	while (tetri)
	{
		if (get_coordinate(tetri) == _ERROR_)
			return (_ERROR_);
		tetri= tetri->next;
	}
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
