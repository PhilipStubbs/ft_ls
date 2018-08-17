/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:31:00 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/17 12:47:06 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include <sys/types.h>
#include <sys/stat.h>
#include "libft/includes/ft_printf.h"

typedef	struct		s_info
{
	char			*permissions;
	char			*name;
	char			*links;
	char			*owner;
	char			*group;
	char			*size;
	char			*date;
	char			*type;
	struct	stat	*info;
	struct	s_info	*next;
}					t_info;


typedef	struct		s_ls
{
	t_info			*hold;
	int				l;
	int				R;
	int				a;
	int				r;
	int				t;
}					t_ls;

#endif
