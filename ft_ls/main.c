/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 11:30:48 by mbarbari          #+#    #+#             */
/*   Updated: 2014/12/07 03:58:23 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		init_struct_arg(v_arg *var, int argc)
{
	var->dir = malloc(sizeof(char *) * argc);
	var->opt_l			= false;
	var->opt_R			= false;
	var->opt_a			= false;
	var->opt_r			= false;
	var->opt_t			= false;
	var->opt_nooption	= true;
}

static	void	testing_validate_option(char *opt)
{
	char *option;

	option = ft_strdup("-lRart");
	if (ft_strchr(option, *opt) == NULL)
	{
		ft_putendl_fd(ft_replace("ls: "ERROR_OPT, "%s", opt), 2);
		ft_strdel(&option);
		exit(1);
	}
}

static v_arg	separate_validate_opt(char *opt, v_arg var)
{
	while (*opt)
	{
		testing_validate_option(opt);
		if (*opt == 'l')
			var.opt_l = true;
		else if (*opt == 'R')
			var.opt_R = true;
		else if (*opt == 'a')
			var.opt_a = true;
		else if (*opt == 'r')
			var.opt_r = true;
		else if (*opt == 't')
			var.opt_t = true;
		var.opt_nooption = false;
		opt++;
	}
	return (var);
}

static int	manage_opt_dir(int argc, int dirval, char **argv, v_arg *var)
{
	while (argc > 1)
	{
		if (*argv[argc - 1] == '-')
		{
			*var = separate_validate_opt(argv[argc - 1], *var);
			argc--;
		}
		else
		{
			if (*argv[argc - 1] != ('.' || '/'))
			{
				var->dir[dirval] = ft_strjoin("./", ft_strdup(argv[argc - 1]));
				ft_putendl(var->dir[dirval]);
			}
			else
				var->dir[dirval] = ft_strdup(argv[argc - 1]);
			dirval++;
			argc--;
		}
	}
	if (dirval == 0)
	{
		*var->dir = ft_strdup(".");
		dirval++;
	}
	return (dirval);
}

int			main(int argc, char **argv)
{
	v_arg	var;
	int		dirval;
	t_dir	*dir;
	int		rslt;
	int		rstf;
	int		cmp;

	dir = NULL;
	dirval = 0;
	rslt = 0;
	cmp = 0;
	init_struct_arg(&var, argc - 1);
	dirval = manage_opt_dir(argc, dirval, argv, &var);
	while (cmp < dirval)
	{
		if ((rslt = process_write(var, var.dir[cmp], &dir)) == true)
			process_read(dir, var);
		if (rslt == 1)
			rstf = 1;
		cmp++;
	}
	return (rstf);
}
