/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overflowfunc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 09:08:49 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/16 11:57:07 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		istherezero(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0')
			return (1);
		i++;
	}
	return (0);
}

int		wstrsize(wchar_t *tmp)
{
	int		len;

	len = 0;
	while (tmp[len])
		len++;
	return (len);
}

int		findwild(char *str, int i)
{
	i++;
	if (str[i] == '\0')
		return (i);
	while (str[i])
	{
		if (str[i] == '*')
			return (i);
		i++;
	}
	return (i);
}

int		istherespace(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int		*populatehold(va_list args, t_format *format)
{
	int	i;
	int	nbr;
	int	*hold;

	nbr = 0;
	hold = (int*)ft_memalloc(sizeof(int) * format->wild + 1);
	while (nbr < format->wild)
	{
		i = va_arg(args, int);
		hold[nbr] = i;
		nbr++;
	}
	return (hold);
}
