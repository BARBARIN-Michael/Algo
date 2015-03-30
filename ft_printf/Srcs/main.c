/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 16:09:28 by mbarbari          #+#    #+#             */
/*   Updated: 2015/02/24 19:47:05 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../libftprintf/Include///ft_printf.h"
#include <stdio.h>
#include "../libft/Include/libft.h"
#include "../libftprintf/Include/ft_printf.h"
#include <limits.h>
#include <locale.h>
#include <unistd.h>
#define TEXT1 "je test un str flag s"
#define TEXT2 "je test un int flag d"
#define TEXT3 "je test un int double flag d"
#define TEXT4 "je test un str double flag s"

int		main(int argc, const char **argv)
{
	char strflag[] = "et le flag a reussi avec un pointeur";
	char strflag2[] = "et putain le deuxieme aussi";
	int i42 = 42;
	int resltft;
	int reslt;
	unsigned long ul1 = 4294967295;
	char c = 'a';
	char c2 = 'b';

	setlocale(LC_ALL, "en_US.UTF-8");
	if (argc == 1)
		return (0);
	reslt = 0;
	resltft = 0;
	if ((strcmp(argv[1], "str") == 0) || (strcmp(argv[1], "all") == 0))
	{
		printf(C_GREEN"\n\n#####################  "C_BROWN"cst"C_GREEN"  #####################"C_NONE"\n");
		reslt += printf(C_RED"   PRINTF -----> "C_NONE"je test un str de base \n");
		resltft += ft_printf(C_RED"ft_printf -----> "C_NONE"je test un str de base \n");
		resltft += ft_printf(C_RED"ft_printf -----> "C_NONE"je test un str ""cumule d'un autre str\n");
		reslt += printf(C_RED"   PRINTF -----> "C_NONE"je test un str ""cumule d'un autre str\n");
		if (resltft == reslt)
			ft_putendl_c("reslt "C_GREEN"OK", "cyan");
		else
		{
			ft_putendl_c("reslt "C_RED"KO", "cyan");
			printf("FT_PRINTF return %d\n", resltft);
			printf("printf return %d\n", reslt);
		}
	}

	reslt = 0;
	resltft = 0;
	if ((strcmp(argv[1], "ptr") == 0) || (strcmp(argv[1], "all") == 0))
	{
		printf(C_GREEN"\n\n#####################  "C_BROWN"ptr"C_GREEN"  #####################"C_NONE"\n");
		// str de base
		reslt += printf(C_RED"   PRINTF ----> "C_NONE"petit ptr int : %p\n", &i42);
		resltft += ft_printf(C_RED"FT_PRINTF ----> "C_NONE"petit ptr int : %p\n", &i42);
		reslt += printf(C_RED"   PRINTF ----> "C_NONE"petit ptr char : %p\n", &c);
		resltft += ft_printf(C_RED"FT_PRINTF ----> "C_NONE"petit ptr char : %p\n", &c);
		reslt += printf(C_RED"   PRINTF ----> "C_NONE"ptr char* : %p\n", strflag);
		resltft += ft_printf(C_RED"FT_PRINTF ----> "C_NONE"ptr char* : %p\n", strflag);
		reslt += printf(C_RED"   PRINTF ----> "C_NONE"ptr char* : %p\n", 0);
		resltft += ft_printf(C_RED"FT_PRINTF ----> "C_NONE"ptr char* : %p\n", 0);
		reslt += printf(C_RED"   PRINTF ----> "C_NONE"ptr char* : %05p\n", 0);
		resltft += ft_printf(C_RED"FT_PRINTF ----> "C_NONE"ptr char* : %05p\n", 0);
		if (resltft  == reslt)
			ft_putendl_c("reslt "C_GREEN"OK", "cyan");
		else
		{
			ft_putendl_c("reslt "C_RED"KO", "cyan");
			printf("FT_PRINTF return %d\n", resltft);
			printf("printf return %d\n", reslt);
		}
	}
	reslt = 0;
	resltft = 0;
	if ((strcmp(argv[1], "str v2") == 0) || (strcmp(argv[1], "all") == 0))
	{
		printf(C_GREEN"\n\n#####################  "C_BROWN"str v2"C_GREEN"  #####################"C_NONE"\n");
		// str de base
		reslt += printf(C_RED"   PRINTF ----> "C_CYAN"Test 1 "C_NONE""TEXT1" %s \n", "et le flag a reussi avec un const str");
		resltft += ft_printf(C_RED"ft_printf ----> "C_CYAN"Test 1 "C_NONE""TEXT1" %s \n", "et le flag a reussi avec un const str");
		reslt += printf(C_RED"   PRINTF ----> "C_CYAN"Test 2 "C_NONE""TEXT4" %s et %s\n", strflag, strflag2);
		resltft += ft_printf(C_RED"ft_printf ----> "C_CYAN"Test 2 "C_NONE""TEXT4" %s et %s\n", strflag, strflag2);
		reslt += printf(C_RED"   PRINTF ----> "C_CYAN"Test 3 "C_NONE""TEXT4" %s%s%s%s%s%s%s%s%s%s\n", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10");
		resltft += ft_printf(C_RED"ft_printf ----> "C_CYAN"Test 3 "C_NONE""TEXT4" %s%s%s%s%s%s%s%s%s%s\n", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10");
		if (resltft == reslt)
			ft_putendl_c("reslt "C_GREEN"OK", "cyan");
		else
		{
			ft_putendl_c("reslt "C_RED"KO", "cyan");
			printf("FT_PRINTF return %d\n", resltft);
			printf("printf return %d\n", reslt);
		}
	}
	reslt = 0;
	resltft = 0;
	if ((argc == 3 && strcmp(argv[1], "int 2") == 0) || (strcmp(argv[1], "all") == 0))
	{
		printf(C_GREEN"\n\n#####################  "C_BROWN"int 2"C_GREEN"  #####################"C_NONE"\n");
		// str de base
		reslt += printf(C_RED"   PRINTF ----> "C_NONE""TEXT2" %d \n", 42);
		resltft += ft_printf(C_RED"FT_PRINTF ----> "C_NONE""TEXT2" %d \n", 42);
		reslt += printf(C_RED"   PRINTF ----> "C_NONE""TEXT2" %d \n", i42);
		resltft += ft_printf(C_RED"FT_PRINTF ----> "C_NONE""TEXT2" %d \n", i42);
		reslt += printf(C_RED"   PRINTF ----> "C_NONE""TEXT3" %d et %d\n", i42, i42);
		resltft += ft_printf(C_RED"FT_PRINTF ----> "C_NONE""TEXT3" %d et %d\n", i42, i42);
		reslt += printf(C_RED"   PRINTF ----> "C_NONE""TEXT3" %d et %det %d\n", i42, i42, i42);
		resltft += ft_printf(C_RED"FT_PRINTF ----> "C_NONE""TEXT3" %d et %det %d\n", i42, i42, i42);
		if (resltft  == reslt)
			ft_putendl_c("reslt "C_GREEN"OK", "cyan");
		else
		{
			ft_putendl_c("reslt "C_RED"KO", "cyan");
			printf("FT_PRINTF return %d\n", resltft);
			printf("printf return %d\n", reslt);
		}
	}
	reslt = 0;
	resltft = 0;
	if ((argc == 2 && strcmp(argv[1], "hex") == 0) || (strcmp(argv[1], "all") == 0))
	{
		printf(C_GREEN"\n\n#####################  "C_BROWN"hex"C_GREEN"  #####################"C_NONE"\n");
		// str de base
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 1 "C_NONE"une valeur hexa 1234 = %x et %X\n", 1234, 1234);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 1 "C_NONE"une valeur hexa 1234 = %x et %X\n", 1234, 1234);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 2 "C_NONE"une valeur hexa 4294967295 = %x et %X\n", ul1, ul1);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 2 "C_NONE"une valeur hexa 4294967295 = %x et %X\n", ul1, ul1);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 3 "C_NONE"une valeur hexa 4294967296 = %x et %X\n", 4294967296 , 4294967296 );
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 3 "C_NONE"une valeur hexa 4294967296 = %x et %X\n", 4294967296, 4294967296 );
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 4 "C_NONE"une valeur hexa -456 = %x et %X\n", -456 , -456 );
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 4 "C_NONE"une valeur hexa -456 = %x et %X\n", -456 , -456 );
		ft_printf(C_RED"   PRINTF -----> "C_CYAN"test 5 "C_NONE"une valeur binaire {101} devrais donner 01100101 =  %b\n", 101 );
		if (resltft  == reslt)
			ft_putendl_c("reslt "C_GREEN"OK", "cyan");
		else
		{
			ft_putendl_c("reslt "C_RED"KO", "cyan");
			printf("FT_PRINTF return %d\n", resltft);
			printf("printf return %d\n", reslt);
		}
	}
	reslt = 0;
	resltft = 0;
	if ((argc == 2 && strcmp(argv[1], "%%") == 0) || (strcmp(argv[1], "all") == 0))
	{
		printf(C_GREEN"\n\n#####################  "C_BROWN"%%%%"C_GREEN"  #####################"C_NONE"\n");
		printf(C_BROWN"######   DEB - Petit test avec \"%%\" :   #####"C_NONE"\n");
		reslt += printf(C_RED"   PRINTF"C_NONE" %\n");
		resltft += ft_printf(C_RED"FT_PRINTF"C_NONE" %\n");
		reslt += printf(C_RED"   PRINTF"C_NONE" {%}\n");
		resltft += ft_printf(C_RED"FT_PRINTF"C_NONE" {%}\n");
		reslt += printf(C_RED"   PRINTF"C_NONE" {% %}\n");
		resltft += ft_printf(C_RED"FT_PRINTF"C_NONE" {% %}\n");
		printf(C_BROWN"######   FIN - Petit test avec \"%%\" :    #####"C_NONE"\n");
		reslt += printf(C_RED"   PRINTF ----> "C_CYAN"test 0"C_NONE" je test pour pouvoir ecrire % Zdans mon code\n");
		resltft += ft_printf(C_RED"FT_PRINTF ----> "C_CYAN"test 0"C_NONE" je test pour pouvoir ecrire % Zdans mon code\n");
		reslt += printf(C_RED"   PRINTF ----> "C_CYAN"test 1"C_NONE" je test pour pouvoir ecrire %% dans mon code\n");
		resltft += ft_printf(C_RED"FT_PRINTF ----> "C_CYAN"test 1"C_NONE" je test pour pouvoir ecrire %% dans mon code\n");

		reslt += printf(C_RED"   PRINTF ----> "C_CYAN"test 2"C_NONE" je test pour pouvoir ecrire %% dans mon %deme code\n", 2);
		resltft += ft_printf(C_RED"FT_PRINTF ----> "C_CYAN"test 2"C_NONE" je test pour pouvoir ecrire %% dans mon %deme code\n", 2);
		
		reslt += printf(C_RED"   PRINTF ----> "C_CYAN"test 3"C_NONE" je test pour pouvoir ecrire %d %% dans mon %deme code\n", 1, 2);
		resltft += ft_printf(C_RED"FT_PRINTF ----> "C_CYAN"test 3"C_NONE" je test pour pouvoir ecrire %d %% dans mon %deme code\n", 1, 2);
		
		reslt += printf(C_RED"   PRINTF ----> "C_CYAN"test 4"C_NONE" je test pour pouvoir ecrire %d %% et %% dans mon %deme code\n", 2, 2);
		resltft += ft_printf(C_RED"FT_PRINTF ----> "C_CYAN"test 4"C_NONE" je test pour pouvoir ecrire %d %% et %% dans mon %deme code\n", 2, 2, 3, 4);
		
		reslt += printf(C_RED"   PRINTF ----> "C_CYAN"test 5"C_NONE" je test pour pouvoir ecrire %d %%.4s et %% dans mon %deme code\n", 2, 2);
		resltft += ft_printf(C_RED"FT_PRINTF ----> "C_CYAN"test 5"C_NONE" je test pour pouvoir ecrire %d %%.4s et %% dans mon %deme code\n", 2, 2);
		reslt += printf(C_RED"   PRINTF ----> "C_CYAN"test 5"C_NONE" je test %05.% \n", 2, 2);
		resltft += ft_printf(C_RED"FT_PRINTF ----> "C_CYAN"test 5"C_NONE" je test %05.% \n", 2, 2);
		reslt += printf(C_RED"   PRINTF ----> "C_CYAN"test 5"C_NONE" je test %.3% \n", 2, 2);
		resltft += ft_printf(C_RED"FT_PRINTF ----> "C_CYAN"test 5"C_NONE" je test %.3% \n", 2, 2);
		if (resltft  == reslt)
			ft_putendl_c("reslt "C_GREEN"OK", "cyan");
		else
		{
			ft_putendl_c("\nreslt "C_RED"KO", "cyan");
			printf("FT_PRINTF return %d\n", resltft);
			printf("printf return %d\n", reslt);
		}
	}
	reslt = 0;
	resltft = 0;
	if ((argc == 2 && strcmp(argv[1], "char") == 0) || (strcmp(argv[1], "all") == 0))
	{
		printf(C_GREEN"\n\n#####################  "C_BROWN"char"C_GREEN"  #####################"C_NONE"\n");
		reslt += printf(C_RED"   PRINTF ----> "C_CYAN"test 1 "C_NONE"je test pour pouvoir ecrire %c dans mon code\n", 'c');
		resltft += ft_printf(C_RED"FT_PRINTF ----> "C_CYAN"test 1 "C_NONE"je test pour pouvoir ecrire %c dans mon code\n", 'c');
		reslt += printf(C_RED"   PRINTF ----> "C_CYAN"test 2 "C_NONE"je test pour pouvoir ecrire %c dans %c mon code\n", 'c', 'd');
		resltft += ft_printf(C_RED"FT_PRINTF ----> "C_CYAN"test 2 "C_NONE"je test pour pouvoir ecrire %c dans %c mon code\n", 'c', 'd');
		reslt += printf(C_RED"   PRINTF ----> "C_CYAN"test 3 "C_NONE"%c est ecrit\n", '\0');
		resltft += ft_printf(C_RED"FT_PRINTF ----> "C_CYAN"test 3 "C_NONE"%c est ecrit\n", '\0');
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 4 "C_NONE"{%c}\n", 0);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 4 "C_NONE"{%c}\n", 0);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 5 "C_NONE"{%3c}\n", 0);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 5 "C_NONE"{%3c}\n", 0);
		if (resltft  == reslt)
			ft_putendl_c("reslt "C_GREEN"OK", "cyan");
		else
		{
			ft_putendl_c("reslt "C_RED"KO", "cyan");
			printf("FT_PRINTF return %d\n", resltft);
			printf("printf return %d\n", reslt);
		}
	}
	reslt = 0;
	resltft = 0;
	if ((argc == 2 && strcmp(argv[1], "uint") == 0) || (strcmp(argv[1], "all") == 0))
	{
		printf(C_GREEN"\n\n#####################  "C_BROWN"uint"C_GREEN"  #####################"C_NONE"\n");
		reslt += printf(C_RED"   PRINTF ----> "C_CYAN"test 1 "C_NONE"j'ecrit un premier ui %u dans mon code\n", 200);
		resltft += ft_printf(C_RED"FT_PRINTF ----> "C_CYAN"test 1 "C_NONE"j'ecrit un premier ui %u dans mon code\n", 200);
		reslt += printf(C_RED"   PRINTF ----> "C_CYAN"test 2 "C_NONE"j'ecrit un ui max %u dans mon code\n", ul1);
		resltft += ft_printf(C_RED"FT_PRINTF ----> "C_CYAN"test 2 "C_NONE"j'ecrit un ui max %u dans mon code\n", ul1);
		reslt += printf(C_RED"   PRINTF ----> "C_CYAN"test 3 "C_NONE"j'ecrit un ui qui ne devrai pas exister %u dans mon code\n", 4294967296);
		resltft += ft_printf(C_RED"FT_PRINTF ----> "C_CYAN"test 3 "C_NONE"j'ecrit un ui qui ne devrai pas exister %u dans mon code\n", 4294967296);
		reslt += printf(C_RED"   PRINTF ----> "C_CYAN"test 4 "C_NONE"j'ecrit un ui negatif (aille aille aille) %u dans mon code\n", -650);
		resltft += ft_printf(C_RED"FT_PRINTF ----> "C_CYAN"test 4 "C_NONE"j'ecrit un ui negatif (aille aille aille) %u dans mon code\n", -650);
		if (resltft  == reslt)
			ft_putendl_c("reslt "C_GREEN"OK", "cyan");
		else
		{
			ft_putendl_c("reslt "C_RED"KO", "cyan");
			printf("FT_PRINTF return %d\n", resltft);
			printf("printf return %d\n", reslt);
		}
	}
	reslt = 0;
	resltft = 0;
	if ((argc == 2 && strcmp(argv[1], "oct") == 0) || (strcmp(argv[1], "all") == 0))
	{
		printf(C_GREEN"\n\n#####################  "C_BROWN"oct"C_GREEN"  #####################"C_NONE"\n");
		reslt += printf(C_RED"   PRINTF ----> "C_CYAN"test 1 "C_NONE"j'ecrit un premier octal %o dans mon code\n", 10110010);
		resltft += ft_printf(C_RED"FT_PRINTF ----> "C_CYAN"test 1 "C_NONE"j'ecrit un premier octal %o dans mon code\n", 10110010);
		reslt += printf(C_RED"   PRINTF ----> "C_CYAN"test 2 "C_NONE"j'ecrit deux octal %o et %o dans mon code\n", 10110010, 1111111);
		resltft += ft_printf(C_RED"FT_PRINTF ----> "C_CYAN"test 2 "C_NONE"j'ecrit deux octal %o et %o dans mon code\n", 10110010, 1111111);
		reslt += printf(C_RED"   PRINTF ----> "C_CYAN"test 3 "C_NONE"j'ecrit un octal max %o dans mon code\n", 1010111100);
		resltft += ft_printf(C_RED"FT_PRINTF ----> "C_CYAN"test 3 "C_NONE"j'ecrit un octal max %o dans mon code\n", 1010111100);
		reslt += printf(C_RED"   PRINTF ----> "C_CYAN"test 4 "C_NONE"j'ecrit un octal qui ne devrai pas exister %o dans mon code\n", ul1);
		resltft += ft_printf(C_RED"FT_PRINTF ----> "C_CYAN"test 4 "C_NONE"j'ecrit un octal qui ne devrai pas exister %o dans mon code\n", ul1);
		reslt += printf(C_RED"   PRINTF ----> "C_CYAN"test 5 "C_NONE"j'ecrit un 2e octal qui ne devrai pas exister %o dans mon code\n", 4294967296);
		resltft += ft_printf(C_RED"FT_PRINTF ----> "C_CYAN"test 5 "C_NONE"j'ecrit un 2e octal qui ne devrai pas exister %o dans mon code\n", 4294967296);
		reslt += printf(C_RED"   PRINTF ----> "C_CYAN"test 6 "C_NONE"j'ecrit un octal qui est negatif (aille aille aille) %o dans mon code\n", -1234);
		resltft += ft_printf(C_RED"FT_PRINTF ----> "C_CYAN"test 6 "C_NONE"j'ecrit un octal qui est negatif (aille aille aille) %o dans mon code\n", -1234);
		if (resltft  == reslt)
			ft_putendl_c("reslt "C_GREEN"OK", "cyan");
		else
		{
			ft_putendl_c("reslt "C_RED"KO", "cyan");
			printf("FT_PRINTF return %d\n", resltft);
			printf("printf return %d\n", reslt);
		}
	}
	reslt = 0;
	resltft = 0;
	if (argc == 2 && (strcmp(argv[1], "str2") == 0) || (strcmp(argv[1], "all") == 0))
	{
		printf(C_GREEN"\n\n#####################  "C_BROWN"str2"C_GREEN"  #####################"C_NONE"\n");
		char	strstr2[] = "je test un str formate par des options";
		// str de base
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 1 "C_NONE"%s \"Bonj\" %%.4s: %.4s \n", strstr2, "Bonjour mon ami");
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 1 "C_NONE"%s \"Bonj\" %%.4s: %.4s \n", strstr2, "Bonjour mon ami");
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 2 "C_NONE"%s \"Bonj\" %%.4s: %.4s et je re %%.5s %.5s \n", strstr2, "Bonjour mon ami", strflag);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 2 "C_NONE"%s \"Bonj\" %%.4s: %.4s et je re %%.5s %.5s \n", strstr2, "Bonjour mon ami", strflag);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 3 "C_NONE"%s \"Bonj\" %%14.4s: %14.4s\n", strstr2, "Bonjour mon ami");
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 3 "C_NONE"%s \"Bonj\" %%14.4s: %14.4s\n", strstr2, "Bonjour mon ami");
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 4 "C_NONE"%s \"Bonj\" %%014.4s: %014.4s\n", strstr2, "Bonjour mon ami");
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 4 "C_NONE"%s \"Bonj\" %%014.4s: %014.4s\n", strstr2, "Bonjour mon ami");
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 5 "C_NONE"%s \"Bonj\" %%-10.4s: %-5.4s\n", strstr2, "Bonjour mon ami");
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 5 "C_NONE"%s \"Bonj\" %%-10.4s: %-5.4s\n", strstr2, "Bonjour mon ami");
		if (resltft  == reslt)
			ft_putendl_c("reslt "C_GREEN"OK", "cyan");
		else
		{
			ft_putendl_c("reslt "C_RED"KO", "cyan");
			printf("FT_PRINTF return %d\n", resltft);
			printf("printf return %d\n", reslt);
		}
	}
	reslt = 0;
	resltft = 0;
	if (argc == 2 && (strcmp(argv[1], "int2") == 0) || (strcmp(argv[1], "all") == 0))
	{
		printf(C_GREEN"\n\n#####################  "C_BROWN"int2"C_GREEN"  #####################"C_NONE"\n");
		char	strstr2[] = "je test un str formate par des options";
		// str de base
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 1 "C_NONE"{%12d}\n", 10000);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 1 "C_NONE"{%12d}\n", 10000);
		if (resltft  == reslt)
			ft_putendl_c("reslt "C_GREEN"OK", "cyan");
		else
		{
			ft_putendl_c("reslt "C_RED"KO", "cyan");
			printf("FT_PRINTF return %d\n", resltft);
			printf("printf return %d\n", reslt);
		}
	}
	reslt = 0;
	resltft = 0;
	if (argc == 2 && (strcmp(argv[1], "D-O-U") == 0) || (strcmp(argv[1], "all") == 0))
	{
		printf(C_GREEN"\n\n#####################  "C_BROWN"D-O-U"C_GREEN"  #####################"C_NONE"\n");
		char	strstr2[] = "test d'un D : ";
		// str de base
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 1 "C_NONE"%s %D\n", strstr2, 4567);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 1 "C_NONE"%s %D\n", strstr2, 4567);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 2 "C_NONE"%s %D\n", strstr2, 0L);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 2 "C_NONE"%s %D\n", strstr2, 0L);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 3 "C_NONE"%s %D\n", strstr2, 1L);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 3 "C_NONE"%s %D\n", strstr2, 1L);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 4 "C_NONE"%s %D\n", strstr2, 42L);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 4 "C_NONE"%s %D\n", strstr2, 42L);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 5 "C_NONE"%s %D\n", strstr2, -1L);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 5 "C_NONE"%s %D\n", strstr2, -1L);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 6 "C_NONE"%s %D\n", strstr2, LONG_MAX);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 6 "C_NONE"%s %D\n", strstr2, LONG_MAX);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 7 "C_NONE"%s %D\n", strstr2, LONG_MIN);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 7 "C_NONE"%s %D\n", strstr2, LONG_MIN);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 8 "C_NONE"%sO %O\n", strstr2, 1);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 8 "C_NONE"%sO %O\n", strstr2, 1);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 9 "C_NONE"%sO %O\n", strstr2, 100);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 9 "C_NONE"%sO %O\n", strstr2, 100);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 10 "C_NONE"%sO %O\n", strstr2, 999);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 10 "C_NONE"%sO %O\n", strstr2, 999);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 11 "C_NONE"%sO %O\n", strstr2, 999988888);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 11 "C_NONE"%sO %O\n", strstr2, 999988888);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 11 "C_NONE"%sO %O%O%O%O%O%O\n", strstr2, 1, 100, 999, 42, 999988888, 1);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 11 "C_NONE"%sO %O%O%O%O%O%O\n", strstr2, 1, 100, 999, 42,  999988888, 1);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 12 "C_NONE"%sU %U\n", strstr2, LONG_MAX / 2);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 12 "C_NONE"%sU %U\n", strstr2, LONG_MAX / 2);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 13 "C_NONE"%sU %U\n", strstr2, ULONG_MAX);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 13 "C_NONE"%sU %U\n", strstr2, ULONG_MAX);
		if (resltft  == reslt)
			ft_putendl_c("reslt "C_GREEN"OK", "cyan");
		else
		{
			ft_putendl_c("reslt "C_RED"KO", "cyan");
			printf("FT_PRINTF return %d\n", resltft);
			printf("printf return %d\n", reslt);
		}
	}
	reslt = 0;
	resltft = 0;
	if (argc == 2 && (strcmp(argv[1], "S-C") == 0) || (strcmp(argv[1], "all") == 0))
	{
		printf(C_GREEN"\n\n#####################  "C_BROWN"S-C"C_GREEN"  #####################"C_NONE"\n");
		char	strstr2[] = "test d'un  : ";
		// str de base
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 0 "C_NONE"%sC %C \n", strstr2, 206);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 0 "C_NONE"%sC %C \n", strstr2, 206);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 0.1 "C_NONE"%slc %lc\n", strstr2, L'米');
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 0.1 "C_NONE"%slc %lc\n", strstr2, L'米');
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 0bis "C_NONE"%sC avec \\0 %C ici et ailleur\n", strstr2, 0);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 0bis "C_NONE"%sC avec \\0 %C ici et ailleur\n", strstr2, 0);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 1 "C_NONE"%sS %S \n", strstr2, L"米");
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 1 "C_NONE"%sS %S \n", strstr2, L"米");
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 1bis "C_NONE"%sS %S \n", strstr2, L"T̗͈̪͈o̜̦͎͝ ̖̣̺̦̳͓͟i̡̻̝̳̠̮̞ͅn̼͈͓͕͚͡v̥́o̝̻̟͖̣̠k̵̦̙̳͙̼̤ͅe̡̘ ͎̮̹̮͉̠th̤͉͉̘̦͜ͅe ̶͙͎̦͙h̘͈͎i̢̮̫̼v̧̤̻e̬͕̰͢-̟͉̜̘͓̭͚m̫ì̳͇n̢̺d̨̥̰̗̲̞̝ ̫r̢ḙ̘̮̫͕͖̞͠p͔̮͚̝͈r͏̙̤e̷̦̼s̡͙͈e̲̳̥̞n̤̱͝ṭ͍͈͡ͅi̧͓͇̗̥̳̮̻n҉̤͓̳͈g͈͎͎͝ ͖̫c̩̼̗h̩͉͘a̜̟͍o̷͔̖̟s̪͟");
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 1bis "C_NONE"%sS %S \n", strstr2, L"T̗͈̪͈o̜̦͎͝ ̖̣̺̦̳͓͟i̡̻̝̳̠̮̞ͅn̼͈͓͕͚͡v̥́o̝̻̟͖̣̠k̵̦̙̳͙̼̤ͅe̡̘ ͎̮̹̮͉̠th̤͉͉̘̦͜ͅe ̶͙͎̦͙h̘͈͎i̢̮̫̼v̧̤̻e̬͕̰͢-̟͉̜̘͓̭͚m̫ì̳͇n̢̺d̨̥̰̗̲̞̝ ̫r̢ḙ̘̮̫͕͖̞͠p͔̮͚̝͈r͏̙̤e̷̦̼s̡͙͈e̲̳̥̞n̤̱͝ṭ͍͈͡ͅi̧͓͇̗̥̳̮̻n҉̤͓̳͈g͈͎͎͝ ͖̫c̩̼̗h̩͉͘a̜̟͍o̷͔̖̟s̪͟");
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 1ter "C_NONE"%sS %S \n", strstr2, L"");
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 1ter "C_NONE"%sS %S \n", strstr2, L"");
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 2"C_NONE" %S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S\n", L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ", L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 2"C_NONE" %S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S\n", L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ", L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 2"C_NONE" %.10S\n", L"αBBBBBB β Γ γ Δ δ Ε ε Ζ ζ");
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 2"C_NONE" %.10S\n", L"αBBBBBB β Γ γ Δ δ Ε ε Ζ ζ");
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 2.2"C_NONE" %4.15S\n", L"我是一只猫。");
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 2.2"C_NONE" %4.15S\n", L"我是一只猫。");
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 3 "C_NONE"%shhC %hhC et %hhC\n", strstr2, 0, L'米');
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 3 "C_NONE"%shhC %c et %C\n", strstr2, 0, L'米');
		if (resltft  == reslt)
			ft_putendl_c("reslt "C_GREEN"OK", "cyan");
		else
		{
			printf(C_CYAN"\nreslt "C_RED"KO\n");
			printf("\tFT_PRINTF return %d\n", resltft);
			printf("\tprintf return %d\n", reslt);
		}
	}
	reslt = 0;
	resltft = 0;
	if (argc == 2 && (strcmp(argv[1], "spec") == 0) || (strcmp(argv[1], "all") == 0))
	{
		printf(C_GREEN"\n\n#####################  "C_BROWN"spec"C_GREEN"  #####################"C_NONE"\n");
		char	strstr2[] = "test d'un D : ";
		// str de base
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 1 "C_NONE"%s %C %d %p %x %S\n", "bonjour ", L'該', 42, &strstr2, 42,L"لحم خنزير");
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 1 "C_NONE"%s %C %d %p %x %S\n", "bonjour ", L'該', 42, &strstr2, 42, L"لحم خنزير");
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 1 "C_NONE"%s %C %d %p %x %% %S\n", "bonjour ", L'該', 42, &strstr2, 42, L"لحم خنزير");
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 1 "C_NONE"%s %C %d %p %x %% %S\n", "bonjour ", L'該', 42, &strstr2, 42, L"لحم خنزير");
		if (resltft  == reslt)
			ft_putendl_c("reslt "C_GREEN"OK", "cyan");
		else
		{
			ft_putendl_c("reslt "C_RED"KO", "cyan");
			printf("FT_PRINTF return %d\n", resltft);
			printf("printf return %d\n", reslt);
		}
	}
	reslt = 0;
	resltft = 0;
	if (argc == 2 && (strcmp(argv[1], "spec2") == 0) || (strcmp(argv[1], "all") == 0))
	{
		printf(C_GREEN"\n\n#####################  "C_BROWN"spec2 "C_GREEN" #####################"C_NONE"\n");
		char	strstr2[] = "test d'un D : ";
		char *shghkh = NULL;
		// str de base
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 1 "C_NONE"{%-13p}\n", NULL);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 1 "C_NONE"{%-13p}\n", NULL);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 2 {%10R}\n", NULL);
		resltft += ft_printf(C_RED"   PRINTF -----> "C_CYAN"test 2 {%10R}\n", NULL);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 3 "C_NONE"{%-50Z}\n", NULL);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 3 "C_NONE"{%-50Z}\n", NULL);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 4 "C_NONE"{%50S}\n", L"لحم خنزيرلحم خنزيرلحم خنزيرلحم خنزير");
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 4 "C_NONE"{%50S}\n", L"لحم خنزيرلحم خنزيرلحم خنزيرلحم خنزير");
		if (resltft  == reslt)
			ft_putendl_c("reslt "C_GREEN"OK", "cyan");
		else
		{
			ft_putendl_c("reslt "C_RED"KO", "cyan");
			printf("FT_PRINTF return %d\n", resltft);
			printf("printf return %d\n", reslt);
		}
	}
	reslt = 0;
	resltft = 0;
	if (argc == 2 && (strcmp(argv[1], "l") == 0) || (strcmp(argv[1], "all") == 0))
	{
		printf(C_GREEN"\n\n#####################  "C_BROWN"l"C_GREEN"  #####################"C_NONE"\n");
		char	strstr2[] = "test d'un D : ";
		// str de base
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 1 "C_NONE"%lD, %lD\n", 0, USHRT_MAX);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 1 "C_NONE"%lD, %lD\n", 0, USHRT_MAX);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 2 "C_NONE"%lX, %lX\n", 0, ULONG_MAX);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 2 "C_NONE"%lX, %lX\n", 0, ULONG_MAX);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 3 "C_NONE"%lc, %lc\n", L"ل", L'該');
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 3 "C_NONE"%lc, %lc\n", L"ل", L'該');
		if (resltft  == reslt)
			ft_putendl_c("reslt "C_GREEN"OK", "cyan");
		else
		{
			ft_putendl_c("reslt "C_RED"KO", "cyan");
			printf("FT_PRINTF return %d\n", resltft);
			printf("printf return %d\n", reslt);
		}
	}
	reslt = 0;
	resltft = 0;
	if (argc == 2 && (strcmp(argv[1], "ll") == 0) || (strcmp(argv[1], "all") == 0))
	{
		printf(C_GREEN"\n\n#####################  "C_BROWN"ll"C_GREEN"  #####################"C_NONE"\n");
		char	strstr2[] = "test d'un D : ";
		// str de base
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 1 "C_NONE"%llO, %llO\n", 0, USHRT_MAX);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 1 "C_NONE"%llO, %llO\n", 0, USHRT_MAX);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 1 "C_NONE"%lld, %lld\n", 0, 42);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 1 "C_NONE"%lld, %lld\n", 0, 42);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 2 "C_NONE"%llX, %llX\n", 0, ULLONG_MAX);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 2 "C_NONE"%llX, %llX\n", 0, ULLONG_MAX);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 3 "C_NONE"%llu, %llu\n", 0, ULLONG_MAX);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 3 "C_NONE"%llu, %llu\n", 0, ULLONG_MAX);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 3 "C_NONE"%ld\n", (long)INT_MAX + 1);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 3 "C_NONE"%ld\n", (long)INT_MAX + 1);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 4 "C_NONE"%hhu, %hhu\n", 0, UCHAR_MAX + 42);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 4 "C_NONE"%hhu, %hhu\n",0,  UCHAR_MAX + 42);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 5 "C_NONE"%zd \n", LLONG_MAX);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 5 "C_NONE"%zd \n", LLONG_MAX);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 6 "C_NONE"%zu \n", ULLONG_MAX);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 6 "C_NONE"%zu \n", ULLONG_MAX);
		if (resltft  == reslt)
			ft_putendl_c("reslt "C_GREEN"OK", "cyan");
		else
		{
			ft_putendl_c("reslt "C_RED"KO", "cyan");
			printf("FT_PRINTF return %d\n", resltft);
			printf("printf return %d\n", reslt);
		}
	}
	reslt = 0;
	resltft = 0;
	if (argc == 2 && (strcmp(argv[1], "#") == 0) || (strcmp(argv[1], "all") == 0))
	{
		printf(C_GREEN"\n\n#####################  "C_BROWN"#"C_GREEN"  #####################"C_NONE"\n");
		char	strstr2[] = "test d'un # : ";
		// str de base
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 1 "C_NONE"%#o\n", 42);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 1 "C_NONE"%#o\n", 42);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 2 "C_NONE"%#o\n", 0);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 2 "C_NONE"%#o\n", 0);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 3 "C_NONE"%#o\n", INT_MAX);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 3 "C_NONE"%#o\n", INT_MAX);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 4 "C_NONE"%#O\n", 1);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 4 "C_NONE"%#O\n", 1);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 5 "C_NONE"%#x\n", 0);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 5 "C_NONE"%#x\n", 0);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 6 "C_NONE"%#.x et %#.0x\n", 0, 0);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 6 "C_NONE"%#.x et %#.0x\n", 0, 0);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 7 "C_NONE"%#.5x\n", 1);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 7 "C_NONE"%#.5x\n", 1);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 8 "C_NONE"%#.3o\n", 1);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 8 "C_NONE"%#.3o\n", 1);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 9 "C_NONE"%#.3o\n", 14);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 9 "C_NONE"%#.3o\n", 14);
		if (resltft  == reslt)
			ft_putendl_c("reslt "C_GREEN"OK", "cyan");
		else
		{
			ft_putendl_c("reslt "C_RED"KO", "cyan");
			printf("FT_PRINTF return %d\n", resltft);
			printf("printf return %d\n", reslt);
		}
	}
	reslt = 0;
	resltft = 0;
	if (argc == 2 && (strcmp(argv[1], "+") == 0) || (strcmp(argv[1], "all") == 0))
	{
		printf(C_GREEN"\n\n#####################  "C_BROWN"+"C_GREEN"  #####################"C_NONE"\n");
		char	strstr2[] = "test d'un # : ";
		// str de base
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 1 "C_NONE"%+d\n", -42);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 1 "C_NONE"%+d\n", -42);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 2 "C_NONE"%+o\n", 12345);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 2 "C_NONE"%+o\n", 12345);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 3 "C_NONE"%+x\n", 12345);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 3 "C_NONE"%+x\n", 12345);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 4 "C_NONE"%#+d\n", 0);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 4 "C_NONE"%#+d\n", 0);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 5 "C_NONE"%#+03d\n", 0);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 5 "C_NONE"%#+03d\n", 0);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 6 "C_NONE"%+u\n", UINT_MAX);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 6 "C_NONE"%+u\n", UINT_MAX);
		if (resltft  == reslt)
			ft_putendl_c("reslt "C_GREEN"OK", "cyan");
		else
		{
			ft_putendl_c("reslt "C_RED"KO", "cyan");
			printf("FT_PRINTF return %d\n", resltft);
			printf("printf return %d\n", reslt);
		}
	}
	reslt = 0;
	resltft = 0;
	if (argc == 2 && (strcmp(argv[1], "0") == 0) || (strcmp(argv[1], "all") == 0))
	{
		printf(C_GREEN"\n\n#####################  "C_BROWN"0"C_GREEN"  #####################"C_NONE"\n");
		char	strstr2[] = "test d'un # : ";
		// str de base
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 1 "C_NONE"%010.1d\n", 0);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 1 "C_NONE"%010.1d\n", 0);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 2 "C_NONE"%010.3d\n", 0);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 2 "C_NONE"%010.3d\n", 0);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 3 "C_NONE"{%0-3d}\n", 0);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 3 "C_NONE"{%0-3d}\n", 0);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 4 "C_NONE"{%0d}\n", -42);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 4 "C_NONE"{%0d}\n", -42);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 5 "C_NONE"{%010d}\n", -42);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 5 "C_NONE"{%010d}\n", -42);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 6 "C_NONE"{%0d}\n", 10000);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 6 "C_NONE"{%0d}\n", 10000);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 7 "C_NONE"{%04d}\n", 10000);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 7 "C_NONE"{%04d}\n", 10000);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 8 "C_NONE"{%05.S}\n", L"42 c'est trop cool");
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 8 "C_NONE"{%05.S}\n", L"42 c'est trop cool");
		if (resltft  == reslt)
			ft_putendl_c("reslt "C_GREEN"OK", "cyan");
		else
		{
			ft_putendl_c("reslt "C_RED"KO", "cyan");
			printf("FT_PRINTF return %d\n", resltft);
			printf("printf return %d\n", reslt);
		}
	}
	reslt = 0;
	resltft = 0;
	if (argc == 2 && (strcmp(argv[1], "lenght") == 0) || (strcmp(argv[1], "all") == 0))
	{
		printf(C_GREEN"\n\n#####################  "C_BROWN"lenght"C_GREEN"  #####################"C_NONE"\n");
		char	strstr2[] = "test d'un # : ";
		// str de base
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 1 "C_NONE"%4d\n", 42);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 1 "C_NONE"%4.d\n", 42);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 2 "C_NONE"%4d\n", 424242);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 2 "C_NONE"%4.d\n", 424242);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 3 "C_NONE"%4s\n", "42");
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 3 "C_NONE"%4s\n", "42");
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 4 "C_NONE"%4s\n", "424242");
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 4 "C_NONE"%4s\n", "424242");
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 4 "C_NONE"%10d\n", -42);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 4 "C_NONE"%10d\n", -42);
		if (resltft  == reslt)
			ft_putendl_c("reslt "C_GREEN"OK", "cyan");
		else
		{
			ft_putendl_c("reslt "C_RED"KO", "cyan");
			printf("FT_PRINTF return %d\n", resltft);
			printf("printf return %d\n", reslt);
		}
	}
	reslt = 0;
	resltft = 0;
	if (argc == 2 && (strcmp(argv[1], "space") == 0) || (strcmp(argv[1], "all") == 0))
	{
		printf(C_GREEN"\n\n#####################  "C_BROWN"space"C_GREEN"  #####################"C_NONE"\n");
		char	strstr2[] = "test d'un # : ";
		// str de base
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 1 "C_NONE"% d\n", -42);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 1 "C_NONE"% d\n", -42);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 2 "C_NONE"% d\n", -9999);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 2 "C_NONE"% d\n", -9999);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 2 "C_NONE"% d\n", 9999);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 2 "C_NONE"% d\n", 9999);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 3 "C_NONE"% +d\n", 42);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 3 "C_NONE"% +d\n", 42);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 4 "C_NONE"{% 03d}\n", 0);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 4 "C_NONE"{% 03d}\n", 0);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 5 "C_NONE"{% 0d}\n", 0);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 5 "C_NONE"{% 0d}\n", 0);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 6 "C_NONE"% s\n", "1");
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 6 "C_NONE"% s\n", "1");
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 7 "C_NONE"% s\n", "salut les copains");
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 7 "C_NONE"% s\n", "salut les copains");
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 8 "C_NONE"% o\n", 123);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 8 "C_NONE"% o\n", 123);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 9 "C_NONE"% x\n", 123);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 9 "C_NONE"% x\n", 123);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 10 "C_NONE"% u\n", UINT_MAX);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 10 "C_NONE"% u\n", UINT_MAX);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 11 "C_NONE"% d\n", 0);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 11 "C_NONE"% d\n", 0);
		if (resltft  == reslt)
			ft_putendl_c("reslt "C_GREEN"OK", "cyan");
		else
		{
			ft_putendl_c("reslt "C_RED"KO", "cyan");
			printf("FT_PRINTF return %d\n", resltft);
			printf("printf return %d\n", reslt);
		}
	}
	reslt = 0;
	resltft = 0;
	if (argc == 2 && (strcmp(argv[1], "precision") == 0) || (strcmp(argv[1], "all") == 0))
	{
		printf(C_GREEN"\n\n#####################  "C_BROWN"precision"C_GREEN"  #####################"C_NONE"\n");
		char	strstr2[] = "test d'un melange : ";
		// str de base
/*		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 1 "C_NONE"{%.4d}\n", 42);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 1 "C_NONE"{%.4d}\n", 42);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 1 "C_NONE"{%.d}\n", 42);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 1 "C_NONE"{%.d}\n", 42);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 2 "C_NONE"{%-.4d}\n", 42);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 2 "C_NONE"{%-.4d}\n", 42);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 3 "C_NONE"{%.4d}\n", 42424242);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 3 "C_NONE"{%.4d}\n", 42424242);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 4 "C_NONE"{%4.4d}\n", 42);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 4 "C_NONE"{%.4d}\n", 42);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 5 "C_NONE"{%4.4d}\n", 42424242);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 5 "C_NONE"{%.4d}\n", 42424242);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 6 "C_NONE"{%.5p et %.p}\n", 0, 0);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 6 "C_NONE"{%.5p et %.p}\n", 0, 0);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 7 "C_NONE"{%.10d}\n", -42);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 7 "C_NONE"{%.10d}\n", -42);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 8 "C_NONE"{%.4u}\n", 42);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 8 "C_NONE"{%.4u}\n", 42);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 9 "C_NONE"{%.4o}\n", 42);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 9 "C_NONE"{%.4o}\n", 42);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 10 "C_NONE"{%.4O}\n", 42);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 10 "C_NONE"{%.4O}\n", 42);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 11 "C_NONE"{%.O et %.0O}\n", 0, 0);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 11 "C_NONE"{%.O et %.0O}\n", 0, 0);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 12 "C_NONE"{%.4x}\n", 42);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 12 "C_NONE"{%.4x}\n", 42);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 13 "C_NONE"{%4.s}\n", "42jesuite");
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 13 "C_NONE"{%4.s}\n", "42jesuite");
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 14 "C_NONE"{%.4s}\n", "42");
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 14 "C_NONE"{%.4s}\n", "42");
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 15 "C_NONE"{%.4s}\n", "42superieura5");
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 15 "C_NONE"{%.4s}\n", "42superieura5");
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 16 "C_NONE"{%4.4s}\n", "42");
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 16 "C_NONE"{%4.4s}\n", "42");
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 17 "C_NONE"{%4.4s}\n", "42superieura5");
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 17 "C_NONE"{%.4s}\n", "42superieura5");
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 18 "C_NONE"{%.4S}\n", L"لحم خنزيرلحم خنزيرلحم خنزيرلحم خنزير");
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 18 "C_NONE"{%.4S}\n", L"لحم خنزيرلحم خنزيرلحم خنزيرلحم خنزير");
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 19 "C_NONE"{%.4S}\n", L"我是一只猫。");
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 19 "C_NONE"{%.4S}\n", L"我是一只猫。");
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 20 "C_NONE"{%4.S}\n", L"لحم خنزيرلحم خنزيرلحم خنزيرلحم خنزير");
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 20 "C_NONE"{%4.S}\n", L"لحم خنزيرلحم خنزيرلحم خنزيرلحم خنزير");
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 21 "C_NONE"{%4.S}\n", L"我是一只猫。");
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 21 "C_NONE"{%4.S}\n", L"我是一只猫。");*/
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 22 "C_NONE"{%.5c}\n", 0);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 22 "C_NONE"{%.5c}\n", 0);
		if (resltft  == reslt)
			ft_putendl_c("reslt "C_GREEN"OK", "cyan");
		else
		{
			ft_putendl_c("reslt "C_RED"KO", "cyan");
			printf("FT_PRINTF return %d\n", resltft);
			printf("printf return %d\n", reslt);
		}
	}
	reslt = 0;
	resltft = 0;
	if (argc == 2 && (strcmp(argv[1], "meli") == 0) || (strcmp(argv[1], "all") == 0))
	{
		printf(C_GREEN"\n\n#####################  "C_BROWN"meli"C_GREEN"  #####################"C_NONE"\n");
		char	strstr2[] = "test d'un melange : ";
		// str de base
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 1 "C_NONE"{%0-3d}\n", 0);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 1 "C_NONE"{%0-3d}\n", 0);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 2 "C_NONE"{%03.2d}\n", 0);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 2 "C_NONE"{%03.2d}\n", 0);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 3 "C_NONE"{%0.d et %.0d}\n", 0, 0);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 3 "C_NONE"{%0.d et %.0d}\n", 0, 0);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 4 "C_NONE"{%#.O}\n", 0);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 4 "C_NONE"{%#.O}\n", 0);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 5 "C_NONE"{%.O}\n", 0);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 5 "C_NONE"{%.O}\n", 0);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 6 "C_NONE"{%#O}\n", 0);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 6 "C_NONE"{%#O}\n", 0);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 7 "C_NONE"{%#.o et %#.0o}\n", 0, 0);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 7 "C_NONE"{%#.o et %#.0o}\n", 0, 0);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 8 "C_NONE"{%+-010d et %-010d}\n", 0, 0);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 8 "C_NONE"{%+-010d et %-010d}\n", 0, 0);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 9 "C_NONE"{%.u et %.0u}\n", 0, 0);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 9 "C_NONE"{%.u et %.0u}\n", 0, 0);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 10 "C_NONE"{%.x et %.0x}\n", 0, 0);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 10 "C_NONE"{%.x et %.0x}\n", 0, 0);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 10 "C_NONE"{%.d et %.0d}\n", 0, 0);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 10 "C_NONE"{%.d et %.0d}\n", 0, 0);
		if (resltft  == reslt)
			ft_putendl_c("reslt "C_GREEN"OK", "cyan");
		else
		{
			ft_putendl_c("reslt "C_RED"KO", "cyan");
			printf("FT_PRINTF return %d\n", resltft);
			printf("printf return %d\n", reslt);
		}
	}
	reslt = 0;
	resltft = 0;
	if (argc == 2 && (strcmp(argv[1], "star") == 0) || (strcmp(argv[1], "all") == 0))
	{
		printf(C_GREEN"\n\n#####################  "C_BROWN"star"C_GREEN"  #####################"C_NONE"\n");
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 1 "C_NONE"{%*d}\n", 15, 15000);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 1 "C_NONE"{%*d}\n", 15, 15000);
		reslt += printf(C_RED"   PRINTF -----> "C_CYAN"test 2 "C_NONE"{%.*d}\n", 15, 15000);
		resltft += ft_printf(C_RED"FT_PRINTF -----> "C_CYAN"test 2 "C_NONE"{%.*d}\n", 15, 15000);
		if (resltft  == reslt)
			ft_putendl_c("reslt "C_GREEN"OK", "cyan");
		else
		{
			ft_putendl_c("reslt "C_RED"KO", "cyan");
			printf("FT_PRINTF return %d\n", resltft);
			printf("printf return %d\n", reslt);
		}
	}
	return (0);
}
