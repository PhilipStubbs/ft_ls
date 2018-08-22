/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroydir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 12:56:31 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/22 13:20:26 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	destroystatinfo(t_statinfo *info)
{
	free(info->name);
	free(info->fulldir);
	if (info->date)
		free(info->date);
	free(info->permis);
	free(info);
}

void	freedouble(char **ar, int n)
{
	int e;

	e = 0;
	while (e < n)
	{
		free(ar[e]);
		e++;
	}
	free(ar);
}

void	destroydir(t_dir *dir)
{
	int	i;

	i = 0;
	while (dir->files)
	{
		destroystatinfo(dir->files);
		dir->files = dir->files->next;
	}
	free(dir->dirnam);
	free(dir->fulldir);
	if (dir->comp)
	{
		i = ft_doublesize(dir->comp);
		freedouble(dir->comp, i);
	}
	free(dir);
}

void	destroylast_dir(t_ls *node)
{
	t_dir *cdir;

	cdir = node->dir;
	while (cdir->next != NULL && (cdir->next->next != NULL))
		cdir = cdir->next;
	destroydir(cdir->next);
	cdir->next = NULL;
	
}
