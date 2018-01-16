#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	printf("\n%d\n", ft_printf("%-3d\n", 0));
	printf("\n%d\n", printf("%-3d\n", 0));
	return (0);
}
