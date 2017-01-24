/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 13:16:02 by cchameyr          #+#    #+#             */
/*   Updated: 2017/01/24 13:40:44 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/include.h"

static int		minsize(t_tetris *t)
{
	int		total_sharp;
	int		size;

	while (t)
		t = t->next;
	total_sharp = t->index * 4;
	size = 2;
	while (size * size < total_sharp)
		size++;
	return (size);
}

void			init_square(t_fillit *f)
{
	f->size = minsize(f->tetri);
}
