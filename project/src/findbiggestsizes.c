/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findbiggestsizes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 10:41:15 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/23 10:53:10 by pstubbs          ###   ########.fr       */
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

int		totalblocksizes(t_dir *dir)
{
	t_statinfo	*file;
	int			ret;

	file = dir->files;
	ret = 0;
	while (file)
	{
		ret += file->stinfo.st_blocks;
		file = file->next;
	}
	return (ret);
}
