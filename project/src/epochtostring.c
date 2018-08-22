/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epochtostring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 08:12:57 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/22 13:50:28 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*epochtostring(long long epoch)
{
	char		*ret;
	char		*tmp;
	int			len;
	time_t		c;

	c = (unsigned long long)epoch;
	ret = ctime(&c);
	len = ft_strlen(ret);
	tmp = ft_strsub(ret,0, (size_t)len -1);
	return (tmp);
}
