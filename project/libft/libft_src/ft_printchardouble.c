/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchardouble.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 12:56:54 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/10 08:17:55 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_printchardouble(char **list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		ft_putendl(list[i]);
		i++;
	}
}
