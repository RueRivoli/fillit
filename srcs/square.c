/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 13:16:02 by cchameyr          #+#    #+#             */
/*   Updated: 2017/01/30 18:51:13 by fgallois         ###   ########.fr       */
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
		if (fx < 0 || fy < 0 || fx >= fillit->size || fy >= fillit->size || fillit->square[fy][fx] != '.')
			return (0);
		cpt++;
	}
	return (1);
}

//Recherche un match a partir des x et y en parametre
int		match_in_all(t_fillit *fillit, t_tetris *tetri, int curr_x, int curr_y)
{
	while (curr_x < fillit->size && curr_y < fillit->size)
	{
		if (match_in_square(fillit, tetri) == 1)
		{
			tetri->pos[0] = curr_y;
			tetri->pos[1] = curr_x;
			return (1);
		}
		curr_x++;
		if (curr_x == fillit->size)
		{
			curr_x = 0;
			curr_y++;
		}
	}
	return (0);
}

