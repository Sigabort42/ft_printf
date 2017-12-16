/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:56:55 by elbenkri          #+#    #+#             */
/*   Updated: 2017/12/16 10:04:03 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_var	var;

	var.ret = 0;
	var.i_buf = 0;
	ft_strcpy(var.flags_conv, "cCdDioOuUxXpsS");
	while (format[var.ret] && format[var.ret] != '%' && var.i_buf != 2000)
		var.buf[var.i_buf++] = format[var.ret++];
	ft_stock_flags(&((char*)format)[var.ret], &var);
	printf("%s %s stock :%s %d\n", var.res, var.buf, var.flags_stock, var.type);
	return (var.ret);
}
