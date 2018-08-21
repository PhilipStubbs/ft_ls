/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroydir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 12:56:31 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/21 18:04:58 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	destroystatinfo(t_statinfo *info)
{
	free(info->name);
	free(info->fulldir);
	if (info->date)
		free(info->date);
	free(info->permis);
	free(info);
}

void	freedouble(char **ar, int n)
{
	int e;

	e = 0;
	while (e < n)
	{
		free(ar[e]);
		e++;
	}
	free(ar);
}

void	destroydir(t_dir *dir)
{
	// t_statinfo	*tmp;
	int	i;

	// dir->files;
	i = 0;
	write(1,"X\n",2); 
	while (dir->files)
	{
		destroystatinfo(dir->files);
		dir->files = dir->files->next;
	}
	
	free(dir->dirnam);
	free(dir->fulldir);
	if (dir->comp)
	{
		i = ft_doublesize(dir->comp);
		freedouble(dir->comp, i);
	}
	free(dir);
}



// {
// 	char			*name;
// 	char			*fulldir;
// 	char			*date;
// 	char			*permis;
// 	struct stat		stinfo;
// 	struct s_info	*next;
// }	


// typedef	struct		s_dir
// {
// 	char			*dirnam;
// 	char			*fulldir;
// 	char			**comp;
// 	t_statinfo		*files;
// 	struct s_dir	*next;
// }					t_dir;
