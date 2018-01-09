/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 09:39:57 by elbenkri          #+#    #+#             */
/*   Updated: 2018/01/09 08:14:16 by elbenkri         ###   ########.fr       */
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
   setlocale(LC_ALL, "");

   printf("\n%d\n", ft_printf("%b\n", "salem djeghbala"));
//   printf("\n%d\n", ft_printf("%"));
//   printf("\n%d\n", printf("%"));
//   printf("\n%d\n", ft_printf("%lX, %lX", 0, ULONG_MAX));
//   printf("\n%d\n", printf("%lX, %lX", 0, ULONG_MAX));
//   printf("\n%d\n", ft_printf("%jx, %jx", 0, ULLONG_MAX));
//   printf("\n%d\n", printf("%jx, %jx", 0, ULLONG_MAX));
//   printf("\n%d\n", ft_printf("%#.x, %#.0x", 0, 0));
//   printf("\n%d\n", printf("%#.x, %#.0x", 0, 0));   
//   printf("\n%d\n", ft_printf("{%05.Z}", 0));
//   printf("\n%d\n", printf("{%05.Z}", 0));   
  return (0);
}
