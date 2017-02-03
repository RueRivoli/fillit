/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:16:48 by fgallois          #+#    #+#             */
/*   Updated: 2017/02/03 13:10:07 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

t_fillit	fill(t_fillit fillit, t_tetris *tetri, int x, int y)
{
	int		cpt;
	int		fx;
	int		fy;

	cpt = 0;
	while (cpt < 4)
	{
		fx = (tetri->coord_x[cpt] - tetri->coord_x[0]) + x;
		fy = (tetri->coord_y[cpt] - tetri->coord_y[0]) + y;
		fillit.square[fy][fx] = (char)(tetri->index + 'A' - 1);
		cpt++;
	}
	return (fillit);
}
