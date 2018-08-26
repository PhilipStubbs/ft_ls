/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfunc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 16:13:28 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/26 15:58:59 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	printfull(t_statinfo *file, int slen, int hlen)
{
	struct passwd	*users;
	struct group	*grp;
	char			*date;
	char			*size;
	char			*tmp;

	size = ft_lltoa(file->stinfo.st_size);
	if (file->u == 1)
		tmp = epochtostring(file->stinfo.st_atimespec.tv_sec);
	else
		tmp = epochtostring(file->stinfo.st_mtimespec.tv_sec);
	date = ft_strsub(tmp, 4, 12);
	free(tmp);
	users = getpwuid(file->stinfo.st_uid);
	grp = getgrgid(file->stinfo.st_gid);
	ft_printf("%s % *lld %-*s  %-*s % *s %s ",
	file->permis, hlen, file->stinfo.st_nlink, file->urslen, users->pw_name,
	file->grplen, grp->gr_name, slen, size, date);
	free(date);
	free(size);
}

void	theprinting(t_ls *node, t_statinfo *file, int sizelen, int hardlinklen)
{
	if (node->l)
		printfull(file, sizelen, hardlinklen);
	if (S_ISDIR(file->stinfo.st_mode) == 1 && node->g == 1 && node->spcfile)
		ft_printf("{CYN}%s/", node->loc[node->inx]);
	else if (execheck(file->stinfo.st_mode) == 1 &&
	node->g == 1 && node->spcfile)
		ft_printf("{MAG}%s/", node->loc[node->inx]);
	else if (node->spcfile)
		ft_printf("%s/", node->loc[node->inx]);
	if (S_ISDIR(file->stinfo.st_mode) == 1 && node->g == 1 && file->d_type == 4)
		ft_printf("{CYN}%s", file->name);
	else if (execheck(file->stinfo.st_mode) == 1 &&
	node->g == 1 && file->d_type != DT_LNK)
		ft_printf("{MAG}%s", file->name);
	else if (file->d_type == DT_LNK && node->g == 1)
		ft_printf("{GRN}%s", file->name);
	else
		ft_printf("%s", file->name);
	if (file->d_type == DT_LNK && node->l == 1)
		findlinkinfo(file);
	ft_printf("\n");
}

void	infoprint(t_ls *node, t_dir *tmp)
{
	if (ft_strcmp(tmp->dirnam, node->dir->dirnam) != 0 ||
	ft_doublesize(node->loc) > 1)
		ft_printf("%s:\n", tmp->fulldir);
	if (node->a == 0 && filecount(tmp) <= 2)
		return ;
	if (node->l == 1 && node->spcfile == NULL)
		ft_printf("total %d:\n", totalblocksizes(node, tmp));
}

void	spcfileprint(t_ls *node, t_dir *dir, int sizelen, int hardlinklen)
{
	t_statinfo	*file;

	file = dir->files;
	sizelen = ft_lllen(dir->files->stinfo.st_size) + 1;
	hardlinklen = ft_lllen(dir->files->stinfo.st_nlink) - 1;
	while (file && ft_strcmp(file->name, node->spcfile) != 0)
		file = file->next;
	if (file == NULL && ft_strcmp(dir->fulldir, node->loc[node->inx]) == 0)
	{
		ft_printf("{RED}ft_ls: %s/%s: No such file or directory",
		node->loc[node->inx], node->spcfile);
		return ;
	}
	infoprint(node, dir);
	theprinting(node, file, sizelen, hardlinklen);
	free(node->spcfile);
	node->spcfile = NULL;
	ft_printf("\n");
}

void	printdir(t_ls *node, t_dir *tmp)
{
	t_statinfo	*file;
	int			sizelen;
	int			hardlinklen;

	sortfile(node, tmp);
	sizelen = biggestfilesize(tmp) + 1;
	hardlinklen = biggesthardlinksize(tmp);
	if (node->spcfile)
	{
		spcfileprint(node, tmp, sizelen, hardlinklen);
		return ;
	}
	infoprint(node, tmp);
	if (node->a == 0 && filecount(tmp) <= 2)
		return ;
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
