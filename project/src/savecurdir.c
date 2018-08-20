/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   savecurdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 08:14:29 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/20 19:09:28 by pstubbs          ###   ########.fr       */
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

// S_ISBLK(m)
// Test for a block special file.
// S_ISCHR(m)
// Test for a character special file.
// S_ISDIR(m)
// Test for a directory.
// S_ISFIFO(m)
// Test for a pipe or FIFO special file.
// S_ISREG(m)
// Test for a regular file.
// S_ISLNK(m)
// Test for a symbolic link.
// S_ISSOCK(m)
// Test for a socket.

t_statinfo	*createnew_stat_link(struct stat statinfo, char *nam)
{
	t_statinfo	*ret;

	ret = (t_statinfo*)ft_memalloc(sizeof(t_statinfo));
	ret->stinfo = statinfo;
	ret->name = ft_strdup(nam);
	ret->next = NULL;
	return (ret);
}

void	savestat_link(struct stat statinfo, char *name, t_dir *current)
{
	t_statinfo	*tmp;

	tmp = current->hold;
	if (current->hold == NULL)
		current->hold = createnew_stat_link(statinfo, name);
	else
	{
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = createnew_stat_link(statinfo, name);
	}
}

t_dir	*createdir_link(char *dirname)
{
	t_dir	*ret;

	ret = (t_dir*)ft_memalloc(sizeof(t_statinfo));
	ret->dirnam = ft_strdup(dirname);
	ret->comp = NULL;
	ret->hold = NULL;
	ret->next = NULL;
	return (ret);
}

void	savedir_link(t_ls *node, char *name)
{
	t_dir	*tmp;

	tmp = node->dir;
	if (node->dir == NULL)
		node->dir = createdir_link(name);
	else
	{
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = createdir_link(name);
	}
}

int		dirnameexists(t_ls *node, char *dirname)
{
	t_dir	*tmp;
	char	*ret;

	tmp = node->dir;
	while (tmp)
	{
		ret = ft_strstr(tmp->dirnam, dirname);
		if (ret != NULL)
		{
			free(ret);
			return (1);
		}
		free(ret);
		tmp = tmp->next;
	}
	return (0);
}

t_dir	*finddir_link(t_ls *node, char *dirname)
{
	t_dir	*tmp;

	tmp = node->dir;
	while (ft_strcmp(tmp->dirnam, dirname) != 0 && tmp)
		tmp = tmp->next;
	return (tmp);
}

void	savecurdir(t_ls *node, char *dirname)
{
	DIR				*currentdir;
	struct dirent	*nextdir;
	struct stat		statinfo;
	t_dir			*cdir;

	if (dirnameexists(node, dirname) == 0)
		savedir_link(node, dirname);
	cdir = finddir_link(node, dirname);
	currentdir = opendir(dirname);
	if (currentdir == NULL)
	{
		ft_printf("opening error");
		exit(1);
	}
	while (((nextdir = readdir(currentdir)) != NULL))
	{
		stat(nextdir->d_name, &statinfo);
		savestat_link(statinfo, nextdir->d_name, cdir);
		ft_printf("going in[%ld]\n",statinfo.st_rdev);
	}
	closedir(currentdir);
}
