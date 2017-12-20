/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 07:45:16 by elbenkri          #+#    #+#             */
/*   Updated: 2017/12/19 19:23:13 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_stock_flags(char *str, t_var *var)
{
	int		i;
	int		j;
	int		flg;

	i = 0;
	j = 0;
	flg = 0;
	var->i_stock = 0;
	while (str[i])
	{
		while (var->flags_conv[j] && str[i] != var->flags_conv[j])
			j++;
		if (str[i] == var->flags_conv[j])
		{
			ft_type(var, var->flags_conv[j]);
			return (i + 1);
		}
		j = 0;
		var->flags_stock[var->i_stock++] = str[i++];
	}
	return (0);
}
