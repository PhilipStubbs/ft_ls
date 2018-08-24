/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:27:09 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/24 15:42:18 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	destroy(int error, t_ls *node)
{
	(void)error;
	if (node->loc)
		freedouble(node->loc, ft_doublesize(node->loc));
	free(node);
}

int		main(int arc, char **arv)
{
	t_ls	*node;
	int		error;

	node = standardisedinitialised();
	error = 0;
	if (arc > 1)
		error = validflags(node, arv + 1);
	if (error >= 0 && node->loc == NULL)
	{
		node->dflt = 1;
		node->loc = (char**)ft_memalloc(sizeof(char) * 2);
		node->loc[0] = ft_strdup(".");
		node->loc[1] = NULL;
	}
	if (error >= 0)
		ft_ls(node);
	destroy(error, node);
	return (1);
}
