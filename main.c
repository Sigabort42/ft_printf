#include "ft_printf.h"
#include <stdio.h>

int	main()
{
//	printf("\n%d\n", ft_printf("@moulitest: %#.o %#.0o", 0, 0));
//	printf("\n%d\n", printf("@moulitest: %#.o %#.0o", 0, 0));
	printf("\n%d\n", ft_printf("test%#.4o et %02o %0#14.0o!!", 012, 036, 12587499));
	printf("\n%d\n", printf("test%#.4o et %02o %0#14.0o!!", 012, 036, 12587499));
	return (0);
}
