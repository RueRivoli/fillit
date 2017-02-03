/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 12:24:23 by cchameyr          #+#    #+#             */
/*   Updated: 2017/02/03 13:12:46 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

void	display_error(void)
{
	ft_putstr("error\n");
	exit(0);
}

void	display_list(t_tetris *list)
{
	int i;
	int j;

	j = 0;
	while (list)
	{
		while (j < 4)
		{
			i = 0;
			while (i < 4)
				ft_putchar(list->form[j][i++]);
			write(1, "\n", 1);
			j++;
		}
		j = 0;
		write(1, "\n", 1);
		list = list->next;
	}
}

void	display_square(char square[26][26])
{
	int i;
	int j;

	i = 0;
	while (i < 26)
	{
		j = 0;
		while (j < 26)
			ft_putchar(square[i][j++]);
		ft_putchar('\n');
		i++;
	}
}

int		display_field(t_fillit *fillit)
{
	int i;
	int j;

	i = 0;
	while (i < fillit->size)
	{
		j = 0;
		while (j < fillit->size)
			ft_putchar(fillit->square[i][j++]);
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
	sleep(1);
	return (_SUCCESS_);
}

void	display_coord(t_tetris *list)
{
	int i;

	i = 0;
	while (list)
	{
		ft_putstr("Piece numero : ");
		ft_putnbr(list->index);
		ft_putstr("\nCord_x : \t");
		i = 0;
		while (i < 4)
		{
			ft_putnbr(list->coord_x[i++]);
			ft_putchar('\t');
		}
		ft_putstr("\n\n");
		ft_putstr("Cord_y : \t");
		i = 0;
		while (i < 4)
		{
			ft_putnbr(list->coord_y[i++]);
			ft_putchar('\t');
		}
		ft_putstr("\n\n");
		list = list->next;
	}
}
