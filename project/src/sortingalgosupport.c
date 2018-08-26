/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingalgosupport.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 17:02:41 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/26 17:06:01 by pstubbs          ###   ########.fr       */
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
