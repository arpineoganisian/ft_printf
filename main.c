#include "libftprintf.h"

int main()
{
	int i1;
	int i2;

	i1 = ft_printf("re-coded: |%-c |%*c", '9', 12, '0');
		printf("| %d\n", i1);
	i2 = printf("original: |%-c |%*c", '9', 12, '0');
		printf("| %d\n", i2);
}
