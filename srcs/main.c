/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 12:15:21 by cchameyr          #+#    #+#             */
/*   Updated: 2017/01/19 13:32:57 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

static int		get_tetriminos(t_fillit *fillit, char *path)
{
	char	*str;
	int		fd;
	int		i;

	if ((fd = open(path, O_RDONLY)) == -1)
		return (_ERROR_);
	while (get_next_line(fd, &str))
	{



	}
	return (_SUCCESS_);
}

int				main(int argc, char **argv)
{
	t_fillit	f;

	if (argc != 2)
		ft_putstr("usage :\t./fillit [-V --Visual] [source_file].fillit\n");
	else
	{
		if (get_tetriminos(&f, argv[1]) == _ERROR_)
			ft_putstr("Error\n");
	}

	(void)f;
	(void)argc;
	(void)argv;
	return (0);
}
