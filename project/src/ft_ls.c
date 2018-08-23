/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 11:41:02 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/23 14:48:52 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	printtest(t_ls *node, t_dir *tmp)
{
	t_statinfo	*tmp2;

	while (tmp)
	{
		ft_printf("%s\n", tmp->fulldir);
		tmp2 = tmp->files;
		while (tmp2 != NULL)
		{
			if (node->l)
				ft_printf("[%s]", tmp2->permis);

			if (S_ISDIR(tmp2->stinfo.st_mode) == 1)
				ft_printf("{CYN}%*c[%s]\n", 5 ,0,tmp2->name);
			else
				ft_printf("%*c[%s]\n", 5,0 ,tmp2->name);
			tmp2 = tmp2->next;
		}
		ft_printf("\n");
		tmp = tmp->next;
	}
}

void	ft_ls(t_ls *node)
{
	t_dir	*cdir;

	savecurdir(node, node->loc);

	cdir = node->dir;
	if (node->l)
	{
		while (cdir)
		{
			setpermission(cdir);
			cdir = cdir->next;
		}
	}
	if (node->recv == 1)
		recursivesearch(node);
	else
	{
		printdir(node ,node->dir);
	}
	
	while (node->dir)
	{
		destroydir(node->dir);
		node->dir = node->dir->next;
	}
}


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