/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 14:24:09 by fgallois          #+#    #+#             */
/*   Updated: 2017/01/30 18:47:59 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

int		recursive(t_fillit *fillit, t_tetris *tetri)
{
	int x;
	int y;

	x = fillit->curr_x;
	y = fillit->curr_y;
	if (tetri == NULL)
		return (1);
	else
	{
		while (x < fillit->size && y < fillit->size)
		{
			ft_putnbr(match_in_all(fillit, tetri, x, y));
			if (match_in_all(fillit, tetri, x, y))
			{
				int a;
				int b;
				YOLO
				a = tetri->pos[0];
				b = tetri->pos[1];
				fill(fillit, tetri, a, b);
				if (recursive(fillit, tetri->next))
					return (1);
				else
				{
					empty(fillit, tetri, a, b);
					a = -1;
					b = -1;
				}
			}
			x++;
			if (x == fillit->size)
			{
				x = 0;
				y++;
			}
		}
	}
	return (0);
}

int		recursive_size(t_fillit *fillit, t_tetris *tetri)
{
	int size;

	size = fillit->size;

	while (size <= 26 && recursive(fillit, tetri) == 0)
		size++;
	if (recursive(fillit, tetri) == 1)
		return (1);
	return (0);
}
