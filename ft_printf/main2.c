#include <stdio.h>
#include <unistd.h>

int main(void)
{
	//printf("%s\n", L"salutЩ les Щcopain");
//	printf("test : %c, %c, %c, %c, %c, %c\n", 0, 1, 2, 3, 4, 5, 6);
	write(1, "\0", 1);
	return (0);
}
