/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 12:14:48 by cchameyr          #+#    #+#             */
/*   Updated: 2017/01/26 17:50:55 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _INCLUDE_H
# define _INCLUDE_H

# include "../libft/libft.h"
# include "get_next_line.h"
# include <fcntl.h>

#   include "debug.h"

typedef struct	s_tetris
{
	char				form[4][4];
	int					index;
	int					coord_x[4];
	int					coord_y[4];
	struct s_tetris		*next;
}				t_tetris;

typedef struct	s_fillit
{
	char		square[26][26];
	int			size;
	t_tetris	*tetri;
}				t_fillit;

int		get_tetriminos(t_fillit *f, char *path);

void	display_list(t_tetris *list);

void	display_square(char square[26][26]);

void	display_coord(t_tetris *list);

int		check_tetriminos(t_tetris *tetri);

void	init_square(t_fillit *f);

#endif
