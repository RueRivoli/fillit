/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 12:26:45 by cchameyr          #+#    #+#             */
/*   Updated: 2017/02/03 15:47:03 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

static int		valid_sharp(t_tetris *tetri, int x, int y, int nb_sharp)
{
	if (tetri->form[y][x] == '#')
	{
		nb_sharp++;
		if (nb_sharp < 5)
		{
			tetri->coord_x[nb_sharp - 1] = x;
			tetri->coord_y[nb_sharp - 1] = y;
		}
	}
	return (nb_sharp);
}

int				check_valid_char(t_tetris *tetri)
{
	int		x;
	int		y;
	int		nb_sharp;

	while (tetri)
	{
		nb_sharp = 0;
		y = -1;
		while (++y < 4)
		{
			x = -1;
			while (++x < 4)
			{
				nb_sharp = valid_sharp(tetri, x, y, nb_sharp);
				if (tetri->form[y][x] != '.' && tetri->form[y][x] != '#')
					return (_ERROR_);
			}
		}
		if (nb_sharp != 4)
			return (_ERROR_);
		tetri = tetri->next;
	}
	return (_SUCCESS_);
}
