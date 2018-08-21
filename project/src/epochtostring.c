/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epochtostring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 08:12:57 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/21 15:35:32 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*epochtostring(long long epoch)
{
	char		*ret;
	char		*tmp;
	struct tm	files;

	tmp = ft_lltoa(epoch);
	ret = ft_strnew(1024);
	ft_memset(&files, 0, sizeof(struct tm));
	strptime(tmp, "%s", &files);
	strftime(ret, 1024, "%b %d %H:%M %Y", &files);
	// free(files);
	free(tmp);
	return (tmp);

	// return (ret);
}
