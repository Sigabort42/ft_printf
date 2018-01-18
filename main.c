#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	printf("\n%d\n", ft_printf("%#08x", 42));
	printf("\n%d\n", printf("%#08x", 42));
	printf("\n%d\n", ft_printf("%0#14.0o!!", 12587499));
	printf("\n%d\n", printf("%0#14.0o!!", 12587499));
	printf("\n%d\n", ft_printf("cc%#.4X et %#0012x %#04hX !!", 0xaef, 0xe, (unsigned short)0));
	printf("\n%d\n", printf("cc%#.4X et %#0012x %#04hX !!", 0xaef, 0xe, (unsigned short)0));
	return (0);
}
