/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findbiggestsizes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 10:41:15 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/26 15:56:44 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		biggestfilesize(t_dir *dir)
{
	t_statinfo	*file;
	long long	tmp;
	int			tmpsize;
	int			ret;

	file = dir->files;
	ret = 0;
	while (file)
	{
		tmp = file->stinfo.st_size;
		tmpsize = 1;
		while (tmp /= 10)
			tmpsize++;
		if (tmpsize > ret)
			ret = tmpsize;
		file = file->next;
	}
	return (ret);
}

int		biggesthardlinksize(t_dir *dir)
{
	t_statinfo	*file;
	long long	tmp;
	int			tmpsize;
	int			ret;

	file = dir->files;
	ret = 0;
	while (file)
	{
		tmp = file->stinfo.st_nlink;
		tmpsize = 1;
		while (tmp /= 10)
			tmpsize++;
		if (tmpsize > ret)
			ret = tmpsize;
		file = file->next;
	}
	return (ret);
}

int		totalblocksizes(t_ls *node, t_dir *dir)
{
	t_statinfo	*file;
	int			ret;

	file = dir->files;
	ret = 0;
	while (file)
	{
		if (node->a == 0 && (ft_strcmp(file->name, ".") != 0 &&
		ft_strcmp(file->name, "..") != 0 &&
		ft_strncmp(file->name, ".", 1) != 0))
			ret += file->stinfo.st_blocks;
		else if (node->a == 1)
			ret += file->stinfo.st_blocks;
		file = file->next;
	}
	return (ret);
}

int		ft_lllen(long long i)
{
	int		x;

	x = 1;
	while (i /= 10)
		x++;
	return (x);
}
