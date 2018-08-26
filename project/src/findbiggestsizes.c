/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findbiggestsizes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 10:41:15 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/26 15:08:56 by pstubbs          ###   ########.fr       */
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

int		ft_lllen(long long i)
{
	int		x;

	x = 1;
	while (i /= 10)
		x++;
	return (x);
}

int		findusergroupsize(t_statinfo *file, int ug)
{
	struct passwd	*users;
	struct group	*grp;

	if (ug == 1)
	{
		grp = getgrgid(file->stinfo.st_gid);
		return (ft_strlen(grp->gr_name));
	}
	users = getpwuid(file->stinfo.st_uid);
	return (ft_strlen(users->pw_name));
}

void	setuserlen(t_dir *dir)
{
	t_statinfo	*file;
	int			tmpsize;
	int			ret;

	file = dir->files;
	ret = 0;
	while (file)
	{
		tmpsize = findusergroupsize(file, 0);
		if (tmpsize > ret)
			ret = tmpsize;
		file = file->next;
	}
	file = dir->files;
	while (file)
	{
		file->urslen = ret;
		file = file->next;
	}
}

void	setgrplen(t_dir *dir)
{
	t_statinfo	*file;
	int			tmpsize;
	int			ret;

	file = dir->files;
	ret = 0;
	while (file)
	{
		tmpsize = findusergroupsize(file, 1);
		if (tmpsize > ret)
			ret = tmpsize;
		file = file->next;
	}
	file = dir->files;
	while (file)
	{
		file->grplen = ret;
		file = file->next;
	}
}

void	setusergrplen(t_dir *dir)
{
	setuserlen(dir);
	setgrplen(dir);
}
