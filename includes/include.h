/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 12:14:48 by cchameyr          #+#    #+#             */
/*   Updated: 2017/01/25 15:18:02 by fgallois         ###   ########.fr       */
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
	struct s_tetris		*next;
}				t_tetris;

typedef struct	s_fillit
{
	char		array[26][26];
	int			size;
	t_tetris	*tetri;
}				t_fillit;

int		get_tetriminos(t_fillit *f, char *path);

void	display_list(t_tetris *list);

void	display_array(char array[26][26]);

int		check_tetriminos(t_tetris *tetri);

void	init_square(t_fillit *f);

#endif
