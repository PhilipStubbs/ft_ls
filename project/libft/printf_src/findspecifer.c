/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findspecifer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 09:32:55 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/16 11:58:32 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	lengthspec(char *str, int i, t_format *format)
{
	if (str[i] == '-' && format != NULL)
		format->minus = 1;
	if (str[i] == '+' && format != NULL)
		format->plus = 1;
	if (format != NULL && (str[i] == 'h' && str[i + 1] == 'h'))
		format->hh = 1;
	if (format != NULL && (str[i] == 'h' && format->hh == 0))
		format->h = 1;
	if (format != NULL && (str[i] == 'l' && str[i + 1] == 'l'))
		format->ll = 1;
	if (format != NULL && (str[i] == 'l' && format->ll == 0))
		format->l = 1;
	if (format != NULL && (str[i] == 'j'))
		format->j = 1;
	if (format != NULL && (str[i] == 'z'))
		format->z = 1;
	if (format != NULL && (str[i] == '*'))
		format->wild++;
	if (format != NULL && (format->hh == 1 || format->h == 1 || format->ll == 1
	|| format->l == 1 || format->j == 1 || format->z == 1))
	{
		format->lenmod = 1;
	}
}

void	normalspecbody_one(char *str, int i, t_format *format)
{
	format->zeropad = 1;
	if (format->padsize == 0)
	{
		if (str[i + 1] == '-' || str[i + 1] == '+')
			format->padsize = ft_atoi(str + i + 2);
		else
			format->padsize = ft_atoi(str + i);
	}
}

void	normalspecbody_two(char *str, int i, t_format *format)
{
	int		x;

	x = 0;
	format->spacpad = 1;
	if (ft_isdigit(str[i + x]) == 0)
	{
		while (ft_isdigit(str[i + x]) == 0)
			x++;
		format->padsize = ft_atoi(str + i + x);
	}
	else
		format->padsize = ft_atoi(str + i);
}

void	normalspec(char *str, int i, t_format *format)
{
	if (str[i] == '#' && format != NULL)
		format->hash = 1;
	if (format != NULL && (str[i] == ' ' && format->spacpad == 0))
	{
		if (ft_isdigit(str[i + 1]) == 1 && str[i + 1] != 0)
			format->padsize = ft_atoi(str + i);
		format->spacpad = 1;
	}
	if (format != NULL && (str[i] == '0' && format->zeropad == 0 &&
	ft_isdigit(str[i - 1]) == 0))
		normalspecbody_one(str, i, format);
	if (format != NULL && (ft_isdigit(str[i]) == 1 && format->zeropad == 0 &&
	format->spacpad == 0 && str[i - 1] != '.'))
	{
		normalspecbody_two(str, i, format);
	}
	if (format != NULL && (str[i] == '.'))
	{
		format->prec = 1;
		format->precsize = ft_atoi(str + i + 1);
	}
}

int		findspecifier(char *str, int i, t_format *format)
{
	int	count;

	count = 1;
	i++;
	if (format != NULL)
		format->start = i;
	while (isnormalflag(str, i) == 1)
	{
		normalspec(str, i, format);
		lengthspec(str, i, format);
		i++;
		count++;
		if (isvaildflag(str, i) == 1 || str[i] == '%')
		{
			break ;
		}
	}
	if (format != NULL)
	{
		if (isvaildflag(str, i) == 0)
			format->badflag = 1;
		format->end = i;
		format->c = str[i];
	}
	return (count);
}
