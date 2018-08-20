/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validflags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 11:09:38 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/20 11:35:38 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		isvalidflag(t_ls *node, char *arv)
{
	int	len;

	len = ft_strlen(arv);
	if (len > 2 || ft_isspace(arv[1]) == 1 ||
	(ft_isdigit(arv[1]) == 1 && arv[1] != '1'))
		return (-1);
	if (arv[1] == 'l')
		node->l = 1;
	else if (arv[1] == 'a')
		node->a = 1;
	else if (arv[1] == 'r')
		node->r = 1;
	else if (arv[1] == 't')
		node->t = 1;
	else if (arv[1] == 'g')
		node->g = 1;
	else if (arv[1] == 'R')
		node->recv = 1;
	else if (arv[1] == 'G')
		node->g = 1;
	else if (len == 1 || arv[0] != '-')
		return (-2);
	return (1);
}

int		validflags(t_ls *node, char **arv)
{
	int	l;
	int	ret;

	l = 0;
	ret = 1;
	while (arv[l])
	{
		ret = isvalidflag(node, arv[l]);
		if (ret < 1)
		{
			if (ret == -2)
				ft_printf("{RED}ft_ls: [%s]: No such file or directory",
				arv[l]);
			else
			{
				ft_printf("{RED}ft_ls: illegal option [%s]\n");
				ft_printf("{RED}usage:ft_ls ");
				ft_printf("{RED}[-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] ");
				ft_printf("{RED}[file ...]\n");
			}
			return (ret);
		}
		l++;
	}
	return (ret);
}
