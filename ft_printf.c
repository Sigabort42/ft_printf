/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:56:55 by elbenkri          #+#    #+#             */
/*   Updated: 2017/12/15 18:39:04 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
//#include <stdarg.h>
#include <stdio.h>

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
		while (str[i] != var->flags_conv[j])
			j++;
		if (str[i] == var->flags_conv[j])
			return (0);
		j = 0;
		var->flags_stock[var->i_stock++] = str[i++];
	}
	return (1);
}

int		ft_printf(const char *format)
{
	t_var	var;

	var.ret = 0;
	var.i_buf = 0;
	ft_strcpy(var.flags_conv, "cCdDioOuUxXpsS");
	while (format[var.ret] && format[var.ret] != '%' && var.i_buf != 2000)
		var.buf[var.i_buf++] = format[var.ret++];
	ft_stock_flags(&(char)format[var.ret], var);
//	var.res = ft_strdup(var.buf);
	printf("%s %s %s\n", var.res, var.buf, var.flags_stock);
	return (var.ret);
}

int		main()
{
	printf("%d\n", ft_printf("salut toi comment tu"));
	return (0);
}
