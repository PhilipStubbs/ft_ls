/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standardisedinitialised.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 08:18:09 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/23 14:17:55 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls	*standardisedinitialised(void)
{
	t_ls	*ret;

	ret = (t_ls*)ft_memalloc(sizeof(t_ls));
	ret->dir = NULL;
	ret->l = 0;
	ret->recv = 0;
	ret->a = 0;
	ret->r = 0;
	ret->t = 0;
	ret->g = 0;
	ret->loc = NULL;
	return (ret);
}
