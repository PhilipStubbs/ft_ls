/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:27:09 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/20 11:41:21 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


void	destroy(int error, t_ls *node)
{
	(void)node;
	(void)error;

}

int		main(int arc, char **arv)
{
	t_ls	*node;
	int		error;

	node = standardisedinitialised();
	error = 0;
	if (arc > 1)
		error = validflags(node, arv +1);
	// ft_printf("l=[%d] a=[%d] r=[%d] t=[%d] g=[%d] R=[%d] g=[%d]\n", node->l,node->a,node->r,node->t,node->g,node->recv,node->g);
	if (error == 0)
		ft_ls(node);
	destroy(error, node);
	return (1);
}