/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ui_maxtoa_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 12:45:52 by elbenkri          #+#    #+#             */
/*   Updated: 2017/12/22 16:14:11 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_count(uintmax_t value, int base)
{
	int		i;

	i = 0;
	while (value > 0)
	{
		i++;
		value /= base;
	}
	return (i);
}

char			*ft_ui_maxtoa_base(uintmax_t value, int base)
{
	char		*res =  NULL;
	int		i;

	if (base == 10)
	  return (ft_lltoa(value));
	i = ft_count(value, base);
	res = (char*)malloc(sizeof(char) * i);
	res[i] = 0;
	while (i-- > 0)
	{
		res[i] = value % base + ((value % base > 9) ? 'a' - 10 : '0');
		value /= base;
	}
	return (res);
}
