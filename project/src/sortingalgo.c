/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingalgo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 17:02:26 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/24 09:29:54 by pstubbs          ###   ########.fr       */
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

void	movelinkbackbyone(t_dir *dir, char *name)
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
		// ft_printf("[%s]\n", tmp->name);
		tmp = tmp->next;
		i++;
	}
	ft_printf("size[%d]\n", i);
	return (i);
}



void	movelinkbackbyoneTEST(t_dir *dir, t_statinfo *a, t_statinfo *b,  t_statinfo *c)
{

	t_statinfo	*head;
	// int			size;

	// size = filecount(dir);
	head = dir->files;
	if (ft_strcmp(a->name, b->name) != 0)
		a->next = c;
	b->next = b->next->next;
	c->next = b;
	dir->files = head;
}

t_statinfo	*movelinkbackbyoneTEST2(t_dir *dir, char *name)
{
	t_statinfo	*newstart;
	t_statinfo	*files;
	t_statinfo	*tmp;
	t_statinfo	*head;

	newstart = dir->files;
	files = dir->files;
	tmp = dir->files;
	head = dir->files;
	while (newstart && ft_strcmp(newstart->name, name) != 0)
		newstart = newstart->next;
	while (files && ft_strcmp(files->next->name, name) != 0)
		files = files->next;
	if (ft_strcmp(tmp->name, files->name) != 0)
	{
		while (tmp && ft_strcmp(tmp->next->name, files->name) != 0)
			tmp = tmp->next;
		tmp->next = newstart;
	}
	files->next = newstart->next;
	newstart->next = files;
	return (head);
}

void	movelinkbackbyoneTEST3(t_dir *dir, t_statinfo *b, t_statinfo *c)
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
	{
		a->next = tmpc;
	}
	else
	{
		dir->files = tmpc;
	}
	tmpb->next = tmpc->next;
	tmpc->next = tmpb;
}


void	birthsortfile(t_dir *tmp)
{
	t_statinfo	*file;
	// t_statinfo	*a;

	file = tmp->files;
	while (file)
	{
		if (file->next != NULL && file->stinfo.st_mtimespec.tv_sec < file->next->stinfo.st_mtimespec.tv_sec)
		{
			movelinkbackbyoneTEST3(tmp, file, file->next);
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
			movelinkbackbyoneTEST3(tmp, file, file->next);
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
			movelinkbackbyone(tmp, file->next->name);
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
			movelinktostart(tmp, file->next->name);
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
			movelinktostart(tmp, file->next->name);
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
			movelinktostart(tmp, file->next->name);
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