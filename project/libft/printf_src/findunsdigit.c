/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findunsdigit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 08:03:21 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/15 19:17:40 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*lengthmodunsigned(t_format *format, long long num)
{
	char	*ret;

	if (format->l == 1 || format->c == 'U')
		ret = ft_ulltoa((unsigned long int)num);
	else if (format->hh == 1)
		ret = ft_ulltoa((unsigned char)num);
	else if (format->h == 1 && format->c != 'U')
		ret = ft_ulltoa((unsigned short int)num);
	else if (format->ll == 1)
		ret = ft_ulltoa((unsigned long long int)num);
	else if (format->j == 1)
		ret = ft_ulltoa((uintmax_t)num);
	else if (format->z == 1)
		ret = ft_ulltoa((size_t)num);
	else if (format->c == 'U')
		ret = ft_ulltoa((unsigned long int)num);
	else
		ret = ft_ulltoa(num);
	return (ret);
}

int		findundigit(t_printf *node, va_list args, t_format *format)
{
	unsigned long long	tmp;
	int					len;
	char				*ret;

	if (format->wild > 0)
		wildcard(node, format, args);
	tmp = va_arg(args, unsigned long long);
	if (tmp == 0 && format->prec == 1 && format->precsize == 0 &&
	format->padsize == 0)
		return (0);
	if (format->lenmod == 1 || format->c == 'U')
		ret = lengthmodunsigned(format, (unsigned long long)tmp);
	else
		ret = ft_ulltoa((unsigned int)tmp);
	if (format->prec == 1)
		ret = precision(format, &ret);
	if (format->spacpad == 1 || format->zeropad == 1)
		ret = createpadding(&ret, format);
	node->output = dynamicstring(&(node)->output, ret);
	len = ft_strlen(ret);
	free(ret);
	return (len);
}
