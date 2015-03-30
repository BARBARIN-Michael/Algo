/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 01:45:02 by mbarbari          #+#    #+#             */
/*   Updated: 2014/11/28 02:42:51 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>

int		main(void)
{
	char *test = "Je test %s avec ce canard";
	char *aremplacer = "de m'enculer";
	char *mod = "%s";
	char *end;

	end = ft_replace(test, mod, aremplacer);
	printf("hum : %s", end);
	return (0);
}
