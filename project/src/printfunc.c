/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfunc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 16:13:28 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/22 17:26:48 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sortfile(t_ls *node, t_dir *tmp)
{
	// t_statinfo	*file;
	(void)node;
	revbirthsortfile(tmp);

}

void	printdir(t_ls *node, t_dir *tmp)
{
	t_statinfo	*tmp2;
	sortfile(node, tmp);
	// write(1,"X\n",2); 
	ft_printf("%s\n", tmp->fulldir);
	tmp2 = tmp->files;
	while (tmp2 != NULL)
	{
		if (node->l)
			ft_printf("[%s]", tmp2->permis);

		if (S_ISDIR(tmp2->stinfo.st_mode) == 1)
			ft_printf("{CYN}%*c[%s]\n", 5, 0, tmp2->name);
		else
			ft_printf("%*c[%s]\n", 5, 0, tmp2->name);
			// ft_printf("	[%s]\n",epochtostring(tmp2->stinfo.s);
		tmp2 = tmp2->next;
	}
	ft_printf("\n");
}
