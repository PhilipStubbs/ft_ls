/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findactions_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 10:29:32 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/16 10:29:40 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		findhexaction(t_printf *node, va_list args, t_format *format, char c)
{
	int	i;

	i = findhex(node, args, c, format);
	free(format);
	return (i);
}

int		findoctaction(t_printf *node, va_list args, t_format *format)
{
	int	i;

	i = findoct(node, args, format);
	free(format);
	return (i);
}

int		findpointeraction(t_printf *node, va_list args, t_format *format)
{
	int	i;

	i = findpointer(node, args, format);
	free(format);
	return (i);
}

int		findunsdigitaction(t_printf *node, va_list args, t_format *format)
{
	int	i;

	i = findundigit(node, args, format);
	free(format);
	return (i);
}
