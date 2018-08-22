/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_link_creation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 10:56:53 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/22 08:16:04 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dir	*finddir_link(t_ls *node, char *dirname)
{
	t_dir	*tmp;

	tmp = node->dir;
	while (ft_strcmp(tmp->dirnam, dirname) != 0 && tmp)
		tmp = tmp->next;
	return (tmp);
}

t_dir	*createdir_link(char *dirname)
{
	t_dir	*ret;

	ret = (t_dir*)ft_memalloc(sizeof(t_statinfo));
	ret->dirnam = ft_strdup(dirname);
	// ret->comp = createnewdouble(ret, ".");
	// ret->comp = createnewdouble(ret, "..");
	ret->comp = (char**)ft_memalloc(sizeof(char *) * 3);
	ret->comp[0] = ft_strdup(".");
	ret->comp[1] = ft_strdup("..");
	ret->comp[2] = NULL;
	ret->compcoun = 0;
	ret->dircoun = 0;
	ret->files = NULL;
	ret->next = NULL;
	return (ret);
}

void	savedir_link(t_ls *node, char *name)
{
	t_dir	*tmp;
	char	*tmpstr;
	t_dir	*cdir;

	tmp = node->dir;
	if (node->dir == NULL)
		node->dir = createdir_link(name);
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = createdir_link(name);
	}
	cdir = node->dir;
	tmpstr = ft_strnew(1);
	while (ft_strcmp(cdir->dirnam, name) != 0)
	{
		tmpstr = dynamicstring(&tmpstr, cdir->dirnam);
		tmpstr = dynamicstring(&tmpstr, "/");
		cdir = cdir->next;
	}
	tmpstr = dynamicstring(&tmpstr, cdir->dirnam);
	if (cdir->fulldir == NULL)
		cdir->fulldir = ft_strdup(tmpstr);
	free(tmpstr);
}

int		dirnameexists(t_ls *node, char *dirname)
{
	t_dir	*tmp;
	char	*ret;

	tmp = node->dir;
	while (tmp)
	{
		ret = ft_strstr(tmp->dirnam, dirname);
		if (ret != NULL)
		{
			free(ret);
			return (1);
		}
		free(ret);
		tmp = tmp->next;
	}
	return (0);
}
