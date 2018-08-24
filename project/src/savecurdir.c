/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   savecurdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 08:14:29 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/24 16:41:35 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

	// char			*name;
	// char			*date;
	// char			*type;
	// struct stat		stinfo;
	// struct s_info	*next;


	//    struct stat { /* when _DARWIN_FEATURE_64_BIT_INODE is defined */
//          dev_t           st_dev;           /* ID of device containing file */
//          mode_t          st_mode;          /* Mode of file (see below) */
//          nlink_t         st_nlink;         /* Number of hard links */
//          ino_t           st_ino;           /* File serial number */
//          uid_t           st_uid;           /* User ID of the file */
//          gid_t           st_gid;           /* Group ID of the file */
//          dev_t           st_rdev;          /* Device ID */
//          struct timespec st_atimespec;     /* time of last access */
//          struct timespec st_mtimespec;     /* time of last data modification */
//          struct timespec st_ctimespec;     /* time of last status change */
//          struct timespec st_birthtimespec; /* time of file creation(birth) */
//          off_t           st_size;          /* file size, in bytes */
//          blkcnt_t        st_blocks;        /* blocks allocated for file */
//          blksize_t       st_blksize;       /* optimal blocksize for I/O */
//          uint32_t        st_flags;         /* user defined flags for file */
//          uint32_t        st_gen;           /* file generation number */
//          int32_t         st_lspare;        /* RESERVED: DO NOT USE! */
//          int64_t         st_qspare[2];     /* RESERVED: DO NOT USE! */
//      };

t_statinfo	*createnew_stat_link(t_dir *current, char *nam)
{
	t_statinfo	*ret;
	char		*tmp;

	tmp = ft_strjoin(current->fulldir, "/");
	ret = (t_statinfo*)ft_memalloc(sizeof(t_statinfo));
	ret->name = ft_strdup(nam);
	ret->fulldir = ft_strjoin(tmp, nam);
	ret->next = NULL;
	free(tmp);
	return (ret);
}

// typedef	struct		s_info
// {
// 	char			*name;
// 	char			*fulldir;
// 	char			*date;
// 	char			*permis;
// 	struct stat		stinfo;
// 	struct s_info	*next;
// }					t_statinfo;

void	savestat_link(char *name, t_dir *current)
{
	t_statinfo	*tmp;

	tmp = current->files;
	if (current->files == NULL)
		current->files = createnew_stat_link(current, name);
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = createnew_stat_link(current, name);
	}
}

void	savecurdir(t_ls *node, char *dirname)
{
	DIR				*currentdir;
	struct dirent	*nextdir;
	t_dir			*cdir;
	t_statinfo		*cfiles;

	savedir_link(node, dirname);
	cdir = findlast(node);
	currentdir = opendir(cdir->fulldir);
	if (currentdir == NULL)
	{
		ft_printf("ft_ls: %s: Permission denied\n", dirname);
		exit(1);
	}
	while (((nextdir = readdir(currentdir)) != NULL))
	{
		savestat_link(nextdir->d_name, cdir);
		cfiles = cdir->files;
		while (ft_strcmp(nextdir->d_name, cfiles->name) != 0)
			cfiles = cfiles->next;
		stat(cfiles->fulldir, &(cfiles->stinfo));
	}
	closedir(currentdir);
}


// if (currentdir == NULL)
// 	{
// 		ft_printf("opening error");
// 		exit(1);
// 	}