#include <locale.h>
#include <unistd.h>
#include <wchar.h>
#include <string.h>
#include <stdlib.h>
#include <libft.h>

void	main(void)
{
	setlocale(LC_ALL, "en_US.UTF-8");
	wchar_t	c = L'c';
	write(1, &c, sizeof(wchar_t));
	write(1, "\n", 1);

	char *str = malloc(sizeof(wchar_t) + 1);
	memcpy(str, &c, sizeof(wchar_t));
	str[2] = '\0';
	write(1, "bonjour : ", 10);
	write(1, str, sizeof(wchar_t));

	str = ft_strjoin("bonjour : ", str);
	write(1, str, ft_strlen(str));
}
