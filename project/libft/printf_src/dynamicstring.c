/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamicstring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 09:52:29 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/16 12:12:02 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*dynamicstring(char **ori, char *add)
{
	char	*tmp;
	char	*ret;

	tmp = ft_strdup(*ori);
	free(*ori);
	ret = ft_strjoin(tmp, add);
	free(tmp);
	return (ret);
}

char	*dynamicchar(char **ori, char add)
{
	char	*tmp;
	char	*ret;
	char	*stradd;

	stradd = (char*)ft_memalloc(sizeof(char) * 3);
	stradd[0] = add;
	stradd[1] = '\0';
	tmp = ft_strdup(*ori);
	free(*ori);
	ret = ft_strjoin(tmp, stradd);
	free(tmp);
	free(stradd);
	return (ret);
}
