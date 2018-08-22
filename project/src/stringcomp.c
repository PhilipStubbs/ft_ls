/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringcomp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 17:24:45 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/22 17:26:18 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		stringcomp(char *str1, char *str2)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	if (str1[0] == '.' && str1[1] == '.' && str2[0] == '.' && str2[1] == '\0')
		return (1);
	i = ft_strcmp(str1, str2);
	x = ft_strcmp(str2, str1);
	if (i > x)
		return (1);
	else
		return (0);
}
