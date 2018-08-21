/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:31:00 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/21 16:40:08 by pstubbs          ###   ########.fr       */
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
	char			*fulldir;
	char			*date;
	char			*permis;
	struct stat		stinfo;
	struct s_info	*next;
}					t_statinfo;

typedef	struct		s_dir
{
	char			*dirnam;
	char			*fulldir;
	char			**comp;
	t_statinfo		*files;
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
void				savedir_link(t_ls *node, char *name);
int					dirnameexists(t_ls *node, char *dirname);
t_dir				*finddir_link(t_ls *node, char *dirname);
void				destroydir(t_dir *dir);
void				recursivesearch(t_ls *node);
char				**createnewdouble(t_dir *current, char *adding);
void				freedouble(char **ar, int n);

void				printtest(t_ls *node, t_dir *tmp);

#endif
