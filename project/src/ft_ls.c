/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 11:41:02 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/26 18:06:57 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		dircheck(t_ls *node, int i)
{
	DIR				*currentdir;

	currentdir = opendir(node->loc[i]);
	if (currentdir == NULL)
	{
		return (0);
	}
	closedir(currentdir);
	return (1);
}

int		slashcheck(t_ls *node, int i)
{
	int		count;
	int		x;

	count = 0;
	x = 0;
	while (node->loc[i][x])
	{
		if (node->loc[i][x] == '/')
			count++;
		x++;
	}
	if (count == 0)
	{
		if (dircheck(node, i) == 0)
		{
			node->spcfile = ft_strdup(node->loc[i]);
			free(node->loc[i]);
			node->loc[i] = ft_strdup(".");
			node->dflt = 1;
		}
	}
	return (count);
}

int		validfilecheck(t_ls *node, int i)
{
	char	*tmp;
	char	*dir;
	int		x;

	if ((slashcheck(node, i) == 0) || (dircheck(node, i) == 1))
		return (0);
	x = ft_strlen(node->loc[i]);
	while (node->loc[i][x] != '/')
		x--;
	dir = ft_strsub(node->loc[i], 0, x);
	tmp = ft_strsub(node->loc[i], x + 1, ft_strlen(node->loc[i]));
	free(node->loc[i]);
	node->loc[i] = ft_strdup(dir);
	node->spcfile = ft_strdup(tmp);
	free(dir);
	free(tmp);
	return (1);
}

int		validdircheck(t_ls *node, int i)
{
	DIR				*currentdir;
	int				check;

	if (node->dflt == 1)
		return (1);
	check = 1;
	validfilecheck(node, i);
	currentdir = opendir(node->loc[i]);
	if (currentdir == NULL)
	{
		if (node->spcfile == NULL)
			ft_printf("{RED}ft_ls: %s: No such file or directory", node->loc[i]);
		else
			ft_printf("{RED}ft_ls: %s/%s: No such file or directory", node->loc[i], node->spcfile);
		return (0);
	}
	closedir(currentdir);
	return (check);
}

void	ft_ls(t_ls *node)
{
	int		i;

	i = 0;
	while (node->loc[i])
	{
		node->dflt = 0;
		node->inx = i;
		if (validdircheck(node, i) == 0)
			return ;
		savecurdir(node, node->loc[i]);
		creatpermissions(node);
		if (node->recv == 1)
			recursivesearch(node);
		else
			printdir(node, node->dir);
		while (node->dir)
		{
			destroydir(node->dir);
			node->dir = node->dir->next;
		}
		i++;
	}
}
