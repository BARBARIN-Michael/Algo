/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 14:08:56 by mbarbari          #+#    #+#             */
/*   Updated: 2014/12/05 11:15:58 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "ft_dirent.h"

/*
** ***************************************************************
** Function new_lstls create a new list with
** name of file,
** file information (confer to struct s_lstinfo in ft_dirent.h)
** ***************************************************************
*/
t_dir		*ft_new_lstls(char const *name)
{
	t_dir	*newdir;

	if (!(newdir = (t_dir *)malloc(sizeof(t_dir))))
		return (NULL);
	newdir->md_name = ft_strdup(name);
	stat(name, newdir->md_filist);
	newdir->md_rflist = NULL;
	newdir->md_ntlist = NULL;
	return (newdir);
}

/*
** ***************************************************************
** Function add_lstls link old dirent with a new directory
** ***************************************************************
*/
t_dir		**ft_add_lstls(t_dir **dirent, t_dir *newdir)
{
	if (newdir)
	{
		if (!(*dirent))
		{
			*dirent = newdir;
			return (dirent);;
		}
		newdir->md_ntlist = (void *)*dirent;
		*dirent = newdir;
	}
	return (dirent);
}

/*
** ***************************************************************
** Function add_lststat insert the the stat struct of file spell
** ***************************************************************
*/
t_dir		**ft_add_lststat(t_dir **dirent, struct stat *newstat)
{
	if (newstat)
	{
		if (!(*dirent))
			return (NULL);
		(*dirent)->md_filist = newstat;
	}
	return (dirent);
}
