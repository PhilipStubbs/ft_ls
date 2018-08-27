/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_support.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 17:09:45 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/27 09:12:59 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	creatpermissions(t_ls *node)
{
	t_dir	*cdir;

	cdir = node->dir;
	if (node->l || node->lg)
	{
		while (cdir)
		{
			setpermission(cdir);
			cdir = cdir->next;
		}
	}
}

char	**createnewchardouble(char **old, char *adding)
{
	char	**list;
	int		size;
	int		i;

	i = 0;
	size = 1;
	if (old == NULL)
		list = (char**)ft_memalloc(sizeof(char *) * (size + 2));
	else
	{
		size = ft_doublesize(old);
		list = (char**)ft_memalloc(sizeof(char *) * (size + 2));
		while (i <= size)
		{
			list[i] = ft_strdup(old[i]);
			i++;
			if (old[i] == NULL)
				break ;
		}
	}
	list[i] = ft_strdup(adding);
	list[i + 1] = NULL;
	if (old)
		freedouble(old, size);
	return (list);
}
