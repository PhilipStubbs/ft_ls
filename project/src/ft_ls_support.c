/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_support.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 17:09:45 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/26 17:10:03 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	creatpermissions(t_ls *node)
{
	t_dir	*cdir;

	cdir = node->dir;
	if (node->l)
	{
		while (cdir)
		{
			setpermission(cdir);
			cdir = cdir->next;
		}
	}
}