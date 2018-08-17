/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 07:45:31 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/02 13:03:35 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmerge(char *s1, char *s2)
{
	int		len;
	int		i;
	int		x;
	char	*ret;

	len = ft_strlen(s1) + ft_strlen(s2);
	ret = (char*)ft_memalloc(sizeof(char) * len + 2);
	i = 0;
	x = 0;
	while (s1[x])
	{
		ret[i++] = s1[x++];
	}
	ret[i] = ' ';
	i++;
	while (*s2)
	{
		ret[i++] = *s2++;
	}
	ret[i] = '\0';
	return (ret);
}
