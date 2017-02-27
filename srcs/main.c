/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 13:07:52 by cchameyr          #+#    #+#             */
/*   Updated: 2017/02/27 11:58:58 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

int				main(int argc, char **argv)
{
	t_fillit	f;
	t_fillit	*e;
	int			ret;

	if (argc != 2)
		ft_putstr("usage :\t./fillit [source_file]\n");
	else
	{
		f.tetri = NULL;
		if (get_tetriminos(&f, argv[1]) == _ERROR_)
			display_error();
		else if (check_tetriminos(f.tetri) == _ERROR_)
			display_error();
		init_square(&f);
		ret = 0;
		while (ret == 0)
		{
			e = (t_fillit *)ft_memalloc(sizeof(t_fillit));
			e = ft_memcpy(e, &f, sizeof(t_fillit));
			ret = recursive(e, e->tetri);
			f.size++;
		}
	}
	return (0);
}
