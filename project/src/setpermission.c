/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setpermission.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 16:21:51 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/20 18:16:24 by pstubbs          ###   ########.fr       */
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
		dynamicchar(ret, 'w');
	else
		dynamicchar(ret, '-');
	if (permis & S_IXGRP)
		dynamicchar(ret, 'x');
	else
		dynamicchar(ret, '-');
	if (permis & S_IROTH)
		dynamicchar(ret, 'r');
	else
		dynamicchar(ret, '-');
	if (permis & S_IWOTH)
		dynamicchar(ret, 'w');
	else
		dynamicchar(ret, '-');
	if (permis & S_IXOTH)
		dynamicchar(ret, 'x');
	else
		dynamicchar(ret, '-');
	// if (S_IFLNK(permis))
	// 	dynamicchar(&ret, '@');
}

char	*findpermission(long long permis)
{
	char	*ret;
	ret = ft_strnew(1);
	if (S_ISDIR(permis))
		dynamicchar(&ret, 'd');
	else
		dynamicchar(&ret, '-');
	if (permis & S_IRUSR)
		dynamicchar(&ret, 'r');
	else
		dynamicchar(&ret, '-');
	if (permis & S_IWUSR)
		dynamicchar(&ret, 'w');
	else
		dynamicchar(&ret, '-');
	if (permis & S_IXUSR)
		dynamicchar(&ret, 'x');
	else
		dynamicchar(&ret, '-');
	if (permis & S_IRGRP)
		dynamicchar(&ret, 'r');
	else
		dynamicchar(&ret, '-');
	findpermission_part2(permis, &ret);
	return (ret);
}

void	setpermission(t_dir *cdir)
{
	t_statinfo	*tmp;

	tmp = cdir->hold;
	// while (tmp != NULL)
	// {
		tmp->permis = findpermission(tmp->stinfo.st_mode);
		tmp = tmp->next;
	// }
}