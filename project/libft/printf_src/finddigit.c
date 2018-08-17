/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finddigit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 16:49:54 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/15 16:58:27 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*addplus(t_format *format, char **str)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	if (format->zeropad == 1 && *str[0] == '0')
	{
		tmp3 = ft_strdup(*str);
		tmp3[0] = '+';
		free(*str);
	}
	else
	{
		tmp = ft_strdup("+");
		tmp2 = ft_strdup(*str);
		free(*str);
		tmp3 = ft_strjoin(tmp, tmp2);
		free(tmp);
		free(tmp2);
	}
	return (tmp3);
}

char	*finddigitbody(t_format *format, long long tmp)
{
	char	*ret;

	if (format->lenmod == 1 || format->c == 'D')
		ret = lengthmoddig(format, tmp);
	else
		ret = ft_itoa(tmp);
	if (format->plus == 1 && format->prec == 0 &&
	ret[0] != '-' && format->zeropad == 0)
		ret = addplus(format, &ret);
	if (format->prec == 1)
		ret = precision(format, &ret);
	if (format->plus == 1 && format->prec == 1 &&
	ret[0] != '-' && format->zeropad == 0)
		ret = addplus(format, &ret);
	if (format->spacpad == 1 && format->zeropad == 0 && format->padsize == 0 &&
	(int)tmp >= 0 && format->plus == 0 && format->prec == 0)
		format->padsize = ft_strlen(ret) + 1;
	return (ret);
}

int		finddigit(t_printf *node, va_list args, t_format *format)
{
	long long	tmp;
	int			len;
	char		*ret;

	if (format->wild > 0)
		wildcard(node, format, args);
	tmp = va_arg(args, long long);
	if (tmp == 0 && format->prec == 1 && format->precsize == 0 &&
	format->padsize == 0 && format->wild == 0)
		return (0);
	if (tmp == 0 && format->prec == 1 && format->precsize == 0 &&
	format->padsize != 0 && format->wild == 0)
		ret = ft_strdup(" ");
	else
		ret = finddigitbody(format, tmp);
	if (format->spacpad == 1 || format->zeropad == 1)
		ret = createpadding(&ret, format);
	if (format->plus == 1 && format->zeropad == 1 && tmp >= 0 && ret[0] != '+')
		ret = addplus(format, &ret);
	node->output = dynamicstring(&(node)->output, ret);
	len = ft_strlen(ret);
	free(ret);
	node->padding = -1;
	return (len);
}
