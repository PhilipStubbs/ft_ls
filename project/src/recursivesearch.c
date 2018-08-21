/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursivesearch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 16:17:35 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/21 18:06:16 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


char	*finddirs(t_ls *node)
{
	t_dir		*tmpdir;
	t_statinfo	*file;
	char		*ret;
	int			max;
	int			i;

	tmpdir = node->dir;
	while (tmpdir->next)
		tmpdir = tmpdir->next;
	file = tmpdir->files;
	ret = NULL;
	max = ft_doublesize(tmpdir->comp);

	while (file)
	{
		if (S_ISDIR(file->stinfo.st_mode) == 1 && ft_strncmp(file->name, "." , 1) != 0)
		{
			i = 0;
			while (tmpdir->comp[i] != NULL)
			{
				if (i < max && ft_strcmp(tmpdir->comp[i], file->name) == 0)
				{
					i = -1;
					break ;
				}
				else
					i++;
			}
			// ft_printf("out[%s]\n", file->name);
			if (i >= 0)
			{
				ret = ft_strdup(file->name);
				break ;
			}
		}
		file = file->next;
	}
	if (ret != NULL)
		tmpdir->comp = createnewdouble(tmpdir, ret);
	// ft_printchardouble(tmpdir->comp);
	// if (ret == NULL)
	// 	destroydir(tmpdir);
	return (ret);
}

t_dir	*finddir(t_ls *node, char *name)
{
	t_dir *cdir;

	cdir = node->dir;
	while (cdir->next && ft_strcmp(name, cdir->dirnam))
		cdir = cdir->next;
	return (cdir);
}

void	recursivesearch(t_ls *node)
{
	char	*nextdir;
	t_dir *cdir;

	nextdir = finddirs(node);
	if (nextdir != NULL)
	{
		savecurdir(node, nextdir);
		findsetpermission(node, nextdir);
	}
	free(nextdir);
	nextdir = finddirs(node);
	if (nextdir != NULL)
	{
		savecurdir(node, nextdir);
		findsetpermission(node, nextdir);
	}
	cdir = finddir(node, nextdir);
	// ft_printf("[%s]\n", cdir->next->dirnam);
	// destroydir(cdir->next);
	free(nextdir);
	
	// ft_printf("HERE[%s]\n", node->dir->comp[0]);
	// ft_printf("HERE[%s]\n", node->dir->comp[1]);
	// ft_printf("HERE[%s]\n", node->dir->comp[2]);
	// nextdir = finddirs(node);
	// if (nextdir != NULL)
	// 	savecurdir(node, nextdir);
	// free(nextdir);
}