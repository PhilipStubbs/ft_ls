/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursivesearch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 16:17:35 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/21 17:00:15 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


char	*finddirs(t_ls *node)
{
	t_dir		*tmpdir;
	t_statinfo	*file;
	char		*ret;
	int			max;
	int			i;

	tmpdir = node->dir;
	i = 0;
	while (tmpdir->next)
		tmpdir = tmpdir->next;
	file = tmpdir->files;
	ret = NULL;
	max = ft_doublesize(tmpdir->comp);
	while (file)
	{
		// ft_printf("looking in[%s]\n",file->name);
		if (S_ISDIR(file->stinfo.st_mode) == 1) //&& ft_strcmp(file->name, "..") != 0 && ft_strcmp(file->name, ".") != 0)
		{
			// ft_printf("might be valid![%s]\n",file->name);
			while (tmpdir->comp != NULL && (tmpdir->comp[i] != NULL))
			{
				if (ft_strcmp(tmpdir->comp[i], file->name) == 0 && i >= max)
					return (NULL);
				i++;
			}
			ret = ft_strdup(file->name);
		}
		file = file->next;
	}
	tmpdir->comp = createnewdouble(tmpdir, ret);
	return (ret);
}

void	recursivesearch(t_ls *node)
{
	char	*nextdir;

	nextdir = finddirs(node);
	if (nextdir != NULL)
		savecurdir(node, nextdir);
	free(nextdir);
	nextdir = finddirs(node);
	if (nextdir != NULL)
		savecurdir(node, nextdir);
	free(nextdir);
	// ft_printf("HERE[%s]\n", node->dir->comp[0]);
	// ft_printf("HERE[%s]\n", node->dir->comp[1]);
	// ft_printf("HERE[%s]\n", node->dir->comp[2]);
	// nextdir = finddirs(node);
	// if (nextdir != NULL)
	// 	savecurdir(node, nextdir);
	// free(nextdir);
}