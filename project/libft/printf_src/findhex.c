/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findhex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 13:30:43 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/15 19:10:46 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*lengthmodhex(t_format *format, uintmax_t num, int cap)
{
	char	*ret;

	if (format->hh == 1)
		ret = ft_itoa_base((unsigned char)num, 16, cap);
	else if (format->h == 1)
		ret = ft_itoa_base((unsigned short int)num, 16, cap);
	else if (format->l == 1)
		ret = ft_itoa_base((unsigned long int)num, 16, cap);
	else if (format->ll == 1)
		ret = ft_itoa_base((unsigned long long int)num, 16, cap);
	else if (format->j == 1)
		ret = ft_itoa_base((uintmax_t)num, 16, cap);
	else if (format->z == 1)
		ret = ft_itoa_base((size_t)num, 16, cap);
	else
		ret = ft_itoa_base(num, 16, cap);
	return (ret);
}

char	*findhexbody_one(t_format *format, int d, uintmax_t tmp)
{
	char	*tmpstr;

	if (format->lenmod == 1)
		tmpstr = lengthmodhex(format, tmp, d);
	else
		tmpstr = ft_itoa_base((unsigned int)tmp, 16, d);
	return (tmpstr);
}

void	findhexbody_two(t_format *fo, char **tstr, char cap, uintmax_t tmp)
{
	if (tmp == 1 && ft_strcmp("0", *tstr) == 0)
		fo->hash = 0;
	if (fo->prec == 1)
		*tstr = precision(fo, tstr);
	if (hexhashswitch(fo) == 1)
		*tstr = hexhash(tstr, cap, fo);
	if ((fo->spacpad == 1 || fo->zeropad == 1))
		*tstr = createpadding(tstr, fo);
	if (fo->hash == 1 && fo->zeropad == 1 && fo->prec == 0)
		*tstr = hexhash(tstr, cap, fo);
}

int		findhex(t_printf *node, va_list args, char cap, t_format *format)
{
	uintmax_t	tmp;
	char		*tmpstr;

	if (format->wild > 0)
		wildcard(node, format, args);
	tmp = va_arg(args, uintmax_t);
	if (tmp == 0 && format->prec == 1 && format->precsize == 0 &&
	format->padsize == 0)
		return (0);
	if (tmp == 0 && format->prec == 1 && format->precsize == 0 &&
	format->padsize != 0)
		tmpstr = ft_strdup(" ");
	else if (cap == 'x')
		tmpstr = findhexbody_one(format, 0, tmp);
	else
		tmpstr = findhexbody_one(format, 1, tmp);
	tmp = ft_strlen(tmpstr);
	findhexbody_two(format, &tmpstr, cap, tmp);
	node->output = dynamicstring(&(node)->output, tmpstr);
	tmp = ft_strlen(tmpstr);
	free(tmpstr);
	return (tmp);
}
