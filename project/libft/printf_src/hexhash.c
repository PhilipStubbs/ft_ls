/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexhash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 18:44:26 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/15 18:56:01 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	hexhashcap(t_format *format, char *check, char **tmpstr2, char **tmpstr)
{
	if (format->zeropad == 1 && check[0] == '0' && check[1] == '0' &&
	format->prec == 0)
	{
		*tmpstr2 = ft_strdup(*tmpstr);
		*tmpstr2[0] = '0';
		*tmpstr2[1] = 'X';
	}
	else if (format->zeropad == 1 && check[0] == '0' && check[1] != '0' &&
	format->prec == 0)
	{
		check[0] = 'X';
		*tmpstr2 = ft_strjoin("0", check);
	}
	else
		*tmpstr2 = ft_strjoin("0X", *tmpstr);
}

char	*hexhashbody(char **tmpstr)
{
	char	*tmpstr2;

	tmpstr2 = ft_strdup(*tmpstr);
	tmpstr2[0] = '0';
	tmpstr2[1] = 'x';
	return (tmpstr2);
}

char	*hexhash(char **tmpstr, char cap, t_format *format)
{
	char	*tmpstr2;
	char	*check;

	check = ft_strdup(*tmpstr);
	if (cap == 'X')
		hexhashcap(format, check, &tmpstr2, tmpstr);
	else
	{
		if (format->zeropad == 1 && check[0] == '0' && check[1] == '0' &&
		format->prec == 0)
			tmpstr2 = hexhashbody(tmpstr);
		else if (format->zeropad == 1 && check[0] == '0' && check[1] != '0' &&
		format->prec == 0)
		{
			check[0] = 'x';
			tmpstr2 = ft_strjoin("0", check);
		}
		else
			tmpstr2 = ft_strjoin("0x", *tmpstr);
	}
	free(*tmpstr);
	*tmpstr = ft_strdup(tmpstr2);
	free(tmpstr2);
	free(check);
	return (*tmpstr);
}
