/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingalgo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 17:02:26 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/24 14:31:39 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	movelinktostart(t_dir *dir, char *name)
{
	t_statinfo	*newstart;
	t_statinfo	*files;
	t_statinfo	*oldstart;

	newstart = dir->files;
	files = dir->files;
	oldstart = dir->files;
	while (newstart && ft_strcmp(newstart->name, name) != 0)
		newstart = newstart->next;
	while (files && ft_strcmp(files->next->name, name) != 0)
		files = files->next;
	files->next = newstart->next;
	newstart->next = oldstart;
	dir->files = newstart;
}

void	movelinkbackbyoneLEG(t_dir *dir, char *name)
{
	t_statinfo	*newstart;
	t_statinfo	*files;
	t_statinfo	*tmp;

	newstart = dir->files;
	files = dir->files;
	tmp = dir->files;
	while (newstart && ft_strcmp(newstart->name, name) != 0)
		newstart = newstart->next;
	while (files && ft_strcmp(files->next->name, name) != 0)
		files = files->next;
	while (tmp && ft_strcmp(tmp->next->next->name, name) != 0)
		tmp = tmp->next;
	files->next = newstart->next;
	newstart->next = files;
	tmp->next = newstart;
}

int		filecount(t_dir *dir)
{
	t_statinfo	*tmp;
	int			i;

	i = 0;
	tmp = dir->files;

	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}


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
		if (file->next != NULL && file->stinfo.st_mtimespec.tv_sec < file->next->stinfo.st_mtimespec.tv_sec)
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
	int			lifes;

	file = tmp->files;
	lifes = 3;
	while (file)
	{
		if (file->next != NULL && file->stinfo.st_mtimespec.tv_sec > file->next->stinfo.st_mtimespec.tv_sec)
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

void	revalphasortfile(t_dir *tmp)
{
	t_statinfo	*file;

	file = tmp->files;
	while (file)
	{
		if (file->next != NULL && stringcomp(file->name, file->next->name) == 0)
		{
			movelinkbackbyone(tmp, file, file->next);
			file = tmp->files;
		}
		else
			file = file->next;
	}
}

void	sizesortfile(t_dir *tmp)
{
	t_statinfo	*file;

	file = tmp->files;
	while (file)
	{
		if (file->next != NULL && file->stinfo.st_size < file->next->stinfo.st_size)
		{
			movelinkbackbyone(tmp, file, file->next);
			file = tmp->files;
		}
		else
			file = file->next;
	}
}

void	revsizesortfile(t_dir *tmp)
{
	t_statinfo	*file;

	file = tmp->files;
	while (file)
	{
		if (file->next != NULL && file->stinfo.st_size > file->next->stinfo.st_size)
		{
			movelinkbackbyone(tmp, file, file->next);
			file = tmp->files;
		}
		else
			file = file->next;
	}
}

		// if (file == NULL)
		// {
		// 	lifes--;
		// 	file = tmp->files;
		// }