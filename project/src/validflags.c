/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validflags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 11:09:38 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/27 09:56:02 by pstubbs          ###   ########.fr       */
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
		node->lg = 1;
	if (arv[i] == 'R')
		node->recv = 1;
	if (arv[i] == 'G')
		node->g = 1;
	if (arv[i] == 's')
		node->s = 1;
	if (arv[i] == 'u')
		node->u = 1;
}

int		allvalid(char *arv)
{
	int		i;
	char	*tmp;

	i = 0;
	while (arv[i])
	{
		tmp = ft_strchr("-GRglartsu", arv[i]);
		if (tmp == NULL)
			return (-1);
		i++;
	}
	return (1);
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
		if (allvalid(arv) == -1)
			return (-1);
		while (arv[i])
		{
			feedintonode(node, arv, i);
			i++;
		}
	}
	if (arv[0] != '-')
		return (2);
	return (1);
}

void	printerror(char *arv)
{
	ft_printf("{RED}ft_ls: illegal option [%s]\n", arv);
	ft_printf("{RED}usage:ft_ls ");
	ft_printf("{RED}[-GRglartsu] ");
	ft_printf("{RED}[file ...]\n");
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
		if (ret == 2)
		{
			node->loc = createnewchardouble(node->loc, arv[l]);
		}
		if (ret < 1)
		{
			if (ret == -2)
				ft_printf("{RED}ft_ls: [%s]: No such file or directory",
				arv[l]);
			else
				printerror(arv[l]);
			return (ret);
		}
		l++;
	}
	return (ret);
}
