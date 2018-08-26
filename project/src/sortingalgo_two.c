/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingalgo_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 16:55:06 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/26 16:55:33 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
		if (file->next != NULL && file->stinfo.st_size <
		file->next->stinfo.st_size)
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
		if (file->next != NULL && file->stinfo.st_size >
		file->next->stinfo.st_size)
		{
			movelinkbackbyone(tmp, file, file->next);
			file = tmp->files;
		}
		else
			file = file->next;
	}
}

void	lastaccessortfile(t_dir *tmp)
{
	t_statinfo	*file;

	file = tmp->files;
	while (file)
	{
		if (file->next != NULL && file->stinfo.st_atimespec.tv_sec >
		file->next->stinfo.st_atimespec.tv_sec)
		{
			movelinkbackbyone(tmp, file, file->next);
			file = tmp->files;
		}
		else
			file = file->next;
	}
}

void	revlastaccessortfile(t_dir *tmp)
{
	t_statinfo	*file;

	file = tmp->files;
	while (file)
	{
		if (file->next != NULL && file->stinfo.st_atimespec.tv_sec <
		file->next->stinfo.st_atimespec.tv_sec)
		{
			movelinkbackbyone(tmp, file, file->next);
			file = tmp->files;
		}
		else
			file = file->next;
	}
}
