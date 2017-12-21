/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:56:55 by elbenkri          #+#    #+#             */
/*   Updated: 2017/12/21 15:43:02 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_var	var;
	va_list ap;

	printf("format :%s\n", format);
	va_start(ap, format);
	var.ret = 0;
	var.i_buf = 0;
	ft_bzero(var.buf, 2000);
	ft_strcpy(var.flags_conv, "cCdDioOuUxXpsS");
	while (format[var.ret])
	{
		while (format[var.ret] && format[var.ret] != '%' && var.i_buf != 2000)
			var.buf[var.i_buf++] = format[var.ret++];
		if (var.i_buf == 2000)
		{
			write(1, var.buf, 2000);
			var.i_buf = 0;
			ft_bzero(var.buf, 2000);
		}
		var.ret += ft_stock_flags(&((char*)format)[var.ret], &var);
		if (ft_strlen(var.flags_stock) == 0)
			break;
		ft_stock_ap(ap, &var);
		(!ft_flags(&var, &var.flags_stock[1])) ? ft_print_buffer(&var) : ft_putstr("oulouloulou\n\n\n");;
		ft_bzero(var.nb.str, 8);
		printf("ret :%d|res :%s|buf :%s|stock :%s|type :%d|test i :%d\n", var.ret, var.res, var.buf, var.flags_stock, var.type, var.nb.i);
		ft_bzero(var.flags_stock, 100);
	}
	ft_putstr("res :");
	ft_putstr(var.buf);
	return (var.i_buf);
}
