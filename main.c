#include "libftprintf.h"

int main()
{
//	int i1;
	int i2;
	int a = 12;
	int *b = &a;

//	i1 = ft_printf("re-coded: |%", );
//		printf("| %d\n", i1);
	i2 = printf("original: |%p", b);
		printf("| %d\n", i2);
}
