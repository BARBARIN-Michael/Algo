/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 17:07:42 by mbarbari          #+#    #+#             */
/*   Updated: 2015/04/03 15:08:25 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include <libftasm.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>

# define _test_bzero
# define _test_strcat

# define RUN_FUNC(FCT, ...) \
		FCT(__VA_ARGS__); \

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
	test[b] = '\0';
	while (b--)
		test[b] = 'T';
	printf("######### BZERO ###########\n\n test = \"%s\"\n", test);
	while (i < a)
	{
		ft_bzero((void *)test, a);
		i++;
	}
	printf("#########\n\n test = \"%s\"\n######### BZERO ###########\n\n", test);
}

static void test_strcat(void)
{
	int a = 5000000;
	int b = 0;
	char *s1 = malloc(a + 1);
	char *s2 = malloc(a / 2 + 1);
	char *tmp;
	char *tmp2;

	tmp = s1;
	tmp2 = s2;

	ft_bzero((void *)s1, a + 1);
	ft_bzero((void *)s2, a / 2 + 1);
	while (b < a / 2)
	{
		s1[b] = 'A';
		s2[b] = 'B';
		b++;
	}
	s1[a] = '\0';
	s2[a / 2] = '\0';
	//printf("######### STRCAT ###########\n\n s1 = \"%s\"\n s2 = \"%s\"", s1, s2);
	ft_strcat(s1, s2);
	//printf("#########\n\n s1 = \"%s\"\n s2 = \"%s\"\n######### STRCAT ###########\n\n", s1, s2);
}

static void test_isalpha(void)
{
	int c = 22;

	while (c < 123)
	{
		if (ft_isalpha(c) == 1)
			printf("%c est un alpha\n", c);
		c++;
	}
}

int		main(void)
{
	//RUN_FUNC(test_bzero, 10000);
	RUN_FUNC(test_isalpha);
	return (0);

}
