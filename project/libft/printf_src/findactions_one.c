/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findactions_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 10:26:52 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/16 10:27:05 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		findstringaction(t_printf *node, va_list args, t_format *format)
{
	int	i;

	i = findstring(node, args, format);
	free(format);
	return (i);
}

int		findwstraction(t_printf *node, va_list args, t_format *format)
{
	int	i;

	i = findwstr(node, args, format);
	free(format);
	return (i);
}

int		findwcharaction(t_printf *node, va_list args, t_format *format)
{
	int	i;

	i = findwchar(node, args, format);
	free(format);
	return (i);
}

int		finddigitaction(t_printf *node, va_list args, t_format *format)
{
	int	i;

	i = finddigit(node, args, format);
	free(format);
	return (i);
}

int		findcharaction(t_printf *node, va_list args, t_format *format)
{
	findchar(node, args, format);
	free(format);
	return (1);
}
