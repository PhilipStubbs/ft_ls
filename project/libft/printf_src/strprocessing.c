/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 10:29:15 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/16 11:57:38 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		justpercentaction(t_printf *node, t_format *format, int l)
{
	int	i;

	i = justpercent(node, format);
	free(format);
	return (i + l + 1);
}

int		handlenonvalidaction(t_printf *node, t_format *format, int l, int i)
{
	int	x;

	if (node->raw[i + l] == '%')
		return (justpercentaction(node, format, l));
	x = handlenonvalid(node, format);
	free(format);
	return (x);
}

int		flagchecker(t_printf *node, char *str, va_list args, int i)
{
	t_format	*format;
	int			l;

	format = cleanformat();
	l = findspecifier(str, i, format);
	if (str[i + l] == 's')
		return (findstringaction(node, args, format));
	else if (str[i + l] == 'S')
		return (findwstraction(node, args, format));
	else if (str[i + l] == 'C')
		return (findwcharaction(node, args, format));
	else if (str[i + l] == 'd' || str[i + l] == 'D' || str[i + l] == 'i')
		return (finddigitaction(node, args, format));
	else if (str[i + l] == 'c')
		return (findcharaction(node, args, format));
	else if (str[i + l] == 'x' || str[i + l] == 'X')
		return (findhexaction(node, args, format, str[i + l]));
	else if (str[i + l] == 'o' || str[i + l] == 'O')
		return (findoctaction(node, args, format));
	else if (str[i + l] == 'p')
		return (findpointeraction(node, args, format));
	else if (str[i + l] == 'U' || str[i + l] == 'u')
		return (findunsdigitaction(node, args, format));
	return (handlenonvalidaction(node, format, l, i));
}

int		movei(char *str, int i)
{
	int l;

	l = findspecifier(str, i, NULL);
	if (str[i + l] == '%')
		return (i + l + 1);
	if (isvaildflag(str, i + l) == 0)
		return (i + l + 1);
	return (i + l + 1);
}

int		strprocessing(t_printf *node, char *str, va_list args)
{
	int		i;

	i = 0;
	node->output = (char*)ft_memalloc(sizeof(char) * node->size + 1);
	while (str[i])
	{
		if (str[i] != '%')
		{
			node->output = dynamicchar(&(node)->output, str[i]);
		}
		if (str[i] == '%')
		{
			node->l += flagchecker(node, str, args, i);
			i = movei(str, i);
		}
		else
		{
			node->l++;
			i++;
		}
	}
	return (0);
}
