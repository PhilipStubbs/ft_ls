/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:31:00 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/20 10:04:44 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <time.h>
# include "libft/includes/ft_printf.h"

typedef	struct		s_info
{
	char			*name;
	char			*date;
	char			*type;
	struct stat		stinfo;
	struct s_info	*next;
}					t_statinfo;

typedef	struct		s_dir
{
	char			*dir;
	struct s_dir	*next;
}					t_dir;

typedef	struct		s_ls
{
	t_statinfo		*hold;
	t_dir			*curdir;
	int				l;
	int				recv;
	int				a;
	int				r;
	int				t;
	int				g;
}					t_ls;

t_ls				*standardisedinitialised(void);
void				savecurdir(t_ls *node, char *name);
char				*epochtostring(long long epoch);

#endif
