/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:56:55 by elbenkri          #+#    #+#             */
/*   Updated: 2017/12/28 16:04:48 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_var	var;
	va_list ap;
	t_flags	s_flags;

	va_start(ap, format);
	var.ret = 0;
	var.i_buf = 0;
	s_flags.c = 0;
	ft_bzero(var.buf, 2000);
	ft_strcpy(var.flags_conv, "cCdDioOuUxXpsSb");
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
		(!ft_flags(&var.flags_stock[1], &s_flags)) ? ft_print_buffer(ap, &var) : ft_print_flags_buffer(ap, &var, &s_flags);
		ft_bzero(var.nb.str, 8);
		ft_bzero(var.flags_stock, 100);
	}
	va_end(ap);
	write(1, var.buf, var.i_buf);
	return (var.i_buf);
}
