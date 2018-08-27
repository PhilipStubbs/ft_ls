/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingalgo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 17:02:26 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/27 08:47:07 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	movelinkbackbyone(t_dir *dir, t_statinfo *b, t_statinfo *c)
{
	t_statinfo	*a;
	t_statinfo	*tmpb;
	t_statinfo	*tmpc;
	int			flag;

	a = dir->files;
	tmpb = b;
	tmpc = c;
	flag = 0;
	if (ft_strcmp(a->name, b->name) != 0)
	{
		flag = 1;
		while (ft_strcmp(a->next->name, b->name) != 0)
			a = a->next;
	}
	if (flag == 1)
		a->next = tmpc;
	else
		dir->files = tmpc;
	tmpb->next = tmpc->next;
	tmpc->next = tmpb;
}

void	birthsortfile(t_dir *tmp)
{
	t_statinfo	*file;

	file = tmp->files;
	while (file)
	{
		if (file->next != NULL && file->stinfo.st_mtimespec.tv_sec <
		file->next->stinfo.st_mtimespec.tv_sec)
		{
			movelinkbackbyone(tmp, file, file->next);
			file = tmp->files;
		}
		else
			file = file->next;
	}
}

void	revbirthsortfile(t_dir *tmp)
{
	t_statinfo	*file;

	// birthsortfile(tmp);
	file = tmp->files;
	while (file)
	{
		if (file->next != NULL && file->stinfo.st_mtimespec.tv_sec >
		file->next->stinfo.st_mtimespec.tv_sec)
		{
			movelinkbackbyone(tmp, file, file->next);
			file = tmp->files;
		}
		else
			file = file->next;
	}
}

void	alphasortfile(t_dir *tmp)
{
	t_statinfo	*file;

	file = tmp->files;
	while (file)
	{
		if (file->next != NULL && stringcomp(file->name, file->next->name) == 1)
		{
			movelinkbackbyone(tmp, file, file->next);
			file = tmp->files;
		}
		else
			file = file->next;
	}
}
