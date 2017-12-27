/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags_buffer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 16:14:24 by elbenkri          #+#    #+#             */
/*   Updated: 2017/12/22 22:16:42 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static void	ft_flags_precision(t_var *var, t_flags *s_flags, int i)
{
	char	tab[] = "(null)";

	if (!var->res)
		var->res = tab;
	else if (!s_flags->precision)
		s_flags->precision = (int)ft_strlen(var->res);
	var->i_buf_tmp = (s_flags->c & (1 << 2)) ?
		0 : s_flags->largeur - s_flags->precision;
	if (var->res)
	    (var->i_buf_tmp < 0) ? ft_memcpy(&var->buf_tmp[0], var->res,s_flags->precision)
: ft_memcpy(&var->buf_tmp[var->i_buf_tmp], var->res, s_flags->precision);
	if (!var->i_buf_tmp)
	{
		i = s_flags->precision;
		var->i_buf_tmp = s_flags->largeur;
	}
	while (i < var->i_buf_tmp)
	{
		if ((!(s_flags->c & (1 << 2))) && (s_flags->c & (1 << 0)))
			var->buf_tmp[i++] = '0';
		else
			var->buf_tmp[i++] = ' ';
	}
	i = 0;
	while (i < (int)ft_strlen(var->buf_tmp))
		var->buf[var->i_buf++] = var->buf_tmp[i++];
}

static void	ft_flags_largeur(t_var *var, t_flags *s_flags, int i)
{
	if (s_flags->largeur < (int)ft_strlen(var->res))
		var->i_buf_tmp = 0;
	else if (s_flags->precision >= (int)ft_strlen(var->res))
		var->i_buf_tmp = (s_flags->c & (1 << 2)) ? 0 :
			s_flags->largeur - ft_strlen(var->res);
	else
		var->i_buf_tmp = (s_flags->c & (1 << 2)) ? 0 : s_flags->largeur;
	ft_memcpy(&var->buf_tmp[var->i_buf_tmp], var->res, ft_strlen(var->res) + 1);
	if (!var->i_buf_tmp)
	{
		i = ft_strlen(var->res);
		var->i_buf_tmp = s_flags->largeur;
	}
	while (i < var->i_buf_tmp)
	{
		if ((!(s_flags->c & (1 << 2))) && (s_flags->c & (1 << 0)))
			var->buf_tmp[i++] = '0';
		else
			var->buf_tmp[i++] = ' ';
	}
	i = 0;
	while (i < (int)ft_strlen(var->buf_tmp))
		var->buf[var->i_buf++] = var->buf_tmp[i++];
}

static void		ft_flags_stock(t_var *var, t_flags *s_flags, char *str_hexa)
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
		k = (!len_str_hexa) ? s_flags->precision - len_str_hexa  + 1 : s_flags->precision - len_str_hexa;
		ft_memset(&var->buf_tmp[var->i_buf_tmp], '0', k);
		var->i_buf_tmp += k;
		ft_memcpy(&var->buf_tmp[var->i_buf_tmp], str_hexa, len_str_hexa);
		ft_memcpy(&var->buf[var->i_buf], var->buf_tmp, var->i_buf_tmp + len_str_hexa);
		var->i_buf += var->i_buf_tmp + len_str_hexa;
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
			k = (var->type == TYPE_HEXA || var->type == TYPE_HEXA_MAJ) ? s_flags->largeur - s_flags->precision - 2 : s_flags->largeur - s_flags->precision;
			ft_memset(&var->buf_tmp[var->i_buf_tmp], ' ', k);
			ft_memcpy(&var->buf[var->i_buf], var->buf_tmp, var->i_buf_tmp + len_str_hexa);
			var->i_buf += s_flags->largeur;
		}
		else
		{
			k = (var->type == TYPE_HEXA || var->type == TYPE_HEXA_MAJ) ? s_flags->largeur - s_flags->precision - 2 : s_flags->largeur - s_flags->precision;
			ft_memset(&var->buf_tmp[0], ' ', k);
			var->i_buf_tmp += k;
			(var->type == TYPE_HEXA && len_str_hexa) ? ft_memcpy(&var->buf_tmp[var->i_buf_tmp - 2], "0x", 2) : 0;
			(var->type == TYPE_HEXA_MAJ && len_str_hexa) ? ft_memcpy(&var->buf_tmp[var->i_buf_tmp - 2], "0X", 2) : 0;
			k = s_flags->precision - len_str_hexa;
			ft_memset(&var->buf_tmp[var->i_buf_tmp], '0', k);
			var->i_buf_tmp += k;
			(!len_str_hexa) ? ft_memcpy(&var->buf_tmp[var->i_buf_tmp], "0", 1) : ft_memcpy(&var->buf_tmp[var->i_buf_tmp], str_hexa, len_str_hexa);
			var->i_buf_tmp += len_str_hexa;
			ft_memcpy(&var->buf[var->i_buf], var->buf_tmp, var->i_buf_tmp + len_str_hexa);
			var->i_buf += s_flags->largeur;
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

int			ft_print_flags_buffer(t_var *var, t_flags *s_flags)
{
	if (var->type == TYPE_STRING)
	{
		var->i_buf_tmp = 0;
		if (var->res)
		{
			if (s_flags->precision < (int)ft_strlen(var->res))
				ft_flags_precision(var, s_flags, 0);
			else
				ft_flags_largeur(var, s_flags, 0);
		}
		else
			ft_flags_precision(var, s_flags, 0);
	}
	else
	{
	  printf("ouloulou :%llu %d %d\n", var->nb.ll, var->type, TYPE_OCTAL);
		if ((s_flags->m & (1 << 3)))
		{
			if (var->type == TYPE_HEXA)
				ft_flags_stock(var, s_flags, ft_lltoa_base(var->nb.ll, 16));
			else if (var->type == TYPE_HEXA_MAJ)
				ft_flags_stock(var, s_flags, ft_lltoa_base_maj(var->nb.ll, 16));
			else if (var->type == TYPE_OCTAL)
				ft_flags_stock(var, s_flags, ft_lltoa_base(var->nb.ll, 8));
		}
	}
	return (1);
}
