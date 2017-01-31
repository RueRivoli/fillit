/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 13:16:02 by cchameyr          #+#    #+#             */
/*   Updated: 2017/01/31 18:53:22 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

static int		minsize(t_tetris *t)
{
	int		total_sharp;
	int		size;

	while (t->next)
		t = t->next;
	total_sharp = t->index * 4;
	size = 3;
	while (size * size < total_sharp)
		size++;
	return (size);
}

void			init_square(t_fillit *f)
{
	int i;
	
	f->curr_x = 0;
	f->curr_y = 0;
	f->size = minsize(f->tetri);
	i = -1;
	while (++i < 26)
		ft_memset(f->square[i], '.', 26);
}

//Recherche un match a la ligne y et la colonne x
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

//Recherche un match a partir des x et y en parametre
int		match_in_all(t_fillit *fillit, t_tetris *tetri, int x, int y)
{
	while (x < fillit->size && y < fillit->size)
	{	
		if (match_in_square(fillit, tetri, x, y) == 1)
		{
			tetri->pos[0] = y;
			tetri->pos[1] = x;
			return (1);
		}
		x++;
		if (x == fillit->size)
		{
			x = 0;
			y++;
		}
	}
	return (0);
}

