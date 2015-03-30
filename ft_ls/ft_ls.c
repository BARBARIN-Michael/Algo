/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 06:35:18 by mbarbari          #+#    #+#             */
/*   Updated: 2014/12/07 04:05:09 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		process_write(v_arg arg, char *d_dir, t_dir **v_dirent)
{
	DIR				*dir;
	struct dirent	*dp;
	struct stat		lststat;

	if (!(dir = opendir(d_dir)))
	{
		ft_putendl(ft_replace("ls: %s: "ERROR_SF, "%s", (d_dir)));
		return (0);
	}
	while ((dp = readdir(dir)) != NULL)
	{
		ft_add_lstls(v_dirent, ft_new_lstls(dp->d_name));
		if ((lstat(dp->d_name, &lststat)) == -1)
			perror(ft_strjoin(dp->d_name, " process write : "));
		ft_add_lststat(v_dirent, &lststat);
		if (arg.opt_R == true && S_ISDIR(lststat.st_mode))
			process_write(arg, dp->d_name, v_dirent);
	}
	closedir(dir);
	return (1);
}

int		process_read(t_dir *dirent, v_arg arg)
{
	t_dir *dp_to_read;

	arg = arg;
	dp_to_read = dirent;
	while (dp_to_read->md_ntlist != NULL)
	{
		if (*dp_to_read->md_name == '.')
		{
		dp_to_read = (t_dir *)dp_to_read->md_ntlist;
			continue ;
		}
		if (arg.opt_l == true)
		{
			ft_putstr((const char *)process_chmod(dp_to_read));
			ft_putstr("  ");
		}
		if (!(arg.opt_a == false && *dp_to_read->md_name == '.'))
			ft_putendl_c(dp_to_read->md_name, 6);
		dp_to_read = (t_dir *)dp_to_read->md_ntlist;
	}
	return (0);
}

char	*process_chmod(t_dir *dirent)
{
	char	*chmod;
	char	*endstr;
	char	*size;
	struct stat statsave;

	size = NULL;
	stat(dirent->md_name, &statsave);
	chmod = ft_memalloc(sizeof(char *) * NBR_CHMOD + 4);
	ft_memset(chmod, ' ', NBR_CHMOD + 3);
	chmod[0] = S_ISLNK(statsave.st_mode)			? 'l' : chmod[0]  ;
	chmod[0] = S_ISCHR(statsave.st_mode)			? 'c' : chmod[0]  ;
	chmod[0] = S_ISBLK(statsave.st_mode)			? 'b' : chmod[0]  ;
	chmod[0] = S_ISFIFO(statsave.st_mode)			? 'f' : chmod[0]  ;
	chmod[0] = S_ISSOCK(statsave.st_mode)			? 'b' : chmod[0]  ;
	chmod[0] = S_ISREG(statsave.st_mode)			? '-' : chmod[0]  ;
	chmod[0] = S_ISDIR(statsave.st_mode)			? 'd' : chmod[0]  ;
	chmod[1] = statsave.st_mode & (S_IRUSR)			? 'r' : '-';
	chmod[2] = statsave.st_mode & (S_IWUSR)			? 'w' : '-';
	chmod[3] = statsave.st_mode & (S_IXUSR)			? 'x' : '-';
	chmod[4] = statsave.st_mode & (S_IRGRP)			? 'r' : '-';
	chmod[5] = statsave.st_mode & (S_IWGRP)			? 'w' : '-';
	chmod[6] = statsave.st_mode & (S_IXGRP)			? 'x' : '-';
	chmod[7] = statsave.st_mode & (S_IROTH)			? 'r' : '-';
	chmod[8] = statsave.st_mode & (S_IWOTH)			? 'w' : '-';
	chmod[9] = statsave.st_mode & (S_IXOTH)			? 'x' : '-';
	size = ft_strdup(ft_itoa(statsave.st_nlink));
	endstr = ft_strjoin(chmod, size);
	free(chmod);
	free(size);
	
	return (endstr);
}
