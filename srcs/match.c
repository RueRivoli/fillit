/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:32:57 by fgallois          #+#    #+#             */
/*   Updated: 2017/02/01 15:48:15 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

int		same_tetrim(t_tetris *tetri1, t_tetris *tetri2)
{
	int		cpt;
	int		fx;
	int		fy;
	int		gx;
	int		gy;

	cpt = 1;
	while (cpt < 4)
	{
		fx = tetri1->coord_x[cpt] - tetri1->coord_x[0];
		fy = tetri1->coord_y[cpt] - tetri1->coord_y[0];
		gx = tetri2->coord_x[cpt] - tetri2->coord_x[0];
		gy = tetri2->coord_y[cpt] - tetri2->coord_y[0];
		if (fx != gx || fy != gy)
			return (0);
		cpt++;
	}
	return (1);
}

int			match_in_square(t_fillit *fillit, t_tetris *tetri, int x, int y)
{
	int		cpt;
	int		fx;
	int		fy;

	cpt = 1;
	while (cpt < 4)
	{	
		fx = (tetri->coord_x[cpt] - tetri->coord_x[0]) + x;
		fy = (tetri->coord_y[cpt] - tetri->coord_y[0]) + y;
		if (fx < 0 || fy < 0 || fx >= fillit->size || fy >= fillit->size || fillit->square[fy][fx] != '.')
			return (0);
		cpt++;
	}
	return (1);
}
