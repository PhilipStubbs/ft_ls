/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paddingsupportfunc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 18:38:29 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/15 18:38:55 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*specialpaddingfordigit(t_format *format, int len, char c, char **str)
{
	char	*amstr;
	char	*tmp;

	if ((*str[0] == '-' && format->minus == 0 && format->prec == 0) ||
	(*str[0] == '-' && format->spacpad == 0 && format->zeropad == 1 &&
	format->prec == 1))
	{
		tmp = ft_strdup("-");
		*str[0] = '0';
	}
	else if ((*str[0] != '-' && format->spacpad == 1 && format->zeropad == 1) ||
	format->prec == 1)
		tmp = ft_strdup(" ");
	else
		tmp = ft_strdup("0");
	amstr = ft_strnew(format->padsize - len - 1);
	ft_memset(amstr, c, format->padsize - len - 1);
	tmp = dynamicstring(&tmp, amstr);
	free(amstr);
	amstr = ft_strdup(tmp);
	free(tmp);
	return (amstr);
}
