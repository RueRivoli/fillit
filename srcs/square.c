/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 13:16:02 by cchameyr          #+#    #+#             */
/*   Updated: 2017/01/30 18:02:51 by fgallois         ###   ########.fr       */
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
	size = 2;
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

int			match_in_square(t_fillit *fillit, t_tetris *tetri)
{
	int		cpt;
	int		fx;
	int		fy;

	cpt = 1;
	while (cpt < 4)
	{
		fx = (tetri->coord_x[cpt] - tetri->coord_x[0]) + fillit->curr_x;
		fy = (tetri->coord_y[cpt] - tetri->coord_y[0]) + fillit->curr_y;
		if (fx < 0 || fy < 0 || fx >= fillit->size || fy >= fillit->size || fillit->square[fx][fy] != '.')
			return (0);
		cpt++;
	}
	return (1);
}

//Recherche un match a partir des x et y en parametre
int		match_in_all(t_fillit *fillit, t_tetris *tetri, int curr_x, int curr_y)
{
	int x;
	int y;

	x = curr_x;
	y = curr_y;
	while (x < fillit->size && y < fillit->size)
	{
		if (match_in_square(fillit, tetri))
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
