/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 12:14:48 by cchameyr          #+#    #+#             */
/*   Updated: 2017/01/19 13:23:59 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _INCLUDE_H
# define _INCLUDE_H

# include "../libft/libft.h"
# include <fcntl.h>

typedef struct	s_tetris
{
	char				*form[4];
	struct s_tetris		*next;
}				t_tetris;

typedef struct	s_fillit
{
	t_tetris	*tetri;
}				t_fillit;



#endif
