/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 09:39:57 by elbenkri          #+#    #+#             */
/*   Updated: 2017/12/28 16:02:27 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main()
{
  printf("\n%d\n", ft_printf("%-10s is a string", ""));
  printf("\n%d\n", printf("%-10s is a string", ""));
 //	printf("%d\n", ft_printf("salut toi comment %o %D %s %d %10.5s lol\n", 6500000000000, 18446744073709551615, 0, -2, "0"));
//	printf("%d\n", printf("salut toi comment %o %D %s %d %10.5s lol\n", 6500000000000, 18446744073709551615, 0, -2, "0"));
	return (0);
}
