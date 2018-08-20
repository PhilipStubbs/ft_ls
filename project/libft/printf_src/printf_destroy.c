/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 10:18:28 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/20 10:23:57 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	printf_destroy(t_printf **node)
{
	free((*node)->output);
	free((*node)->raw);
	free(*node);
}
