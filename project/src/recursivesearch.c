/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursivesearch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 16:17:35 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/21 15:27:39 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*finddirs(t_dir *node)
{

}

void	recursivesearch(t_ls *node)
{
	char	*nextdir;

	nextdir = finddirs(node);
	savecurdir(node, "src");
}