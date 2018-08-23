/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfunc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 16:13:28 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/23 10:55:38 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
 #include <pwd.h>
  #include <grp.h>

void	sortfile(t_ls *node, t_dir *tmp)
{
	// t_statinfo	*file;
	(void)node;
	alphasortfile(tmp);
}

void	printfull(t_statinfo *file, int slen, int hlen)
{
	struct passwd	*users;
	struct group	*grp;
	char			*date;
	char			*size;

	size = ft_lltoa(file->stinfo.st_size);
	date = epochtostring(file->stinfo.st_birthtimespec.tv_sec);
	users = getpwuid(file->stinfo.st_uid);
	grp = getgrgid(file->stinfo.st_gid);
	ft_printf("%s  % *lld %s %s % *s %s", 
	file->permis, hlen ,file->stinfo.st_nlink, users->pw_name, grp->gr_name, slen ,size, date);
	free(date);
	free(size);

}

void	printdir(t_ls *node, t_dir *tmp)
{
	t_statinfo	*file;
	int			sizelen;
	int			hardlinklen;

	sortfile(node, tmp);
	sizelen = biggestfilesize(tmp) + 1;
	hardlinklen = biggesthardlinksize(tmp);
	ft_printf("%s:\n", tmp->fulldir);
	if (node->l == 1)
		ft_printf("total %d:\n", totalblocksizes(tmp));
	file = tmp->files;
	while (file != NULL)
	{
		if (node->l)
			printfull(file, sizelen, hardlinklen);

		if (S_ISDIR(file->stinfo.st_mode) == 1 && node->g == 1)
			ft_printf("{CYN}%*c[%s]\n", 5, 0, file->name);
		else
			ft_printf("%*c[%s]\n", 5, 0, file->name);
			// ft_printf("	[%s]\n",epochtostring(file->stinfo.s);
		file = file->next;
	}
	ft_printf("\n");
}
