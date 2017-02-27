/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:33:44 by cchameyr          #+#    #+#             */
/*   Updated: 2017/02/27 13:24:26 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

int		return_false(t_fillit *f)
{
	ft_memdel((void **)&f);
	return (_ERROR_);
}

int		return_true(t_fillit *f)
{
	ft_memdel((void **)&f);
	return (_SUCCESS_);
}

int		return_display(t_fillit *f)
{
	display_field(f);
	ft_memdel((void **)&f);
	return (_SUCCESS_);
}
