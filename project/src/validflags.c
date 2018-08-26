/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validflags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 11:09:38 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/26 14:46:27 by pstubbs          ###   ########.fr       */
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
	if (arv[i] == 's')
		node->s = 1;
	if (arv[i] == 'u')
		node->u = 1;
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
	if (arv[0] != '-')
		return (2);
	return (1);
}

char	**createnewchardouble(char **old, char *adding)
{
	char	**list;
	int		size;
	int		i;

	i = 0;
	size = 1;
	if (old == NULL)
		list = (char**)ft_memalloc(sizeof(char *) * (size + 2));
	else
	{
		size = ft_doublesize(old);
		list = (char**)ft_memalloc(sizeof(char *) * (size + 2));
		while (i <= size)
		{
			list[i] = ft_strdup(old[i]);
			i++;
			if (old[i] == NULL)
				break ;
		}
	}
	list[i] = ft_strdup(adding);
	list[i + 1] = NULL;
	if (old)
		freedouble(old, size);
	return (list);
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
