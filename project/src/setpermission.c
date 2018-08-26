/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setpermission.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 16:21:51 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/26 15:10:23 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	findpermission_part2(long long  permis, char **ret, char *dir)
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
	if ((listxattr(dir, 0, 0, XATTR_NOFOLLOW)) > 0)
		*ret = dynamicstring(ret, "@");
	else
		*ret = dynamicstring(ret, " ");
}

void	filetype(int premis, char **ret)
{
	if (premis == DT_REG)
		*ret = dynamicstring(ret, "-");
	else if (premis == DT_DIR)
		*ret = dynamicstring(ret, "d");
	else if (premis == DT_LNK)
		*ret = dynamicstring(ret, "l");
	else if (premis == DT_BLK)
		*ret = dynamicstring(ret, "b");
	else if (premis == DT_CHR)
		*ret = dynamicstring(ret, "c");
	else if (premis == DT_SOCK)
		*ret = dynamicstring(ret, "s");
	else if (premis == DT_FIFO)
		*ret = dynamicstring(ret, "p");
	else
		*ret = dynamicstring(ret, "-");
}

char	*findpermission(int d_type, long long permis, char *dir)
{
	char	*ret;

	ret = ft_strnew(1);
	filetype(d_type, &ret);
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
	findpermission_part2(permis, &ret, dir);
	return (ret);
}

void	findsetpermission(t_ls *node, char *name)
{
	t_dir *cdir;

	(void)name;
	cdir = findlast(node);
	setpermission(cdir);
}

void	setpermission(t_dir *cdir)
{
	t_statinfo	*tmp;

	tmp = cdir->files;
	while (tmp != NULL)
	{
		if (tmp->permis == NULL)
			tmp->permis = findpermission(tmp->d_type, tmp->stinfo.st_mode, tmp->fulldir);
		tmp = tmp->next;
	}
}
