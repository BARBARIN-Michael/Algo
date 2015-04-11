/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 17:07:42 by mbarbari          #+#    #+#             */
/*   Updated: 2015/04/07 11:46:14 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include <libftasm.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>
#include <fcntl.h>

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

static void test_puts(char *s)
{
	int i;
	i = ft_puts(s);
	printf("Si je lit le nbr de bit ecrit : %d\n", i);
}

static void test_memset(void *str, int c, size_t n)
{
	void *test = NULL;

	test = ft_memset((void *)str, c, n);
	printf("test : %s\n", test);
}

static void test_memcpy(void *str, size_t n)
{
	char test2[] = "si je dit des conneries";
	void *test;

	test = ft_memcpy((void *)test2, (const void *)str, n);
	printf("test : %s\n", test);
}

static void test_strdup(void)
{
	char test2[] = "si je dit des conneries";
	void *test;

	test = ft_strdup(test2);
	printf("test : %s\n", test);
}

static void test_cat(void)
{
	int fd = open("main.c", O_RDONLY);
	ft_cat(-1);
}

static void test_isdigit(void)
{
	if ((ft_isdigit(5) == 1))
		printf("test de isdigit OK\n");
}

int		main(void)
{
	char str[] = "testing function";
	//RUN_FUNC(test_bzero, 10000);
	//RUN_FUNC(test_isalpha);
	//RUN_FUNC(test_puts, "ceci n'est qu'un test");
	//RUN_FUNC(test_memset, (void *)str, 'A', 5);
	//RUN_FUNC(test_memcpy, (void *)str, 5);
	//RUN_FUNC(test_strdup);
	RUN_FUNC(test_cat);
	return (0);
}
