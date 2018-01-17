#include "ft_printf.h"
#include <stdio.h>

int	main()
{
//	printf("\n%d\n", ft_printf("@moulitest: %#.o %#.0o", 0, 0));
//	printf("\n%d\n", printf("@moulitest: %#.o %#.0o", 0, 0));
	printf("\n%d\n", ft_printf("%0#14.0o!!", 12587499));
	printf("\n%d\n", printf("%0#14.0o!!", 12587499));
	return (0);
}
