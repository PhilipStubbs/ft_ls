/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:31:00 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/27 10:18:19 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/types.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <dirent.h>
# include <time.h>
# include "ft_printf.h"
# include <pwd.h>
# include <grp.h>

typedef	struct		s_info
{
	char			*name;
	char			*fulldir;
	char			*date;
	char			*permis;
	int				d_type;
	int				urslen;
	int				grplen;
	int				u;
	struct stat		stinfo;
	struct s_info	*next;
}					t_statinfo;

typedef	struct		s_dir
{
	char			*dirnam;
	char			*fulldir;
	char			**comp;
	int				compcoun;
	int				dircoun;
	t_statinfo		*files;
	struct s_dir	*next;
}					t_dir;

typedef	struct		s_ls
{
	t_dir			*dir;
	char			**loc;
	char			*spcfile;
	int				inx;
	int				dflt;
	int				lg;
	int				l;
	int				recv;
	int				a;
	int				r;
	int				t;
	int				g;
	int				s;
	int				u;
}					t_ls;

t_ls				*standardisedinitialised(void);
int					savecurdir(t_ls *node, char *name);
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
void				findsetpermission(t_ls *node, char *name);
void				alphasortfile(t_dir *tmp);
void				revalphasortfile(t_dir *tmp);
void				birthsortfile(t_dir *tmp);
void				revbirthsortfile(t_dir *tmp);
int					stringcomp(char *str1, char *str2);
void				sizesortfile(t_dir *tmp);
void				revsizesortfile(t_dir *tmp);
int					ft_lllen(long long i);
char				**createnewchardouble(char **old, char *adding);

void				printtest(t_ls *node, t_dir *tmp);
void				printdir(t_ls *node, t_dir *tmp);

void				destroylast_dir(t_ls *node);
t_dir				*findlast(t_ls *node);
int					biggesthardlinksize(t_dir *dir);
int					biggestfilesize(t_dir *dir);
int					totalblocksizes(t_ls *node, t_dir *dir);
int					numberofdirs(t_ls *node, t_dir *cdir);
int					filecount(t_ls *node, t_dir *dir);
void				setusergrplen(t_dir *dir);
void				revlastaccessortfile(t_dir *tmp);
void				lastaccessortfile(t_dir *tmp);
void				sortfile(t_ls *node, t_dir *tmp);
void				findlinkinfo(t_statinfo *file);
void				atest(t_ls *node, t_statinfo **file);
int					execheck(long long permis);
int					numberofdirs(t_ls *node, t_dir *cdir);
void				recursivesearchpreprocess(t_ls *node, int *mar, int *i);
t_statinfo			*skiphidden(t_statinfo *file);
t_dir				*findbestdirsbody(t_ls *node, t_statinfo **file);
int					recalibrate(t_dir *dir);
void				movelinkbackbyone(t_dir *dir, t_statinfo *b, t_statinfo *c);
void				movelinktostart(t_dir *dir, char *name);
void				creatpermissions(t_ls *node);

#endif
