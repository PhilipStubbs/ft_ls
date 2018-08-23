/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingalgo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 17:02:26 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/23 09:14:51 by pstubbs          ###   ########.fr       */
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
	while(newstart && ft_strcmp(newstart->name, name) != 0)
		newstart = newstart->next;
	while(files && ft_strcmp(files->next->name, name) != 0)
		files = files->next;
	files->next = newstart->next;
	newstart->next = oldstart;
	dir->files = newstart;
	// return (dir->files);
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
	// int			lifes;

	file = tmp->files;
	// lifes = 2;
	while (file)
	{
		// if (file->next != NULL)
			// ft_printf("before [%s] | [%s]\n", file->name ,file->next->name);
		if (file->next != NULL && stringcomp(file->name ,file->next->name) == 1)
		{
			// ft_printf("changing [%s] | [%s]\n", file->next->name, file->name);
			movelinktostart(tmp, file->next->name);
			file = tmp->files;
		}
		file = file->next;
		// if (file == NULL)
		// {
		// 	lifes--;
		// 	file = tmp->files;
		// }
	}
}



// void	revalphasortfile(t_dir *tmp)
// {
// 	t_statinfo	*file;
// 	int			lifes;

// 	file = tmp->files;
// 	lifes = 2;
// 	while (lifes)
// 	{
// 		if (file->next != NULL && stringcomp(file->next->name, file->name) == 1)
// 		{
// 			// ft_printf("changing [%s] | [%s]\n", file->name ,file->next->name);
// 			movelinktostart(tmp, file->next->name);
// 		}
// 		file = file->next;
// 		if (file == NULL)
// 		{
// 			lifes--;
// 			file = tmp->files;
// 		}
// 	}
// }
