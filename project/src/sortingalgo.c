/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingalgo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 17:02:26 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/23 09:46:23 by pstubbs          ###   ########.fr       */
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
	// return (dir->files);
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

// void	birthsortfile(t_dir *tmp)
// {
// 	t_statinfo	*file;
// 	int			lifes;

// 	file = tmp->files;
// 	lifes = 2;
// 	while (lifes)
// 	{
// 		if (file->next != NULL && file->stinfo.st_birthtimespec.tv_sec >  file->next->stinfo.st_birthtimespec.tv_sec)
// 		{
// 			file = movelinktostart(tmp, file->next->name);
// 		}
// 		file = file->next;
// 		if (file == NULL)
// 		{
// 			lifes--;
// 			file = tmp->files;
// 		}
// 	}
// }

// void	revbirthsortfile(t_dir *tmp)
// {
// 	t_statinfo	*file;
// 	int			lifes;

// 	file = tmp->files;
// 	lifes = 2;
// 	while (lifes)
// 	{
// 		if (file->next != NULL && file->stinfo.st_birthtimespec.tv_sec < file->next->stinfo.st_birthtimespec.tv_sec)
// 		{
// 			file = movelinktostart(tmp, file->next->name);
// 		}
// 		file = file->next;
// 		if (file == NULL)
// 		{
// 			lifes--;
// 			file = tmp->files;
// 		}
// 	}
// }

void	alphasortfile(t_dir *tmp)
{
	t_statinfo	*file;

	file = tmp->files;
	while (file)
	{
		if (file->next != NULL && stringcomp(file->name ,file->next->name) == 1)
		{
			movelinkbackbyone(tmp, file->next->name);
			file = tmp->files;
		}
		file = file->next;
	}
}



void	revalphasortfile(t_dir *tmp)
{
	t_statinfo	*file;
	// int			lifes;

	file = tmp->files;
	// lifes = 2;
	while (file)
	{
		if (file->next != NULL && stringcomp(file->name ,file->next->name) == 0)
		{
			// ft_printf("changing [%s] | [%s]\n", file->name ,file->next->name);
			movelinktostart(tmp, file->next->name);
			file = tmp->files;
		}
		file = file->next;
	// 	if (file == NULL)
	// 	{
	// 		lifes--;
	// 		file = tmp->files;
	// 	}
	}
}
