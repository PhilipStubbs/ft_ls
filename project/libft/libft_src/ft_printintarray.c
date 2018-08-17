/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printintarray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 10:15:53 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/02 13:03:17 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_printintarray(int *list, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putnbr(list[i++]);
		ft_putstr(" | ");
	}
	ft_putchar('\n');
}
