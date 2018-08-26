/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printsupport.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 15:58:02 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/26 15:59:30 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		execheck(long long permis)
{
	if ((permis & S_IXGRP || permis & S_IXUSR ||
	permis & S_IXOTH) && S_ISDIR(permis) == 0)
		return (1);
	else
		return (0);
}

void	atest(t_ls *node, t_statinfo **file)
{
	if (node->a == 0)
	{
		while ((*file) && (*file)->name[0] == '.')
			(*file) = (*file)->next;
	}
}

void	findlinkinfo(t_statinfo *file)
{
	char	buff[1024];
	int		i;

	i = readlink(file->fulldir, buff, 1023);
	buff[i] = '\0';
	ft_printf(" -> %s", buff);
}

void	sortfile(t_ls *node, t_dir *tmp)
{
	if (node->l == 1)
		setusergrplen(tmp);
	if (node->r == 1 && node->t == 0 && node->s == 0)
		revalphasortfile(tmp);
	else if (node->r == 0 && node->t == 1 && node->s == 0)
		birthsortfile(tmp);
	else if (node->r == 1 && node->t == 1 && node->s == 0)
		revbirthsortfile(tmp);
	else if (node->s == 1 && node->r == 0)
		sizesortfile(tmp);
	else if (node->s == 1 && node->r == 1)
		revsizesortfile(tmp);
	else if (node->u == 1 && node->r == 0)
		lastaccessortfile(tmp);
	else if (node->u == 1 && node->r == 1)
		revlastaccessortfile(tmp);
	else
		alphasortfile(tmp);
}
