/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/10 12:09:59 by mbarbari          #+#    #+#             */
/*   Updated: 2015/04/10 15:59:31 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <ctype.h>
#include <libftasm.h>
#include <stdlib.h>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

void	ft_error(char *fct, char *test)
{
	printf(MAGENTA"Error for %s in the test %s"RESET"\n", fct, test);
}

int		ft_check_mem(char *lib, char *ft, int nb, int pb)
{
	int		i;

	i = -1;
	if (pb == 0)
	{
		while (++i < nb)
			if (lib[i] != ft[i])
				return (0);
	}
	else
	{
		while (++i < nb)
			if (lib[i] != ft[i])
			{
				printf("lib = %c, ft = %c\n", lib[i], ft[i]);
				return (0);
			}
	}
	return (1);
}

static void	check_ft_bzero(void)
{
	int		test = 1;
	char	lib[] = "coucou !";
	char	ft[] = "coucou !";

	bzero(lib, 0);
	ft_bzero(ft, 0);
	if (!(test = ft_check_mem(lib, ft, 9, 0)))
	{
		ft_check_mem(lib, ft, 9, 1);
		ft_error("bzero", "zero");
	}
	bzero(lib, 2);
	ft_bzero(ft, 2);
	if (!(test = ft_check_mem(lib, ft, 9, 0)))
	{
		ft_check_mem(lib, ft, 9, 1);
		ft_error("bzero", "two");
	}
	lib[0] = 'c';
	lib[1] = 'o';
	ft[0] = 'c';
	ft[1] = 'o';
	bzero(lib, 9);
	ft_bzero(ft, 9);
	if (!(test = ft_check_mem(lib, ft, 9, 0)))
	{
		ft_check_mem(lib, ft, 9, 1);
		ft_error("bzero", "simple string");
	}
	if (test)
		printf(GREEN"bzero OK"RESET"\n");
	else
		printf(RED"bzero FAIL"RESET"\n");
}

static void check_ft_strcat(void)
{
	int		test = 1;
	char	ft[20];
	char	*lib = "coucou !";
	char	*ft2;

	bzero(ft, 20);
	ft2 = ft_strcat(ft, "");
	ft2 = ft_strcat(ft, "co");
	ft2 = ft_strcat(ft, "u");
	ft2 = ft_strcat(ft, "cou");
	ft2 = ft_strcat(ft, " !");;
	if (!(test = ft_check_mem(lib, ft, 9, 1)))
	{
		ft_check_mem(lib, ft, 9, 1);
		ft_error("strcat", "function");
	}
	if (!(test = ft_check_mem(lib, ft2, 9, 1)))
	{
		ft_check_mem(lib, ft2, 9, 1);
		ft_error("strcat", "return");
	}
	if (test)
		printf(GREEN"strcat OK"RESET"\n");
	else
		printf(RED"strcat FAIL"RESET"\n");


	char	buf[9];

	bzero(buf, 9);
	ft_strcat(buf, "");
	ft_strcat(buf, "Bon");
	ft_strcat(buf, "j");
	ft_strcat(buf, "our.");
	ft_strcat(buf, "");
	if (strcmp(buf, "Bonjour.") == 0)
		printf("STRCAT OK \n");
	if (buf == ft_strcat(buf, ""))
		printf("test 2 strcat OK\n");
}

static void	check_ft_isalpha(void)
{
	int		i;
	int		test = 1;
	int		a;
	int		b;

	i = -31;
	while (++i < 350)
		if ((a = ft_isalpha(i)) != (b = isalpha(i)))
		{
			printf("i = %c, ft_ialpha=%d, isalpha=%d\n", i, a, b);
			test = 0;
		}
	if (test)
		printf(GREEN"isalpha OK"RESET"\n");
	else
		printf(RED"isalpha FAIL"RESET"\n");
}

static void	check_ft_isdigit(void)
{
	int		i;
	int		test = 1;
	int		a;
	int		b;

	i = -31;
	while (++i < 350)
		if ((a =ft_isdigit(i)) != (b = isdigit(i)))
		{
			test = 0;
			printf("i = %c, ft_isdigit=%d, isdigit= %d\n", i, a, b);
		}
	if (test)
		printf(GREEN"isdigit OK"RESET"\n");
	else
		printf(RED"isdigit FAIL"RESET"\n");
}

static void	check_ft_isalnum(void)
{
	int		i;
	int		test = 1;
	int		a;
	int		b;

	i = -31;
	while (++i < 350)
		if ((a = ft_isalnum(i)) != (b = isalnum(i)))
		{
			printf("i = %c, ft_ialnum=%d, isalnum= %d\n", i, a, b);
			test = 0;
		}
	if (test)
		printf(GREEN"isalnum OK"RESET"\n");
	else
		printf(RED"isalnum FAIL"RESET"\n");
}

static void	check_ft_isascii(void)
{
	int		i;
	int		test = 1;
	int		a;
	int		b;

	i = -31;
	while (++i < 350)
		if ((a= ft_isascii(i)) != (b =isascii(i)))
		{
			test = 0;
			printf("i = %c, ft_iascii=%d, isascii= %d\n", i, a, b);
		}
	if (test)
		printf(GREEN"isascii OK"RESET"\n");
	else
		printf(RED"isascii FAIL"RESET"\n");
}

static void	check_ft_isprint(void)
{
	int		i;
	int		test = 1;
	int		a;
	int		b;

	i = -31;
	while (++i < 350)
		if ((a = ft_isprint(i)) != (b =isprint(i)))
		{
			printf("i = %c, ft_iprint=%d, isprint= %d\n", i, a, b);
			test = 0;
		}
	if (test)
		printf(GREEN"isprint OK"RESET"\n");
	else
		printf(RED"isprint FAIL"RESET"\n");
}

static void	check_ft_toupper(void)
{
	int		i;
	int		test = 1;
	int		a;
	int		b;

	i = -31;
	while (++i < 350)
		if ((a = ft_toupper(i)) != (b = toupper(i)))
		{
			printf("i = %c, ft_toupper=%d, toupper= %d\n", i, a, b);
			test = 0;
		}
	if (test)
		printf(GREEN"toupper OK"RESET"\n");
	else
		printf(RED"toupper FAIL"RESET"\n");
}

static void	check_ft_tolower(void)
{
	int		i;
	int		test = 1;
	int		a;
	int		b;

	i = -31;
	while (++i < 350)
		if ((a = ft_tolower(i)) != (b =tolower(i)))
		{
			printf("i = %c, ft_tolower=%d, tolower= %d\n", i, a, b);
			test = 0;
		}
	if (test)
		printf(GREEN"tolower OK"RESET"\n");
	else
		printf(RED"tolower FAIL"RESET"\n");
}

static void	check_ft_putsfd(void)
{
	char	*str = NULL;
	int		a;
	int		b;
	int		test;

	test = 0;
	printf(CYAN"Begin test for puts"RESET"\n");
	printf("empty string:\n");
	b = puts("");
	a = ft_putsfd("", 1);
	if (a != b)
		test = 1;
	printf("simple string:\n");
	b = puts("coucou");
	a = ft_putsfd("coucou", 1);
	if (a != b)
		test = 1;
	printf("NULL string:\n");
	b = puts(str);
	a = ft_putsfd(str, 1);
	if (a != b)
		test = 1;
	if (test)
		printf(GREEN"tolower OK"RESET"\n");
	else
		printf(RED"tolower FAIL"RESET"\n");

	printf(CYAN"End test for puts"RESET"\n");
}


static void	check_ft_puts(void)
{
	char	*str = NULL;
	int		a;
	int		b;
	int		test;

	test = 0;
	printf(CYAN"Begin test for puts"RESET"\n");
	printf("empty string:\n");
	b = puts("");
	a = ft_puts("");
	if (a != b)
		test = 1;
	printf("simple string:\n");
	b = puts("coucou");
	a = ft_puts("coucou");
	if (a != b)
		test = 1;
	printf("NULL string:\n");
	b = puts(str);
	a = ft_puts(str);
	if (a != b)
		test = 1;
	if (test)
		printf(GREEN"tolower OK"RESET"\n");
	else
		printf(RED"tolower FAIL"RESET"\n");

	printf(CYAN"End test for puts"RESET"\n");
}

static void	check_ft_strlen(void)
{
	int		test = 1;
	char	*s1 = "";
	char	*s2 = "coucou !";
	int a;
	int b;

	if ((a = ft_strlen(s1)) != (b = strlen(s1)))
	{
		printf("ft_strlen = %d, strlen = %d\n", a, b);
		ft_error("strlen", "empty string");
		test = 0;
	}
	if ((a = ft_strlen(s2)) != (b = strlen(s2)))
	{
		printf("ft_strlen = %d, strlen = %d\n", a, b);
		ft_error("strlen", "simple string");
		test = 0;
	}
	if (test)
		printf(GREEN"strlen OK"RESET"\n");
	else
		printf(RED"strlen FAIL"RESET"\n");
}

static void	check_ft_memset(void)
{
	int		test = 1;
	char	lib[] = "coucou !";
	char	ft[] = "coucou !";
	char	*lib2;
	char	*ft2;

	lib2 = memset(lib, 'a', 0);
	ft2 = ft_memset(ft, 'a', 0);
	if (!(test = ft_check_mem(lib, ft, 9, 1)))
		ft_error("memset", "zero in function");
	if (!(test = ft_check_mem(lib2, ft2, 9, 1)))
		ft_error("memset", "zero in return");
	lib2 = memset(lib, 'a', 2);
	ft2 = ft_memset(ft, 'a', 2);
	if (!(test = ft_check_mem(lib, ft, 9, 1)))
		ft_error("memset", "two in function");
	if (!(test = ft_check_mem(lib2, ft2, 9, 1)))
		ft_error("memset", "two in return");
	lib[0] = 'c';
	lib[1] = 'o';
	ft[0] = 'c';
	ft[1] = 'o';
	lib2 = memset(lib, 'a', 9);
	ft2 = ft_memset(ft, 'a', 9);
	if (!(test = ft_check_mem(lib, ft, 9, 1)))
		ft_error("memset", "simple string in function");
	if (!(test = ft_check_mem(lib2, ft2, 9, 1)))
		ft_error("memset", "simple string in return");
	if (test)
		printf(GREEN"memset OK"RESET"\n");
	else
		printf(RED"memset FAIL"RESET"\n");
}

static void	check_ft_memcpy(void)
{
	int		test = 1;
	char	lib[] = "abcdefghijkl";
	char	ft[] = "abcdefghijkl";
	char	lib2[] = "123456789";
	char	ft2[] = "123456789";
	char	*lib3;
	char	*ft3;
	char	lib4[] = "";
	char	ft4[] = "";

	lib3 = memcpy(lib, lib2, 0);
	ft3 = ft_memcpy(ft, ft2, 0);
	if (!(test = ft_check_mem(lib, ft, 9, 1)))
		ft_error("memset", "zero in function");
	if (!(test = ft_check_mem(lib3, ft3, 9, 1)))
		ft_error("memset", "zero in return");
	lib3 = memcpy(lib, lib2, 7);
	ft3 = ft_memcpy(ft, ft2, 7);
	if (!(test = ft_check_mem(lib, ft, 9, 1)))
		ft_error("memset", "seven in function");
	if (!(test = ft_check_mem(lib3, ft3, 9, 1)))
		ft_error("memset", "seven in return");
	lib3 = memcpy(lib, lib4, 7);
	ft3 = ft_memcpy(ft, ft4, 7);
	if (!(test = ft_check_mem(lib3, ft3, 1, 1)))
		ft_error("memset", "one in return");
	if (test)
		printf(GREEN"memcpy OK"RESET"\n");
	else
		printf(RED"memcpy FAIL"RESET"\n");
}

static void	check_ft_strdup(void)
{
	int		test1;
	int		test2;
	char	*lib = strdup("");
	char	*ft = ft_strdup("");
	char	*lib2 = strdup("coucou !");
	char	*ft2 = ft_strdup("coucou !");

	if ((test1 = strcmp(lib, ft)))
		ft_error("strdup", "empty string");
	if ((test2 = strcmp(lib2, ft2)))
		ft_error("strdup", "simple string");
	if (test1 || test2)
		printf(RED"strdup FAIL"RESET"\n");
	else
		printf(GREEN"strdup OK"RESET"\n");
}

static void	check_ft_pow()
{
	int test = 0; 
	int err = 0;

	test = ft_pow(5, 3);
	if (test == 125)
	{
		test = ft_pow(10, 4);
		if (test == 10000)
		{
			test = ft_pow(10, 0);
			if (test != 1) {
				printf(RED"pow KO"RESET"\n");
				err = 1;
			}
		}
		else {
			printf(RED"pow KO"RESET"\n");
			err = 1;
		}
	}
	else {
		printf(RED"pow KO"RESET"\n");
		err = 1;
	}
	if (err == 0)
		printf(GREEN"pow OK"RESET"\n");
}

static void check_ft_strchr()
{
	char test[] = "si je dit des conneries";
	char *ret;

	ret = ft_strchr(test, 'd');
	if (strcmp(ret, "dit des conneries") == 0)
		printf(GREEN"strchr OK"RESET"\n");
	else
		printf(RED"strchr KO"RESET"\n");
}

static void check_ft_max()
{
	int test1 = 9;
	int test2 = 4;
	int reslt = 0;

	if (ft_max(4, 9) != 9)
		reslt = 1;
	if (ft_max(9, 4) != 9)
		reslt = 1;
	reslt == 0 ? printf(GREEN"Max OK"RESET"\n"), 1 : printf(RED"Max KO"RESET"\n"), 0;

}

static void check_ft_putchar(void)
{
	char i;

	i = 32;
	printf("debut des test ft_putchar\n");
	printf(" !\"#$%%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}\n");
	while (i < 126)
	{
		ft_putchar(i);
		i++;
	}
	printf("\nfin des test ft_putchar\n");
}

int			main(int ac, char **av)
{
	int		fd;

	(void)av;
	if (ac == 1)
	{
		check_ft_bzero();
		check_ft_strcat();
		check_ft_isalpha();
		check_ft_isdigit();
		check_ft_isalnum();
		check_ft_isascii();
		check_ft_isprint();
		check_ft_toupper();
		check_ft_tolower();
		check_ft_puts();
		check_ft_strlen();
		check_ft_memset();
		check_ft_memcpy();
		check_ft_strdup();
		check_ft_pow();
		check_ft_strchr();
		check_ft_max();
		check_ft_putchar();
		check_ft_putsfd();
		printf(CYAN"Test for cat on fd = -3"RESET"\n");
		ft_cat(-3);
		printf(CYAN"Begin test for cat on STDIN"RESET"\n");
		ft_cat(0);
		printf(CYAN"End test for cat on STDIN"RESET"\n");
	}
	else if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) > -1)
		{
			ft_cat(fd);
			close(fd);
		}
		else
			printf("ft_cat: %s: %s\n", av[1], strerror(errno));
	}
	else
		printf("Zero parameter for unit test or one parameter to test cat with a file.\n");
	return (0);
} 
