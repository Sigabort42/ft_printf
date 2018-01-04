/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 07:45:16 by elbenkri          #+#    #+#             */
/*   Updated: 2017/12/28 11:27:00 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
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
		if (str[i] == '%')
		{
			ft_type(var, '%');
			var->flags_stock[var->i_stock++] = str[i++];
			return (i);
		}
		else if (!str[i] && str[i] != var->flags_conv[j])
		{
			ft_type(var, 'N');
			var->nb.c = str[i];
			return (i + 1);
		}
	}
	return (0);
}
