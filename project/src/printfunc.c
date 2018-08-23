/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfunc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 16:13:28 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/23 10:31:46 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
 #include <pwd.h>
  #include <grp.h>

void	sortfile(t_ls *node, t_dir *tmp)
{
	// t_statinfo	*file;
	(void)node;
	revalphasortfile(tmp);
}

int		biggestsize(t_dir *dir)
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

void	printfull(t_statinfo *file, int len)
{
	struct passwd	*users;
	struct group	*grp;
	char			*date;
	char			*size;

	size = ft_lltoa(file->stinfo.st_size);
	date = epochtostring(file->stinfo.st_birthtimespec.tv_sec);
	users = getpwuid(file->stinfo.st_uid);
	grp = getgrgid(file->stinfo.st_gid);
	ft_printf("%s %s %s % *s %s", 
	file->permis, users->pw_name, grp->gr_name, len ,size, date);
	free(date);
	free(size);

}

void	printdir(t_ls *node, t_dir *tmp)
{
	t_statinfo	*file;
	int			len;

	sortfile(node, tmp);
	len = biggestsize(tmp) +1 ;
	ft_printf("len [%d]\n", len);
	ft_printf("%s\n", tmp->fulldir);
	file = tmp->files;
	while (file != NULL)
	{
		if (node->l)
			printfull(file, len);

		if (S_ISDIR(file->stinfo.st_mode) == 1 && node->g == 1)
			ft_printf("{CYN}%*c[%s]\n", 5, 0, file->name);
		else
			ft_printf("%*c[%s]\n", 5, 0, file->name);
			// ft_printf("	[%s]\n",epochtostring(file->stinfo.s);
		file = file->next;
	}
	ft_printf("\n");
}
