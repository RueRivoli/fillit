/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 12:24:23 by cchameyr          #+#    #+#             */
/*   Updated: 2017/01/23 17:50:10 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

void	display_list(t_tetris *list)
{
	int i;
	int j;
	
	i = 0;
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

