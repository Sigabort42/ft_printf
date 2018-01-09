/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 16:24:38 by elbenkri          #+#    #+#             */
/*   Updated: 2018/01/08 18:31:10 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_wchar(wchar_t chr, t_var *var, int i)
{
	char	c;

	c = 0;
	if (chr > 0)
		var->i_buf -= i;
	if (chr <= 0x7F) //127
		var->buf[var->i_buf++] = chr;
	else if (chr <= 0x7FF) //2047
    {
		var->buf[var->i_buf++] = (chr >> 6) + 192; //OxC0
		var->buf[var->i_buf++] = (chr & 63) + 128; //0x3F 0x80
    }
	else if (chr <= 0xFFFF) //65535
    {
		var->buf[var->i_buf++] = (chr >> 12) + 224; //0xE0
		var->buf[var->i_buf++] = ((chr >> 6) & 63) + 128; //0x3F 0x80
		var->buf[var->i_buf++] = (chr & 63) + 128; //0x3F 0x80
    }
	else if (chr <= 0x10FFFF) //1114111 
    {
		var->buf[var->i_buf++] = (chr >> 18) + 240; // 0xF0
		var->buf[var->i_buf++] = ((chr >> 12) & 63) + 128; //0x3F 0x80
		var->buf[var->i_buf++] = ((chr >> 6) & 63) + 128; //0x3F 0x80
		var->buf[var->i_buf++] = (chr & 63) + 128; //0x3F 0x80
    }
}
