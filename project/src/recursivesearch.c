/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursivesearch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 16:17:35 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/22 13:16:41 by pstubbs          ###   ########.fr       */
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
		if (S_ISDIR(file->stinfo.st_mode) == 1) //&& ft_strncmp(file->name, "." , 1) != 0)
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

t_dir	*findlast(t_ls *node)
{
	t_dir *cdir;

	cdir = node->dir;
	while (cdir->next)
		cdir = cdir->next;
	return (cdir);
}

int		numberofdirs(t_dir *cdir)
{
	t_statinfo	*file;
	int	count;

	count = 0;
	file = cdir->files;
	while (file)
	{
		if (S_ISDIR(file->stinfo.st_mode) == 1 &&
		ft_strcmp(file->name, ".") != 0 &&
		ft_strcmp(file->name, "..") != 0)
			count++;
		file = file->next;
	}
	return (count);
}

void	recursivesearch(t_ls *node)
{
	char	*nextdir;
	t_dir	*cdir;
	int		i;
	int		maxbasedir;

	printdir(node, node->dir);
	i = 0;
	maxbasedir = numberofdirs(node->dir);
	while (i < maxbasedir)
	{
		nextdir = finddirs(node);
		if (nextdir != NULL)
		{
			savecurdir(node, nextdir);
			findsetpermission(node, nextdir);
			cdir = findlast(node);
			printdir(node, cdir);
			free(nextdir);
		}
		else if (nextdir == NULL)
		{
			// ft_printf("[%s]\n",NULL);
			destroylast_dir(node);
		}
		cdir = findlast(node);
		if (ft_strcmp(cdir->dirnam, node->dir->dirnam) == 0)
			i++;
	}
}

// ./ Filler_Visualizer-master/ visualizer/ frameworks/ SDL2_image.framework/ Frameworks /webp.framework/ Headers 7
// ./ Algo 1/ Filler_Visualizer-master/ visualizer/ frameworks/ SDL2.framework/ Versions 6
// ./ Completed Projects/ Algo 1/ filler/ .git/ objects/ ea  6