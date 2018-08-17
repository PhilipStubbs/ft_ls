/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basicchecker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 12:28:14 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/15 19:00:03 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		isnormalflag(char *str, int i)
{
	char	c;

	c = str[i];
	if (ft_isdigit(c) == 1)
		return (1);
	else if (c == 'h' || c == 'l' || c == 'j' || c == 'e' || c == 't' ||
	c == 'z' || c == '-' || c == ' ' || c == '#' || c == '.' ||
	c == '+' || c == '*')
		return (1);
	else if (isvaildflag(str, i) == 1 && isvaildflag(str, i - 1) == 1)
		return (0);
	return (0);
}

int		isvaildflag(char *str, int i)
{
	char	c;

	c = str[i];
	if (c == 's' || c == 'S' || c == 'd' || c == 'S' || c == 'p' ||
	c == 'D' || c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' ||
	c == 'x' || c == 'X' || c == 'c' || c == 'C')
		return (1);
	return (0);
}

int		spacechecker(char *str, int l)
{
	char	c;

	c = str[l - 1];
	if (str[l] == ' ' && c != 's' && c != 'd' && c != 'S' && c != 'p' &&
	c != 'D' && c != 'i' && c != 'o' && c != 'O' && c != 'u' && c != 'U' &&
	c != 'x' && c != 'X' && c != 'c' && c != 'C')
	{
		return (1);
	}
	return (0);
}

int		creatspecialpaddingswitch(t_format *format)
{
	if ((((format->spacpad == 1 && format->zeropad == 1) ||
	(format->zeropad == 1 && format->spacpad == 0)) && (format->c == 'd' ||
	format->c == 'D' || format->c == 'i')) && format->minus == 0 &&
	format->wild == 0)
		return (1);
	return (0);
}

int		hexhashswitch(t_format *format)
{
	if ((format->hash == 1 && format->zeropad == 0 && format->spacpad == 1) ||
	(format->prec == 1 && format->hash == 1 && format->zeropad == 0 &&
	format->spacpad == 0) || (format->prec == 0 && format->hash == 1 &&
	format->zeropad == 0 && format->spacpad == 0))
		return (1);
	return (0);
}
