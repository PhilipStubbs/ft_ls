/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setpermission.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 16:21:51 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/22 11:25:53 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
    // printf("File Permissions: \t");
    // printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    // printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    // printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    // printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    // printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    // printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    // printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    // printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    // printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    // printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
	// S_IFLNK
void	findpermission_part2(long long permis, char **ret)
{
	if (permis & S_IWGRP)
		*ret = dynamicstring(ret, "w");
	else
		*ret = dynamicstring(ret, "-");
	if (permis & S_IXGRP)
		*ret = dynamicstring(ret, "x");
	else
		*ret = dynamicstring(ret, "-");
	if (permis & S_IROTH)
		*ret = dynamicstring(ret, "r");
	else
		*ret = dynamicstring(ret, "-");
	if (permis & S_IWOTH)
		*ret = dynamicstring(ret, "w");
	else
		*ret = dynamicstring(ret, "-");
	if (permis & S_IXOTH)
		*ret = dynamicstring(ret, "x");
	else
		*ret = dynamicstring(ret, "-");
	// if (permis & S_IFLNK)
	// *ret = dynamicchar(ret, '@');
	// if (S_ISLNK(permis) == 1)
		// *ret = dynamicchar(ret, '@');
}

char	*findpermission(long long permis)
{
	char	*ret;

	ret = ft_strnew(1);
	if (S_ISDIR(permis))
		ret = dynamicstring(&ret, "d");
	else
		ret = dynamicstring(&ret, "-");
	if (permis & S_IRUSR)
		ret = dynamicstring(&ret, "r");
	else
		ret = dynamicstring(&ret, "-");
	if (permis & S_IWUSR)
		ret = dynamicstring(&ret, "w");
	else
		ret = dynamicstring(&ret, "-");
	if (permis & S_IXUSR)
		ret = dynamicstring(&ret, "x");
	else
		ret = dynamicstring(&ret, "-");
	if (permis & S_IRGRP)
		ret = dynamicstring(&ret, "r");
	else
		ret = dynamicstring(&ret, "-");
	findpermission_part2(permis, &ret);
	return (ret);
}

void	findsetpermission(t_ls *node, char *name)
{
	t_dir *cdir;

	// cdir = node->dir;
	(void)name;
	cdir = findlast(node);
	// while (cdir && ft_strcmp(name, cdir->dirnam))
	// 	cdir = cdir->next;
	setpermission(cdir);
}

void	setpermission(t_dir *cdir)
{
	t_statinfo	*tmp;

	tmp = cdir->files;
	while (tmp != NULL)
	{
		if (tmp->permis == NULL)
			tmp->permis = findpermission(tmp->stinfo.st_mode);
		tmp = tmp->next;
	}
}
