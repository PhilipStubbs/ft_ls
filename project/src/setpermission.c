/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setpermission.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 16:21:51 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/20 19:08:14 by pstubbs          ###   ########.fr       */
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
	
	while (tmp != NULL)
	{
		ft_printf("inside[%ld]\n",tmp->stinfo.st_mode);
		tmp->permis = findpermission(tmp->stinfo.st_mode);
		tmp = tmp->next;
	}
}

// -rw-r--r-- 1 pip users     8 Aug 20 14:53 author
// -rwxr-xr-x 1 pip users 49896 Aug 20 18:44 ft_ls
// drwxr-xr-x 2 pip users  4096 Aug 20 14:53 includes
// drwxr-xr-x 5 pip users  4096 Aug 20 14:57 libft
// -rw-r--r-- 1 pip users   518 Aug 20 16:28 makefile
// drwxr-xr-x 2 pip users  4096 Aug 20 16:21 src

// -rw-r--r-- 1 pip users 1242 Aug 20 14:57 epochtostring.c
// -rw-r--r-- 1 pip users 3574 Aug 20 18:43 ft_ls.c
// -rw-r--r-- 1 pip users 1337 Aug 20 17:13 main_ft_ls.c
// -rw-r--r-- 1 pip users  910 Aug 20 16:17 recursearch.c
// -rw-r--r-- 1 pip users 4732 Aug 20 18:17 savecurdir.c
// -rw-r--r-- 1 pip users 2756 Aug 20 18:44 setpermission.c
// -rw-r--r-- 1 pip users 1120 Aug 20 17:42 standardisedinitialised.c
// -rw-r--r-- 1 pip users 1936 Aug 20 14:53 validflags.c

// -rw-r--r--]    [makefile]
// [drwxr-xr-x]    [src]
// [-rw-r--r--]    [author]
// [-rwxr-xr-x]    [ft_ls]
// [drwxr-xr-x]    [libft]
// [drwxr-xr-x]    [includes]
// [drwxr-xr-x]    [.vscode]
// [drwxr-xr-x]    [..]
// [drwxr-xr-x]    [.]