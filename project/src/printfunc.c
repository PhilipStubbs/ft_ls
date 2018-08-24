/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfunc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 16:13:28 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/24 14:32:08 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sortfile(t_ls *node, t_dir *tmp)
{
	if (node->r == 1 && node->t == 0 && node->s == 0)
		revalphasortfile(tmp);
	else if (node->r == 0 && node->t == 1 && node->s == 0)
		birthsortfile(tmp);
	else if (node->r == 1 && node->t == 1 && node->s == 0)
		revbirthsortfile(tmp);
	else if (node->s == 1 && node->r == 0)
		sizesortfile(tmp);
	else if (node->s == 1 && node->r == 1)
		revsizesortfile(tmp);
	else
		alphasortfile(tmp);
}

void	printfull(t_statinfo *file, int slen, int hlen)
{
	struct passwd	*users;
	struct group	*grp;
	char			*date;
	char			*size;
	char			*tmp;

	size = ft_lltoa(file->stinfo.st_size);
	tmp = epochtostring(file->stinfo.st_mtimespec.tv_sec);
	date = ft_strsub(tmp, 4, 12);
	free(tmp);
	users = getpwuid(file->stinfo.st_uid);
	grp = getgrgid(file->stinfo.st_gid);
	ft_printf("%s % *lld %s  %s % *s %s ",
	file->permis, hlen, file->stinfo.st_nlink, users->pw_name,
	grp->gr_name, slen, size, date);
	free(date);
	free(size);
}

int		execheck(long long permis)
{
	if ((permis & S_IXGRP || permis & S_IXUSR ||
	permis & S_IXOTH) && S_ISDIR(permis) == 0)
		return (1);
	else
		return (0);
}

void	atest(t_ls *node, t_statinfo **file)
{
	if (node->a == 0)
	{
		while ((*file) && (*file)->name[0] == '.')
			(*file) = (*file)->next;
	}
}

void	theprinting(t_ls *node, t_statinfo *file, int sizelen, int hardlinklen)
{
	if (node->l)
		printfull(file, sizelen, hardlinklen);
	if (S_ISDIR(file->stinfo.st_mode) == 1 && node->g == 1)
		ft_printf("{CYN}%s\n", file->name);
	else if (execheck(file->stinfo.st_mode) == 1 && node->g == 1)
		ft_printf("{MAG}%s\n", file->name);
	else
		ft_printf("%s\n", file->name);
}

void	printdir(t_ls *node, t_dir *tmp)
{
	t_statinfo	*file;
	int			sizelen;
	int			hardlinklen;

	sortfile(node, tmp);
	if (node->a == 0 && filecount(tmp) <= 2)
		return ;
	sizelen = biggestfilesize(tmp) + 1;
	hardlinklen = biggesthardlinksize(tmp);
	if (ft_strcmp(tmp->dirnam, node->dir->dirnam) != 0)
		ft_printf("%s:\n", tmp->fulldir);
	if (node->l == 1)
		ft_printf("total %d:\n", totalblocksizes(tmp));
	file = tmp->files;
	while (file != NULL)
	{
		atest(node, &file);
		if (file == NULL)
			break ;
		theprinting(node, file, sizelen, hardlinklen);
		file = file->next;
	}
	ft_printf("\n");
}
