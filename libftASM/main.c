/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 17:07:42 by mbarbari          #+#    #+#             */
/*   Updated: 2015/04/02 21:08:24 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include <libftasm.h>
#include <time.h>
#include <stdlib.h>

//# define BZERO
# define STRCAT

/*# define RUN_FUNC(function, ...) \
	ifdef _ # function \
		function(__VA_ARGS__); \
	endif
*/
static char s_rand(void)
{
	return (('0' + rand() % (65 - 122)));
}

static void test_bzero(int const a)
{
	int		i;
	int b = a;
	char	test[b];

	i = 0;
	while (b)
		test[b--] = 'T';
	printf("######### BZERO ###########\n\n test = \"%s\"\n", test);
	while (i < a)
	{
		ft_bzero((void *)test, a);
		i++;
	}
	printf("#########\n\n test = \"%s\"\n######### BZERO ###########\n\n", test);
}
#include <limits.h>
static void test_strcat(void)
{
	int a = 50;
	int b = 0;
	char *s1 = malloc(a + 1);
	char *s2 = malloc(a / 2 + 1);

	while (b < a / 2)
	{
		s1[b] = 'A';
		s2[b] = 'B';
		b++;
	}
	s1[a - 1] = '\0';
	s1[a ] = '\0';
	s2[a / 2 - 1] = '\0';
	//printf("######### STRCAT ###########\n\n s1 = \"%s\"\n s2 = \"%s\"", s1, s2);
	ft_strcat(s1, s2);
	//printf("#########\n\n s1 = \"%s\"\n s2 = \"%s\"\n######### STRCAT ###########\n\n", s1, s2);
}

int		main(void)
{
	#ifdef BZERO
		test_bzero(10000);
	#endif
	#ifdef STRCAT
		test_strcat();
	#endif
	return (0);

}
