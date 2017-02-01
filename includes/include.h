/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 12:14:48 by cchameyr          #+#    #+#             */
/*   Updated: 2017/02/01 15:56:57 by cchameyr         ###   ########.fr       */
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
	int					pos[2];
	int					checked;
	struct s_tetris		*next;
}				t_tetris;

typedef struct	s_fillit
{
	char		square[26][26];
	int			size;
	int			curr_x;
	int			curr_y;
	t_tetris	*tetri;
}				t_fillit;

int			get_tetriminos(t_fillit *f, char *path);

void		display_error(void);

void		display_list(t_tetris *list);

void		display_square(char square[26][26]);

int			display_field(t_fillit *fillit);

void		display_coord(t_tetris *list);

int			check_tetriminos(t_tetris *tetri);

void		init_square(t_fillit *f);

int			match_in_square(t_fillit *fillit, t_tetris *tetri, int x, int y);

int			recursive(t_fillit fillit, t_tetris *tetri);

int			same_tetrim(t_tetris *tetri1, t_tetris *tetri2);

t_fillit	fill(t_fillit fillit, t_tetris *tetri, int x, int y);

#endif
