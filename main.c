/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 09:39:57 by elbenkri          #+#    #+#             */
/*   Updated: 2017/12/22 19:43:32 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main()
{
	printf("%d\n", ft_printf("%5.5s\n", "salut"));
	printf("%d\n", printf("%5.5s\n", "salut"));
//	printf("%d\n", ft_printf("salut toi comment %x %s %d %10.5s lol\n", 6500000000000, 0, -2, "0"));
//	printf("%d\n", printf("salut toi comment %li %s %d %10.5s lol\n", 6500000000000, 0, -2, "0"));
	return (0);
}
