/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_stock.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 16:14:24 by elbenkri          #+#    #+#             */
/*   Updated: 2017/12/22 22:16:42 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void		ft_flags_stock(t_var *var, t_flags *s_flags, char *str_hexa)
{
	int	k;
	int	len_str_hexa;

	len_str_hexa = ft_strlen(str_hexa);
	var->i_buf_tmp = 0;
	if ((s_flags->c & (1 << 4)) && (var->type >= TYPE_HEXA && var->type <= TYPE_HEXA_MAJ))
	{
		if (var->type == TYPE_HEXA && len_str_hexa)
		{
			ft_memcpy(&var->buf_tmp[var->i_buf_tmp], "0x", 2);
			var->i_buf_tmp += 2;
		}
		else if (var->type == TYPE_HEXA_MAJ && len_str_hexa)
		{
			ft_memcpy(&var->buf_tmp[var->i_buf_tmp], "0X", 2);
			var->i_buf_tmp += 2;
		}
	}
	if (s_flags->precision >= s_flags->largeur && s_flags->precision >= len_str_hexa)
	{
		k = s_flags->precision - len_str_hexa;
		ft_memset(&var->buf_tmp[var->i_buf_tmp], '0', k);
		var->i_buf_tmp += k;
		ft_memcpy(&var->buf_tmp[var->i_buf_tmp], str_hexa, len_str_hexa);
		ft_memcpy(&var->buf[var->i_buf], var->buf_tmp, var->i_buf_tmp + len_str_hexa);
		var->i_buf += var->i_buf_tmp + len_str_hexa;
		(!len_str_hexa && !s_flags->precision && (var->type >= TYPE_OCTAL && var->type <= TYPE_HEXA_MAJ)) ? ft_memcpy(&var->buf[var->i_buf++], "0", 1) : 0;
	}
	else if (s_flags->largeur > s_flags->precision && s_flags->precision >= len_str_hexa)
	{
		if ((s_flags->c & (1 << 2)))
		{
			k = s_flags->precision - len_str_hexa;
			ft_memset(&var->buf_tmp[var->i_buf_tmp], '0', k);
			var->i_buf_tmp += k;
			ft_memcpy(&var->buf_tmp[var->i_buf_tmp], str_hexa, len_str_hexa);
			var->i_buf_tmp += len_str_hexa;
			k = ((var->type == TYPE_HEXA || var->type == TYPE_HEXA_MAJ) && len_str_hexa) ? s_flags->largeur - s_flags->precision - 2 : s_flags->largeur - s_flags->precision;
			ft_memset(&var->buf_tmp[var->i_buf_tmp], ' ', k);
			var->i_buf_tmp += k;
			(!len_str_hexa && !s_flags->precision && (var->type >= TYPE_OCTAL && var->type <= TYPE_OCTAL_MAJ)) ? ft_memcpy(&var->buf[var->i_buf++], "0", 1) : 0;
			ft_memcpy(&var->buf[var->i_buf], var->buf_tmp, var->i_buf_tmp + len_str_hexa);
			var->i_buf = s_flags->largeur;
		}
		else
		{
			k = ((var->type == TYPE_HEXA || var->type == TYPE_HEXA_MAJ) && len_str_hexa) ? s_flags->largeur - s_flags->precision - 2 : s_flags->largeur - s_flags->precision;
 			ft_memset(&var->buf_tmp[0], ' ', k);
			var->i_buf_tmp += k;

			(var->type == TYPE_HEXA && len_str_hexa) ? ft_memcpy(&var->buf_tmp[var->i_buf_tmp - 2], "0x", 2) : 0;
			(var->type == TYPE_HEXA_MAJ && len_str_hexa) ? ft_memcpy(&var->buf_tmp[var->i_buf_tmp - 2], "0X", 2) : 0;
			k = s_flags->precision - len_str_hexa;
			ft_memset(&var->buf_tmp[var->i_buf_tmp], '0', k);
			var->i_buf_tmp += k;
			ft_memcpy(&var->buf_tmp[var->i_buf_tmp], str_hexa, len_str_hexa);
			var->i_buf_tmp += len_str_hexa;
			ft_memcpy(&var->buf[var->i_buf], var->buf_tmp, var->i_buf_tmp + len_str_hexa);
			var->i_buf += s_flags->largeur;
			(!len_str_hexa && (var->type >= TYPE_OCTAL && var->type <= TYPE_HEXA_MAJ)) ? ft_memcpy(&var->buf[var->i_buf - 1], "0", 1) : 0;
		}
	}
	else if (s_flags->largeur < len_str_hexa)
	{
		ft_memcpy(&var->buf_tmp[var->i_buf_tmp], str_hexa, len_str_hexa);
		ft_memcpy(&var->buf[var->i_buf], var->buf_tmp, var->i_buf_tmp + len_str_hexa);
		var->i_buf += var->i_buf_tmp + len_str_hexa;
	}
	else if (s_flags->largeur > s_flags->precision)
	{
		if ((s_flags->c & (1 << 2)))
		{
			ft_memcpy(&var->buf_tmp[var->i_buf_tmp], str_hexa, len_str_hexa);
			var->i_buf_tmp += len_str_hexa;
			k = s_flags->largeur - s_flags->precision;
			ft_memset(&var->buf_tmp[var->i_buf_tmp], ' ', k);
			ft_memcpy(&var->buf[var->i_buf], var->buf_tmp, var->i_buf_tmp + len_str_hexa);
			var->i_buf += s_flags->largeur;
		}
	}
}
