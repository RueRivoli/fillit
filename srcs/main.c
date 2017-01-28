/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 13:07:52 by cchameyr          #+#    #+#             */
/*   Updated: 2017/01/27 14:22:38 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

int				main(int argc, char **argv)
{
	t_fillit f;

	if (argc != 2)
		ft_putstr("usage :\t./fillit [-V --Visual] [source_file].fillit\n");
	else
	{
		if (get_tetriminos(&f, argv[1]) == _ERROR_)
			display_error();
		else if (check_tetriminos(f.tetri) == _ERROR_)
			display_error();
		else
			ft_putendl("Success");
		init_square(&f);
		//display_list(f.tetri);
			display_coord(f.tetri);
			ft_putchar('\n');
		//display_square(f.square);
	}
	return (0);
}
