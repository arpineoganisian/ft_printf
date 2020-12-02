#include "libftprintf.h"

int main()
{
	char u = 'u';
	char a = 'a';

//	ft_printf("re-coded: %08%");
//		printf("|\n");
//	printf("original: %08%");
//		printf("|\n");
	
	ft_printf("re-coded: %8c %c", u, a);
		printf("|\n");
	printf("original: %8c %c", u, a);
		printf("|\n");

}
