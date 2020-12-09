#include "libftprintf.h"

int main()
{
	int i1;
	int i2;

	i1 = ft_printf("re-coded: |%-3x", 0);
		printf("| %d\n", i1);
	i2 = printf("original: |%-3x", 0);
		printf("| %d\n", i2);

}
