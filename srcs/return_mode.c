/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:33:44 by cchameyr          #+#    #+#             */
/*   Updated: 2017/02/27 11:49:44 by cchameyr         ###   ########.fr       */
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
