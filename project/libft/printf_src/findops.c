/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 10:48:41 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/15 17:21:34 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		justpercent(t_printf *node, t_format *format)
{
	char	*tmp;
	int		len;

	tmp = ft_strdup("%");
	if (format->zeropad == 1 || format->spacpad == 1)
	{
		tmp = createpadding(&tmp, format);
	}
	node->output = dynamicstring(&(node)->output, tmp);
	len = ft_strlen(tmp);
	free(tmp);
	return (len);
}

int		findstring(t_printf *node, va_list args, t_format *format)
{
	char	*tmp;
	char	*tmp2;
	int		len;

	if (format->l == 1)
		return (findwstr(node, args, format));
	if (format->wild > 0)
		wildcard(node, format, args);
	tmp = va_arg(args, char*);
	if (tmp == NULL)
		tmp2 = ft_strdup("(null)");
	else
		tmp2 = ft_strdup(tmp);
	if (format->prec == 1)
		tmp2 = precision(format, &tmp2);
	if (format->zeropad == 1 || format->spacpad == 1)
		tmp2 = createpadding(&tmp2, format);
	len = ft_strlen(tmp2);
	node->output = dynamicstring(&(node)->output, tmp2);
	free(tmp2);
	return (len);
}

char	*findcharbody(t_format *format, t_printf *node)
{
	char	*ret;

	ret = ft_strdup("{\\0}");
	node->lenmod += 3;
	if (format->padsize > 0)
		format->padsize += 3;
	return (ret);
}

int		findchar(t_printf *node, va_list args, t_format *format)
{
	char	tmp;
	char	*tmpstr;
	int		i;

	i = 0;
	if (format->l == 1)
		return (findwchar(node, args, format));
	if (format->wild > 0)
		wildcard(node, format, args);
	tmp = va_arg(args, int);
	if (tmp == 0)
		tmpstr = findcharbody(format, node);
	else
	{
		tmpstr = ft_strnew(1);
		tmpstr[0] = tmp;
	}
	if (format->spacpad == 1 || format->zeropad == 1)
		tmpstr = createpadding(&tmpstr, format);
	node->output = dynamicstring(&(node)->output, tmpstr);
	i = ft_strlen(tmpstr);
	free(tmpstr);
	return (i);
}
