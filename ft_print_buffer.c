/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_buffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 19:12:01 by elbenkri          #+#    #+#             */
/*   Updated: 2018/01/09 07:13:48 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static void	ft_print_buffer2(va_list ap, char *str, t_var *var)
{
	t_flags	s_flags;

	s_flags.c = 0;
	s_flags.m = 0;
	s_flags.largeur = 0;
	s_flags.precision = 0;
	if (var->type == TYPE_HEXA || var->type == TYPE_HEXA_MAJ)
	{
		if (var->type == TYPE_HEXA)
			str = ft_ltoa_base(va_arg(ap, unsigned int), 16);
		else if (var->type == TYPE_HEXA_MAJ)
			str = ft_ltoa_base_maj(va_arg(ap, unsigned int), 16);
	}
	else if (var->type == TYPE_OCTAL)
		str = ft_ltoa_base(va_arg(ap, unsigned int), 8);
	else if (var->type == TYPE_NON_CONNU)
		;
	else if (var->type == TYPE_MODULO)
		;
 	else if (var->type <= TYPE_INT)
		str = ft_itoa(va_arg(ap, int));
	else if (var->type == TYPE_MODULO)
		var->buf[var->i_buf++] = '%';
	else if (var->type == TYPE_ADDRESS)
	{
		str = ft_ltoa_base(va_arg(ap, unsigned long), 16);
		ft_memcpy(&var->buf[var->i_buf], "0x", var->i_buf += 2);
	}
	else if (var->type == TYPE_BITWISE)
		str = ft_ltoa_base(va_arg(ap, unsigned long), 2);
	else
		str = ft_ltoa(va_arg(ap, long long));
	if (var->type != TYPE_MODULO && var->type != TYPE_NON_CONNU)
		ft_memcpy(&var->buf[var->i_buf], str, var->i_buf += ft_strlen(str));
	free(str);
}

int			ft_print_buffer(va_list ap, t_var *var)
{
	char	*str;
	int		i;

	i = 0;
	if (var->type == TYPE_STRING || var->type == TYPE_CHAR || var->type == TYPE_WSTRING || var->type == TYPE_WCHAR)
	{
		if (var->type == TYPE_WSTRING)
		{
			var->nb.chr2 = (wchar_t*)va_arg(ap, unsigned int*);
			if (!var->nb.chr2)
				ft_memcpy(&var->buf[var->i_buf], "(null)", var->i_buf += 6);
			else
			{
				while (var->nb.chr2[i])
					ft_wchar2(var->nb.chr2[i++], var, 0);
			}
		}
		else if (var->type == TYPE_WCHAR)
		{
			var->nb.u_i = va_arg(ap, unsigned int);
			if (var->nb.u_i > 1114111)
				return (0);
			ft_wchar2((wchar_t)var->nb.u_i, var, 0);
		}
		else if (var->type == TYPE_CHAR)
			var->buf[var->i_buf++] = va_arg(ap, int);
		else if (var->type == TYPE_STRING && !(var->res = va_arg(ap, char *)))
			ft_memcpy(&var->buf[var->i_buf], "(null)", var->i_buf += 6);
		else
			ft_memcpy(&var->buf[var->i_buf], var->res, var->i_buf += ft_strlen(var->res));
	}
	else if (var->type == TYPE_UNSIGNED || var->type == TYPE_UNSIGNED_MAJ
			 || var->type == TYPE_OCTAL_MAJ)
	{
		if (var->type == TYPE_OCTAL_MAJ)
			str = ft_lltoa_base(va_arg(ap, unsigned long), 8);
		else if (var->type == TYPE_UNSIGNED_MAJ)
			str = ft_lltoa(va_arg(ap, unsigned long));
		else
			str = ft_ltoa(va_arg(ap, unsigned int));
		ft_memcpy(&var->buf[var->i_buf], str, var->i_buf += ft_strlen(str));
		free(str);
	}
	else
		ft_print_buffer2(ap, str = NULL, var);
	return (0);
}
