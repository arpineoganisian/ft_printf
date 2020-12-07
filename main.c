#include "libftprintf.h"

int main()
{
//	int i1;
	int i2;
//	char u = 'u';
//	char *str = NULL;
//	int a = 12;

	//___string
//	i1 = ft_printf("re-coded: |%8.2d", a);
//		printf("| %d\n", i1);
	i2 = printf("original: |%*.*d", 8, 4, -12);
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
