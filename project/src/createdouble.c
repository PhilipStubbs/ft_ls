/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createdouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 16:25:55 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/21 16:44:17 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**createnewdouble(t_dir *current, char *adding)
{
	char	**list;
	int		size;
	int		i;

	i = 0;
	size = 1;
	if (current->comp == NULL)
		list = (char**)ft_memalloc(sizeof(char *) * (size + 2));
	else
	{
		size = ft_doublesize(current->comp);
		list = (char**)ft_memalloc(sizeof(char *) * (size + 2));
		while (i <= size)
		{
			list[i] = ft_strdup(current->comp[i]);
			i++;
			if (current->comp[i] == NULL)
				break ;
		}
	}
	list[i] = ft_strdup(adding);
	list[i + 1] = NULL;
	if (current->comp)
		freedouble(current->comp, size);
	return (list);
}
