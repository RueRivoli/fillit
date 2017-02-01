/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 14:24:09 by fgallois          #+#    #+#             */
/*   Updated: 2017/02/01 13:11:59 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"
#include <stdio.h>

int		recursive(t_fillit *fillit, t_tetris *tetri)
{
	int x;
	int y;

	x = 0;
	y = 0;
	//printf("size : %d\n", fillit->size);
	if (tetri == NULL)
		return (1);
	else
	{
		while (x < fillit->size && y < fillit->size)
		{
			//ft_putnbr(match_in_all(fillit, tetri, x, y));
			if (match_in_all(fillit, tetri, x, y))
			{
				int a;
				int b;
				a = tetri->pos[0];
				b = tetri->pos[1];
				fill(fillit, tetri, b, a);
				//ft_putstr("Field :\n");
				//display_field(fillit);
				if (tetri->next == NULL)
				{	//ft_putstr("FIN\n");
				}
				if (recursive(fillit, tetri->next))
				{
					//ft_putstr("chat :\n");
					//display_list(tetri->next);
					return (1);
				}
				else
				{
					empty(fillit, tetri, b, a);
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
