/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findpointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 17:04:00 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/15 17:18:11 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*findpointerbody(t_format *format, char **tmpstr)
{
	char	*ret;

	format->padsize -= 2;
	ret = ft_strdup(*tmpstr);
	ret = createpadding(&ret, format);
	free(*tmpstr);
	*tmpstr = ft_strdup(ret);
	free(ret);
	ret = ft_strjoin("0x", *tmpstr);
	return (ret);
}

int		findpointerbody_two(t_printf *node, char **ret, char **tmpstr)
{
	int tmp;

	node->output = dynamicstring(&(node)->output, *ret);
	tmp = ft_strlen(*ret);
	free(*tmpstr);
	free(*ret);
	return (tmp);
}

int		findpointer(t_printf *node, va_list args, t_format *format)
{
	unsigned long long	tmp;
	char				*tmpstr;
	char				*ret;

	if (format->wild > 0)
		wildcard(node, format, args);
	tmp = va_arg(args, unsigned long long);
	if (tmp == 0 && format->prec == 1 && format->precsize == 0 &&
	format->padsize == 0 && format->hash == 0)
		tmpstr = ft_strdup("");
	else
		tmpstr = ft_itoa_base(tmp, 16, 0);
	if (format->prec == 1)
		tmpstr = precision(format, &tmpstr);
	if (format->zeropad == 0)
		ret = ft_strjoin("0x", tmpstr);
	if (format->spacpad == 1 || format->zeropad == 1)
	{
		if (format->zeropad == 1)
			ret = findpointerbody(format, &tmpstr);
		else
			ret = createpadding(&ret, format);
	}
	return (findpointerbody_two(node, &ret, &tmpstr));
}
