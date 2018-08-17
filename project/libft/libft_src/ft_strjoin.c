/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 08:41:56 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/03 18:47:20 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *pre, char const *suf)
{
	char *ret;

	if (!pre || !suf)
		return (NULL);
	ret = ft_strnew(ft_strlen(pre) + ft_strlen(suf));
	if (!ret)
		return (NULL);
	ret = ft_strcpy(ret, (char *)pre);
	ft_strcat(ret, (char *)suf);
	return (ret);
}
