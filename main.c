/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 09:39:57 by elbenkri          #+#    #+#             */
/*   Updated: 2017/12/21 14:46:29 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main()
{
	printf("%d\n", ft_printf("salut toi comment %x %s %010d\n", 6500000000000, 0, -2));
	printf("%d\n", printf("salut toi comment %li %s %d\n", 6500000000000, 0, -2));
	return (0);
}
