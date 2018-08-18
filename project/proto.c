/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 14:40:02 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/18 17:29:55 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>
#include <time.h>

int		main(int arc, char **arv)
{
	// time_t c;
	DIR				*currentdir;
	struct dirent	*nextdir;
	struct stat		stinfo;
	char	buf[1024];
	struct tm tm;

	currentdir = opendir("."); 	//current location
	if (currentdir == NULL)
	{
		ft_printf("null");
		exit(1);
	}
	while (((nextdir = readdir(currentdir)) != NULL))
	{
		
	
		stat(nextdir->d_name, &stinfo);
		// ft_printf("[%s]", nextdir->d_name);
		// printf("		[%lld]", stinfo.st_size);
		// printf("	[%ld]\n", stinfo.st_mtimespec.tv_sec);

		// c = strtoul( ft_lltoa(stinfo.st_mtimespec.tv_sec), NULL, 0 );
		// ctime( &c );
		memset(&tm, 0, sizeof(struct tm));
   		strptime( ft_lltoa(stinfo.st_mtimespec.tv_sec), "%s", &tm);
		strftime(buf, sizeof(buf), "%b %d %H:%M %Y", &tm);
		printf("		%s\n", buf);
		// ft_printf("[%s]\n", currentdir->);

		// ft_printf("[%s]\n", sd->d_name);
	}
	closedir(currentdir);
    return 0;
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

