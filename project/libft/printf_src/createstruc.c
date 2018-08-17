/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createstruc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 09:53:15 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/16 11:47:45 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_printf	*createstruc(void)
{
	t_printf	*ret;

	ret = (t_printf*)ft_memalloc(sizeof(t_printf));
	ret->output = NULL;
	ret->size = 0;
	ret->padding = 0;
	ret->l = 0;
	ret->lenmod = 0;
	ret->isspaceswitch = 0;
	return (ret);
}

t_format	*cleanformat(void)
{
	t_format	*ret;

	ret = (t_format*)ft_memalloc(sizeof(t_format));
	ret->c = 0;
	ret->start = 0;
	ret->end = 0;
	ret->spacpad = 0;
	ret->zeropad = 0;
	ret->padsize = 0;
	ret->hash = 0;
	ret->minus = 0;
	ret->plus = 0;
	ret->prec = 0;
	ret->precsize = 0;
	ret->badflag = 0;
	ret->lenmod = 0;
	ret->hh = 0;
	ret->h = 0;
	ret->l = 0;
	ret->ll = 0;
	ret->j = 0;
	ret->z = 0;
	ret->wild = 0;
	ret->wchar = 0;
	return (ret);
}
