/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 13:16:02 by cchameyr          #+#    #+#             */
/*   Updated: 2017/01/25 15:36:16 by fgallois         ###   ########.fr       */
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

	f->size = minsize(f->tetri);
	i = -1;
	while (++i < 26)
		ft_memset(f->array[i], '.', 26);
}
