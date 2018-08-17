/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lengthmod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 15:09:39 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/14 12:58:26 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*lengthmoddig(t_format *format, long long num)
{
	char	*ret;

	if (format->ll == 1 || format->c == 'D')
		ret = ft_lltoa((long long int)num);
	else if (format->hh == 1)
		ret = ft_lltoa((signed char)num);
	else if (format->h == 1)
		ret = ft_lltoa((short int)num);
	else if (format->l == 1)
		ret = ft_lltoa((long int)num);
	else if (format->j == 1)
		ret = ft_lltoa((intmax_t)num);
	else if (format->z == 1)
		ret = ft_lltoa((size_t)num);
	else
		ret = ft_itoa(num);
	return (ret);
}
