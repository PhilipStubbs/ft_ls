/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:27:09 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/23 14:31:14 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


void	destroy(int error, t_ls *node)
{
	
	(void)error;
	// if (node->dir)
	// 	free(node->dir);
	free(node->loc);
	free(node);

}

int		main(int arc, char **arv)
{
	t_ls	*node;
	int		error;

	node = standardisedinitialised();
	error = 0;
	if (arc > 1)
		error = validflags(node, arv +1);
	if (error >= 0 && node->loc == NULL)
		node->loc = ft_strdup(".");
	
	// ft_printf("l=[%d] a=[%d] r=[%d] t=[%d] g=[%d] R=[%d] g=[%d]\n", node->l,node->a,node->r,node->t,node->g,node->recv,node->g);
	if (error >= 0)
		ft_ls(node);
	destroy(error, node);
	return (1);
}
