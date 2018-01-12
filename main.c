/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 09:39:57 by elbenkri          #+#    #+#             */
/*   Updated: 2018/01/12 02:07:53 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "ft_printf.h"
#include "libft/libft.h"
#include <locale.h>

int		main()
{
	int	ret;
	setlocale(LC_ALL, "");

	printf("\n%d\n", ft_printf("test %-7C %007d%-10.2ls!!", 0xd777, 0x45, L"〻"));
	printf("\n%d\n", printf("test %-7C %007d%-10.2ls!!", 0xd777, 0x45, L"〻"));
	//printf("\n%d\n", ft_printf("%llx, %llx", 0, ULLONG_MAX));
	//printf("\n%d\n", printf("%llx, %llx", 0, ULLONG_MAX));
	//printf("\n%d\n", ft_printf("%lX, %lX", 0, ULONG_MAX));
	//printf("\n%d\n", printf("%lX, %lX", 0, ULONG_MAX));
	//printf("\n%d\n", ft_printf("%jx, %jx", 0, ULLONG_MAX));
   //  printf("\n%d\n", printf("%jx, %jx", 0, ULLONG_MAX));
	return (0);
}
