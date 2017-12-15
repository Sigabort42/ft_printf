/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 12:45:52 by elbenkri          #+#    #+#             */
/*   Updated: 2017/12/14 20:08:52 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

char	*ft_itoa_base(int value, int base)
{
	char	*res =  NULL;
	int		i;
	int		flg;

	flg = (value < 0) ? 1 : 0;
	value *= (flg == 1) ? -1 : 1;
	i = ft_is_number(value);
	res = (char*)malloc(sizeof(char) * i);
	if (flg == 1)
		res[i] = 0;
	else
		res[i--] = 0;
	while (i-- > 0)
	{
		res[i] = value % base + ((value % base > 9) ? 'A' - 10 : '0');
		value /= base;
	}
	res[0] = (flg == 1) ? '-' : res[0];
	return (res);
}

int		main()
{
	printf("%s\n", ft_itoa_base(200000000, 16));
	return (0);
}
