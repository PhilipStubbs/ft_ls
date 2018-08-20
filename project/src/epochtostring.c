/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epochtostring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 08:12:57 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/20 08:13:33 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*epochtostring(long long epoch)
{
	char		*ret;
	char		*tmp;
	struct tm	hold;

	tmp = ft_lltoa(epoch);
	ret = ft_strnew(1024);
	ft_memset(&hold, 0, sizeof(struct tm));
	strptime(tmp, "%s", &hold);
	strftime(ret, 1024, "%b %d %H:%M %Y", &hold);
	// free(hold);
	free(tmp);
	return (ret);
}
