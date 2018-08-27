/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   savecurdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 08:14:29 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/27 10:27:36 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_statinfo	*createnew_stat_link(t_ls *node, t_dir *c, char *nam, int d_type)
{
	t_statinfo	*ret;
	char		*tmp;

	tmp = ft_strjoin(c->fulldir, "/");
	ret = (t_statinfo*)ft_memalloc(sizeof(t_statinfo));
	ret->name = ft_strdup(nam);
	ret->fulldir = ft_strjoin(tmp, nam);
	ret->d_type = d_type;
	ret->u = node->u;
	ret->next = NULL;
	free(tmp);
	return (ret);
}

void		savestat_link(t_ls *node, char *name, t_dir *current, int d_type)
{
	t_statinfo	*tmp;

	tmp = current->files;
	if (current->files == NULL)
		current->files = createnew_stat_link(node, current, name, d_type);
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = createnew_stat_link(node, current, name, d_type);
	}
}

int			returnerror(t_dir *cdir, char *dirname)
{
	return (ft_printf("%s:\nft_ls: %s: Permission denied\n\n",
	cdir->fulldir, dirname));
}

int			savecurdir(t_ls *node, char *dirname)
{
	DIR				*currentdir;
	struct dirent	*nextdir;
	t_dir			*cdir;
	t_statinfo		*cfiles;

	savedir_link(node, dirname);
	cdir = findlast(node);
	currentdir = opendir(cdir->fulldir);
	if (currentdir == NULL)
		return (returnerror(cdir, dirname));
	while (((nextdir = readdir(currentdir)) != NULL))
	{
		savestat_link(node, nextdir->d_name, cdir, nextdir->d_type);
		cfiles = cdir->files;
		while (ft_strcmp(nextdir->d_name, cfiles->name) != 0)
			cfiles = cfiles->next;
		if (nextdir->d_type == DT_LNK)
			lstat(cfiles->fulldir, &(cfiles->stinfo));
		else
			stat(cfiles->fulldir, &(cfiles->stinfo));
	}
	closedir(currentdir);
	return (1);
}
