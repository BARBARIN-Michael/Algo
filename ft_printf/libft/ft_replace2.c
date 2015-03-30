/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 13:09:26 by mbarbari          #+#    #+#             */
/*   Updated: 2015/02/01 15:38:03 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>

char	*ft_replace(char *s1, char *mod, char *s2)
{
	char	*rslt;
	char	*st2;
	int		lenmod;

	lenmod = ft_strlen(mod);
	rslt = ft_memalloc(ft_strlen(s1) - lenmod + ft_strlen(s2) + 2);
	if (!(st2 = ft_strstr(s1, mod)))
		return (NULL);
	rslt = ft_strncat(rslt, s1, (st2 - s1));
	rslt = ft_strcat(rslt, s2);
	rslt = ft_strcat(rslt, st2 + lenmod);
	return (rslt);
}

char	*ft_nreplace(char *s1, char *mod, char *s2, size_t n)
{
	char	*rslt;
	char	*st2;
	int		lenmod;

	lenmod = ft_strlen(mod);
	rslt = ft_memalloc(ft_strlen(s1) - lenmod + ft_strlen(s2) + 2);
	if (!(st2 = ft_strnstr(s1, mod, n)))
		return (NULL);
	rslt = ft_strncat(rslt, s1, (st2 - s1));
	rslt = ft_strcat(rslt, s2);
	rslt = ft_strcat(rslt, st2 + lenmod);
	return (rslt);
}

char	*ft_n1replace(char *s1, char *mod, char *s2, size_t n)
{
	char	*rslt;
	char	*st2;
	int		lenmod;

	lenmod = ft_strlen(mod);
	if (!(rslt = ft_memalloc(ft_strlen(s1) - lenmod + ft_strlen(s2) + 1)))
		return (NULL);
	st2 = s1;
	ft_putnstr(s2, 1);
	while (n)
	{
		st2 = ft_strchr(st2, *mod) + 1;
		n--;
	}
	if (!(st2 = ft_strstr(st2, mod)))
		return (ft_strdup(s1));
	rslt = ft_strncat(rslt, s1, (st2 - s1));
	if (*s2 == '\0')
	{
		rslt = ft_strncat(rslt, s2, 1);
	}
	ft_putnstr(rslt, 10);
	rslt = ft_strcat(rslt, s2);
	rslt = ft_strcat(rslt, st2 + lenmod);
	return (rslt);
}
