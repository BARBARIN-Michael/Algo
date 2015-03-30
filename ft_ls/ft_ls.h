/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 18:41:58 by mbarbari          #+#    #+#             */
/*   Updated: 2014/12/07 03:56:49 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include "ft_dirent.h"
#include "ft_error.h"
#include <libft.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

# define true	1
# define false	0
# define NBR_CHMOD 10
# define SI_IRMODR  00400
# define SI_IRMODW  00200
# define SI_IRMODX  00100
typedef int bool;

typedef struct	s_arg
{
	char	**dir;
	
	bool	opt_l;
	bool	opt_R;
	bool	opt_a;
	bool	opt_r;
	bool	opt_t;
	bool	opt_nooption;
}				v_arg;

t_dir		**ft_add_lststat(t_dir **dirent, struct stat *newstat);
int			process_write(v_arg arg, char *d_dir, t_dir **v_dirent);
int			process_read(t_dir *dirent, v_arg arg);
char		*process_chmod(t_dir *dirent);
t_dir		*ft_new_lstls(char const *name);
t_dir		**ft_add_lstls(t_dir **dirent, t_dir *newdir);
#endif
