/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirent.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 15:38:19 by mbarbari          #+#    #+#             */
/*   Updated: 2014/12/06 02:38:48 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DIRENT_H
# define FT_DIRENT_H

/*
** *****************************************************************************
** -----------------------------------
** Second structure is a daughter data s_lstinfo
** they content a global file data with information of option -l
** ==================
** char		*dd_chmod			is read and right and type information
** int		dd_perm				is id permission
** char		*dd_propertyName 	is name of create property
** char		*dd_plcreate 		is placecreate
** char		*dd_oweight			is weight binary
** char		*dd_date			is datetime of file modification
** ==================
** I need to sort all files by strcmp 
** If -t option, i sort files by create date
** *****************************************************************************
*/
typedef struct	s_lstinfo
{
  char		*dd_chmod;
  int		dd_perm;
  char		*dd_propertyName;
  char		*dd_plcreate;
  char		*dd_oweight;
  char		*dd_date;
}				t_info;

/*
** *****************************************************************************
** -----------------------------------
** First structure is a mother data s_lstdire
** they content a global file data
** ==================
** char *md_name
** struct s_lstinfo md_filist information of file, content global information
** struct s_lstdire md_rlist in recursive file
** struct s_lstdire md_sdlist that content a next file of this same directory
** ==================
** I need to sort all files by strcmp 
** If -t option, i sort files by create date
** *****************************************************************************
*/
typedef struct	s_lstdir
{
	char				*md_name;
	void				*md_filist;
	struct stat			*md_rflist;
	void				*md_ntlist;

}				t_dir;

#endif
