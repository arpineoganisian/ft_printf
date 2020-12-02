#include "libftprintf.h"

int main()
{
//	int i1;
	int i2;
//	char u = 'u';
//	char a = 'a';
	char str[5] = "1234\0";

	//___string
//	i1 = ft_printf("re-coded: %s");
//		printf("| %d\n", i1);
	i2 = printf("original: %8.2s", str);
		printf("| %d\n", i2);

	//___%
//	ft_printf("re-coded: %08%");
//		printf("|\n");
//	printf("original: %08%");
//		printf("|\n");

	//___char	
//	ft_printf("re-coded: %0*c %c", 5, u, a);
//		printf("|\n");
//	printf("original: %0*c %c", 5, u, a);
//		printf("|\n");

}
