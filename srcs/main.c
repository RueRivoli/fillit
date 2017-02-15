/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 13:07:52 by cchameyr          #+#    #+#             */
/*   Updated: 2017/02/15 13:09:18 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"
#include <stdio.h>

int				main(int argc, char **argv)
{
	t_fillit f;

	if (argc != 2)
		ft_putstr("usage :\t./fillit [-V --Visual] [source_file].fillit\n");
	else
	{
		f.tetri = NULL;
		if (get_tetriminos(&f, argv[1]) == _ERROR_)
			display_error();
		else if (check_tetriminos(f.tetri) == _ERROR_)
			display_error();
		init_square(&f);
		while (recursive(f, f.tetri) == 0)
			f.size++;
	}
	return (0);
}
