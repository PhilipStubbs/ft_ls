/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursivesearch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 16:17:35 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/27 10:22:45 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		recalibrate(t_dir *dir)
{
	t_statinfo	*file;
	int			i;

	file = dir->files;
	i = 0;
	while (file)
	{
		if (file && ft_strncmp(file->name, ".", 1) == 0)
		{
			dir->comp = createnewdouble(dir, file->name);
			i++;
		}
		file = file->next;
	}
	return (i);
}

int		findbestdirsprocess(t_statinfo *file, t_dir *td, char **ret, int max)
{
	int			i;

	i = 0;
	if (file->d_type == 4)
	{
		while (td->comp[i] != NULL)
		{
			if ((i < max && ft_strcmp(td->comp[i], file->name) == 0))
			{
				i = -1;
				break ;
			}
			else
				i++;
		}
	}
	if (i > 0)
	{
		*ret = ft_strdup(file->name);
		return (1);
	}
	return (0);
}

char	*findbestdirs(t_ls *node)
{
	t_dir		*tmpdir;
	t_statinfo	*file;
	char		*ret;
	int			max;
	int			i;

	tmpdir = findbestdirsbody(node, &file);
	ret = NULL;
	max = ft_doublesize(tmpdir->comp);
	if (node->a == 0)
		recalibrate(tmpdir);
	while (file)
	{
		if (node->a == 0)
			file = skiphidden(file);
		if (file == NULL)
			break ;
		i = findbestdirsprocess(file, tmpdir, &ret, max);
		if (i > 0)
			break ;
		file = file->next;
	}
	if (ret != NULL)
		tmpdir->comp = createnewdouble(tmpdir, ret);
	return (ret);
}

void	recursivesearch(t_ls *node)
{
	char	*nextdir;
	t_dir	*cdir;
	int		i;
	int		maxbasedir;
	int		x;

	recursivesearchpreprocess(node, &maxbasedir, &i);
	while (i < maxbasedir && node->dflt == 0 && node->spcfile == NULL)
	{
		nextdir = findbestdirs(node);
		if (nextdir != NULL)
		{
			x = savecurdir(node, nextdir);
			findsetpermission(node, nextdir);
			cdir = findlast(node);
			if (x == 1)
				printdir(node, cdir);
			free(nextdir);
		}
		else if (nextdir == NULL)
			destroylast_dir(node);
		cdir = findlast(node);
		if (ft_strcmp(cdir->dirnam, node->dir->dirnam) == 0)
			i++;
	}
}
