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

static void	ft_print_buffer4(t_var *var)
{
 	if (var->nb.l >= -2147483648 && var->nb.i <= 0)
	{
		ft_strcat(var->buf, ft_itoa(var->nb.i));
		var->i_buf += ft_is_number(var->nb.i);
	}
	else
	{
		ft_strcat(var->buf, ft_ltoa(var->nb.l));
		var->i_buf += ft_is_number(var->nb.l);
	}
}

static void	ft_print_buffer3(char *str, t_var *var)
{
	if (var->type == TYPE_HEXA || var->type == TYPE_HEXA_MAJ)
	{
		if (var->type == TYPE_HEXA)
			str = ft_ltoa_base(var->nb.l, 16);
		else if (var->type == TYPE_HEXA_MAJ)
			str = ft_ltoa_base_maj(var->nb.l, 16);
		ft_strcat(var->buf, str);
		var->i_buf += ft_strlen(str);
		free(str);
	}
	else if (var->type == TYPE_OCTAL)
	{
		str = ft_ltoa_base(var->nb.l, 8);
		ft_strcat(var->buf, str);
		var->i_buf += ft_strlen(str);
		free(str);
	}
	else
		ft_print_buffer4(var);
}

static void	ft_print_buffer2(t_var *var)
{
	char	*str;

	if (var->type == TYPE_LONG_LONG)
	{
		str = ft_lltoa(var->nb.ll);
		ft_strcat(var->buf, str);
		var->i_buf += ft_is_number_u_long_long(var->nb.ll);
		free(str);
	}
	else if (var->type == TYPE_UNSIGNED || var->type == TYPE_UNSIGNED_MAJ
		 || var->type == TYPE_OCTAL_MAJ)
	{
		if (var->type == TYPE_OCTAL_MAJ)
		{
			str = ft_ltoa_base(var->nb.u_l, 8);
			ft_strcat(var->buf, str);
			var->i_buf += ft_strlen(str);
			free(str);
			return ;
		}
		str = ft_ltoa(var->nb.u_l);
		ft_strcat(var->buf, str);
		var->i_buf += ft_is_number(var->nb.u_l);
		free(str);
	}
	else
		ft_print_buffer3(str = NULL, var);
}

void		ft_print_buffer(t_var *var)
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
		ft_print_buffer2(var);
}
