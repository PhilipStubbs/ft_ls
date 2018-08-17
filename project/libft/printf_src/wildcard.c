/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 18:10:05 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/16 11:56:59 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		checkforcorrectminus(t_format *format, char *str, int *hold, int i)
{
	int nbr;
	int	x;

	nbr = 0;
	x = i;
	x = findwild(str, x);
	while (nbr < format->wild)
	{
		if (hold[nbr] < 0 && str[x - 1] != '.')
		{
			format->minus = 1;
			hold[nbr] *= -1;
		}
		nbr++;
	}
}

void		procressprecsize(t_format *format, int **hold)
{
	if (format->precsize < 0 && format->c == 's')
		format->precsize *= -1;
	if (format->precsize < 0 && format->c != 's')
		format->precsize = 0;
	free(*hold);
}

int			wildcardbody_two(t_format *format, int *hold, int nbr, char c)
{
	if (c == '.')
	{
		format->precsize = hold[nbr];
		nbr++;
	}
	return (nbr);
}

void		wildcardbody_one(t_format *format, t_printf *node, int *hold, int i)
{
	int	nbr;

	nbr = 0;
	while (nbr < format->wild)
	{
		nbr = wildcardbody_two(format, hold, nbr, node->raw[i - 1]);
		if (nbr == format->wild)
			break ;
		if (ft_isdigit(node->raw[i - 1]) == 1 || node->raw[i - 1] == ' ' ||
		ft_isdigit(node->raw[i + 1]) == 1 || ft_isalpha(node->raw[i + 1]) == 1)
		{
			if (node->isspaceswitch == 0 && hold[nbr] == 0)
				format->spacpad = 0;
			if (ft_isdigit(node->raw[i + 1]) == 0)
				format->padsize = hold[nbr];
			nbr++;
		}
		if (format->spacpad == 0 && format->zeropad == 0 &&
		format->padsize != 0)
			format->spacpad = 1;
		i = findwild(node->raw, i);
		if (node->raw[i] == '\0')
			break ;
	}
}

void		wildcard(t_printf *node, t_format *format, va_list args)
{
	int	*hold;
	int	nbr;
	int	i;

	node->isspaceswitch = istherespace(node->raw);
	hold = populatehold(args, format);
	nbr = 0;
	i = format->start;
	checkforcorrectminus(format, node->raw, hold, i);
	wildcardbody_one(format, node, hold, i);
	procressprecsize(format, &hold);
}
