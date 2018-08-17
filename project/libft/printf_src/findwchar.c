/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findwchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 16:47:12 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/16 12:10:47 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

wchar_t	findwcharbody(t_printf *node, va_list args, t_format *format)
{
	wchar_t	tmp;

	if (format->wild > 0)
		wildcard(node, format, args);
	tmp = va_arg(args, wchar_t);
	return (tmp);
}

int		findwchar(t_printf *node, va_list args, t_format *format)
{
	int		len;
	char	*ret;
	char	*tmpstr;
	wchar_t	tmp;

	tmp = findwcharbody(node, args, format);
	tmpstr = wcharfinder(format, tmp);
	if (tmpstr == NULL || tmp == 0)
	{
		free(tmpstr);
		tmpstr = ft_strdup("{\\0}");
		node->output = dynamicstring(&node->output, tmpstr);
		free(tmpstr);
		node->lenmod += 3;
		return (2);
	}
	free(tmpstr);
	ret = wcharfinder(format, tmp);
	if ((format->spacpad == 1 || format->zeropad == 1))
		tmpstr = createpadding(&tmpstr, format);
	len = ft_strlen(ret);
	node->output = dynamicstring(&node->output, ret);
	free(ret);
	return (len);
}
