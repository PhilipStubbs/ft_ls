/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:31:00 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/20 18:18:06 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <time.h>
# include "ft_printf.h"

typedef	struct		s_info
{
	char			*name;
	char			*date;
	char			*permis;
	struct stat		stinfo;
	struct s_info	*next;
}					t_statinfo;

typedef	struct		s_dir
{
	char			*dirnam;
	char			**comp;
	t_statinfo		*hold;
	struct s_dir	*next;
}					t_dir;

typedef	struct		s_ls
{
	t_dir			*dir;
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
int					validflags(t_ls *node, char **arv);
void				ft_ls(t_ls *node);
void				setpermission(t_dir *cdir);

#endif
