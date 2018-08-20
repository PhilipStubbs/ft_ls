/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:27:09 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/20 10:21:35 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		validflags(t_ls *node, char **arv)
{
	int	l;
	int	ret;

	l = 0;
	ret = 1;
	while (arv[l])
	{
		if (arv[l][0] != '-')
			ret = -1;
		if (arv[l][1] == 'l')
			node->l == 1;
		else if (arv[l][1] == 'a')
			node->a == 1;
		else if (arv[l][1] == 'r')
			node->r == 1;
		else if (arv[l][1] == 't')
			node->t == 1;
		else if (arv[l][1] == 'g')
			node->g == 1;
		else if (arv[l][1] == 'R')
			node->recv == 1;
		else
			ret = -2;
	}
	return (ret);
}
// (!ft_strchr("srps", *cmd))
	// ret->l = 0;
	// ret->recv = 0;
	// ret->a = 0;
	// ret->r = 0;
	// ret->t = 0;
	// ret->g = 0;

int	main(int arc, char **arv)
{
	t_ls *node;
	int	error;

	node = standardisedinitialised();
	if (arc > 1)
		error = validflags(node, arv +1);
	if (error == -1)
		destroy(error, node)
	return (1);
}