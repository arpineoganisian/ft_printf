#include "libftprintf.h"

int main()
{
//	int i1;
	int i2;
	int a = 10;
	int *p = &a; 


//	i1 = ft_printf("re-coded: |%x, 555);
//		printf("| %d\n", i1);
	i2 = printf("original: |%p", p);
		printf("| %d\n", i2);

}
