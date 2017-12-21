/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_buffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 19:12:01 by elbenkri          #+#    #+#             */
/*   Updated: 2017/12/21 14:37:40 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	ft_print_buffer(t_var *var)
{
	if (var->type == TYPE_STRING)
	{
		if (var->res == 0)
		{
			ft_strcat(var->buf, "(null)");
			var->i_buf += ft_strlen("(null)");
		}
		else
		{
			ft_strcat(var->buf, var->res);
			var->i_buf += ft_strlen(var->res);
		}
	}
	else
	{
		if (var->nb.i >= -2147483648 && var->nb.i < 0)
		{
			ft_strcat(var->buf, ft_lltoa(var->nb.i));
			var->i_buf += ft_is_number(var->nb.i);
		}
		else
		{
			ft_strcat(var->buf, ft_lltoa(var->nb.ll));
			var->i_buf += ft_is_number(var->nb.ll);
		}
	}
}
