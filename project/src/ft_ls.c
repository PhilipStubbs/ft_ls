/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 11:41:02 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/20 14:01:09 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls(t_ls *node)
{
	// t_statinfo *tmp;

	// tmp = node->hold;
	savecurdir(node, ".");
	// tmp = ;
	// write(1,"X\n",2); 
	// ft_printf("here[%s]\n", tmp->name);
	// ft_printf("hold[%s]\n", node->hold->next->name);
	while (node->hold != NULL)
	{
		// write(1,"X\n",2); 
		ft_printf("hold[%s]\n",  epochtostring(node->hold->stinfo.st_mtimespec.tv_sec));
		node->hold = node->hold->next;
	}
}