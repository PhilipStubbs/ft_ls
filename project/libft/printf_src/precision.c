/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 16:59:51 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/16 09:46:56 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*specialprecision(t_format *format, char **str)
{
	char	*tmp;
	char	*bigprec;
	int		len;
	int		isneg;

	len = ft_strlen(*str);
	isneg = 0;
	if (len < format->precsize)
	{
		if (*str[0] == '-')
		{
			isneg = 1;
			*str[0] = '0';
		}
		len = format->precsize - len;
		bigprec = (char*)ft_memalloc(sizeof(char) * (len + isneg) + 1);
		ft_memset(bigprec, '0', (len + isneg));
		tmp = ft_strjoin(bigprec, *str);
		free(bigprec);
	}
	else
		tmp = ft_strdup(*str);
	if (isneg == 1)
		tmp[0] = '-';
	return (tmp);
}

char	*precision(t_format *format, char **str)
{
	char	*tmp;

	if (format->c != 'c' && format->c != 'C' && format->c != 's' &&
	format->c != 'S')
		tmp = specialprecision(format, str);
	else
		tmp = ft_strsub(*str, 0, format->precsize);
	free(*str);
	return (tmp);
}
