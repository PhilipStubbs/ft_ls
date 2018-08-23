/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validflags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 11:09:38 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/23 14:49:50 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	feedintonode(t_ls *node, char *arv, int i)
{
	if (arv[i] == 'l')
		node->l = 1;
	if (arv[i] == 'a')
		node->a = 1;
	if (arv[i] == 'r')
		node->r = 1;
	if (arv[i] == 't')
		node->t = 1;
	if (arv[i] == 'g')
		node->g = 1;
	if (arv[i] == 'R')
		node->recv = 1;
	if (arv[i] == 'G')
		node->g = 1;
}

int		isvalidflag(t_ls *node, char *arv)
{
	int	len;
	int	dircount;
	int	i;

	i = 0;
	dircount = 0;
	len = ft_strlen(arv);
	if (ft_isspace(arv[1]) == 1 || len == 1)
		return (-1);
	if (arv[0] == '-')
	{
		while (arv[i])
		{
			feedintonode(node, arv, i);
			i++;
		}
	}
	if (arv[0] != '-' && node->loc == NULL)
		node->loc = ft_strdup(arv);
	else
		return (-2);



	// if (arv[1] == 'l')
	// 	node->l = 1;
	// else if (arv[1] == 'a')
	// 	node->a = 1;
	// else if (arv[1] == 'r')
	// 	node->r = 1;
	// else if (arv[1] == 't')
	// 	node->t = 1;
	// else if (arv[1] == 'g')
	// 	node->g = 1;
	// else if (arv[1] == 'R')
	// 	node->recv = 1;
	// else if (arv[1] == 'G')
	// 	node->g = 1;
	// else if (len == 1 || arv[0] != '-')
	// 	return (-2);
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
				ft_printf("{RED}ft_ls: [%s]: No such file or directory", arv[l]);
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


	// 