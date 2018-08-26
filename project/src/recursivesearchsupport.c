/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursivesearchsupport.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 16:09:33 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/26 17:40:06 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			numberofdirs(t_ls *node, t_dir *cdir)
{
	t_statinfo	*file;
	int			count;

	count = 0;
	file = cdir->files;
	(void)node;
	while (file)
	{
		if (S_ISDIR(file->stinfo.st_mode) == 1 &&
		ft_strcmp(file->name, ".") != 0 &&
		ft_strcmp(file->name, "..") != 0 &&
		ft_strncmp(file->name, ".", 1) != 0
		&& file->d_type == 4)
			count++;
		if (node->a == 1 && ft_strncmp(file->name, ".", 1) == 0 &&
		ft_strcmp(file->name, ".") != 0 &&
		ft_strcmp(file->name, "..") != 0 && file->d_type == 4)
			count++;
		file = file->next;
	}
	return (count);
}

void		recursivesearchpreprocess(t_ls *node, int *maxbasedir, int *i)
{
	printdir(node, node->dir);
	*i = 0;
	if (node->a == 0)
		recalibrate(node->dir);
	*maxbasedir = (numberofdirs(node, node->dir));
}

t_dir		*findlast(t_ls *node)
{
	t_dir *cdir;

	cdir = node->dir;
	while (cdir->next)
		cdir = cdir->next;
	return (cdir);
}

t_statinfo	*skiphidden(t_statinfo *file)
{
	while (file && ft_strncmp(file->name, ".", 1) == 0)
		file = file->next;
	return (file);
}

t_dir		*findbestdirsbody(t_ls *node, t_statinfo **file)
{
	t_dir *tmpdir;

	tmpdir = node->dir;
	while (tmpdir->next)
		tmpdir = tmpdir->next;
	*file = tmpdir->files;
	return (tmpdir);
}
