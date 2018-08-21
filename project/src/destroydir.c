/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroydir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 12:56:31 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/21 13:35:59 by pstubbs          ###   ########.fr       */
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

void	destroydir(t_dir *dir)
{
	// t_statinfo	*tmp;

	// dir->hold;
	while (dir->hold)
	{
		destroystatinfo(dir->hold);
		dir->hold = dir->hold->next;
	}
	free(dir->dirnam);
	free(dir->fulldir);
	if (dir->comp)
		free(dir->comp);
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
// 	t_statinfo		*hold;
// 	struct s_dir	*next;
// }					t_dir;
