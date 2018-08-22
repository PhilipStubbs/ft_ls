/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfunc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 16:13:28 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/22 18:03:09 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sortfile(t_ls *node, t_dir *tmp)
{
	// t_statinfo	*file;
	(void)node;
	revbirthsortfile(tmp);

}

void	printfull(t_statinfo *file)
{
	struct passwd	*users;
	struct group	*grp;
	char			*date;

	date = epochtostring(file->stinfo.st_birthtimespec)
	users = getpwuid(file->stinfo.st_uid);
	grp = getgrgid(file->stinfo.st_gid);
	ft_printf("%s %s %s %lld", 
	file->permis, users->pw_name, grp->gr_name, file->stinfo.st_size);

}

void	printdir(t_ls *node, t_dir *tmp)
{
	t_statinfo	*file;
	sortfile(node, tmp);
	ft_printf("%s\n", tmp->fulldir);
	file = tmp->files;
	while (file != NULL)
	{
		if (node->l)
			printfull(file);

		if (S_ISDIR(file->stinfo.st_mode) == 1)
			ft_printf("{CYN}%*c[%s]\n", 5, 0, file->name);
		else
			ft_printf("%*c[%s]\n", 5, 0, file->name);
			// ft_printf("	[%s]\n",epochtostring(file->stinfo.s);
		file = file->next;
	}
	ft_printf("\n");
}
