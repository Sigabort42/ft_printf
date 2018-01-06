/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 09:39:57 by elbenkri          #+#    #+#             */
/*   Updated: 2018/01/04 08:11:33 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "ft_printf.h"
#include "libft/libft.h"

int		main()
{
  printf("\n%d\n", ft_printf("%4.s", "42"));
  printf("\n%d\n", printf("%4.s", "42"));
  //  printf("\n%d\n", ft_printf("%llx", 9223372036854775808));
  //  printf("\n%d\n", printf("%llx", 9223372036854775808));
  //  printf("\n%d\n", ft_printf("salut {fd}2 toi %s %s %10d", "a", "def", 1234));
  //  printf("\n%d\n", printf("salut toi %s %s %*d", "a", "def", 10, 1234));
  //	printf("\n%d\n", ft_printf("{%-15ZZZZ}", 123));
  //	printf("\n%d\n", printf("{%-15ZZZZ}", 123));
  //	printf("%d\n", ft_printf("salut toi comment %o %D %s %d %10.5s lol\n", 6500000000000, 18446744073709551615, 0, -2, "0"));
  //	printf("%d\n", printf("salut toi comment %o %D %s %d %10.5s lol\n", 6500000000000, 18446744073709551615, 0, -2, "0"));
  return (0);
}
