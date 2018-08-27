/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingalgosupport.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 17:02:41 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/27 08:29:38 by pstubbs          ###   ########.fr       */
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

int		filecount(t_ls *node, t_dir *dir)
{
	t_statinfo	*file;
	int			i;

	i = 0;
	file = dir->files;
	while (file)
	{
		if (ft_strcmp(file->name, ".") != 0 &&
		ft_strcmp(file->name, "..") != 0 &&
		ft_strncmp(file->name, ".", 1) != 0)
			i++;
		if (node->a == 1 && ft_strncmp(file->name, ".", 1) == 0 &&
		ft_strcmp(file->name, ".") != 0 &&
		ft_strcmp(file->name, "..") != 0)
			i++;
		file = file->next;
		i++;
	}
	return (i);
}
