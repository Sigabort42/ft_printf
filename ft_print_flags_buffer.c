/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags_buffer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 16:14:24 by elbenkri          #+#    #+#             */
/*   Updated: 2017/12/28 13:11:42 by elbenkri         ###   ########.fr       */
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

int			ft_print_flags_buffer(t_var *var, t_flags *s_flags)
{
	if (var->type == TYPE_STRING || var->type == TYPE_CHAR || var->type == TYPE_MODULO)
	{
		var->i_buf_tmp = 0;
		if (var->type == TYPE_CHAR)
			var->res = ft_strdup(&var->nb.c);
		else if (var->type == TYPE_MODULO)
			var->res = ft_strdup("%");
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
		if (var->type == TYPE_ADDRESS)
		{
			ft_memcpy(&var->buf[var->i_buf], "0x", 2);
			var->i_buf += 2;
			ft_flags_stock(var, s_flags, ft_ltoa_base(var->nb.l, 16));
		}
		else if ((s_flags->m & (1 << 3)))
		{
			if (var->type == TYPE_HEXA)
				ft_flags_stock(var, s_flags, ft_lltoa_base(var->nb.ll, 16));
			else if (var->type == TYPE_HEXA_MAJ)
				ft_flags_stock(var, s_flags, ft_lltoa_base_maj(var->nb.ll, 16));
			else if (var->type == TYPE_OCTAL)
				ft_flags_stock(var, s_flags, ft_lltoa_base(var->nb.ll, 8));
			else if (var->type == TYPE_OCTAL_MAJ)
				ft_flags_stock(var, s_flags, ft_ltoa_base(var->nb.ll, 8));
			else
				ft_flags_stock(var, s_flags, ft_lltoa(var->nb.ll));
		}
		else if ((s_flags->m & (1 << 0)))
		{
			if (var->type == TYPE_HEXA)
				ft_flags_stock(var, s_flags, ft_itoa_base(var->nb.u_c, 16));
			else if (var->type == TYPE_HEXA_MAJ)
				ft_flags_stock(var, s_flags, ft_itoa_base_maj(var->nb.u_c, 16));
			else if (var->type == TYPE_OCTAL)
				ft_flags_stock(var, s_flags, ft_itoa_base(var->nb.u_c, 8));
			else if (var->type == TYPE_OCTAL_MAJ)
				ft_flags_stock(var, s_flags, ft_ltoa_base(var->nb.u_l, 8));
			else
				ft_flags_stock(var, s_flags, ft_itoa(var->nb.u_c));
		}
		else if ((s_flags->m & (1 << 1)))
		{
			if (var->type == TYPE_HEXA)
				ft_flags_stock(var, s_flags, ft_itoa_base(var->nb.u_sh, 16));
			else if (var->type == TYPE_HEXA_MAJ)
				ft_flags_stock(var, s_flags, ft_itoa_base_maj(var->nb.u_sh, 16));
			else if (var->type == TYPE_OCTAL)
				ft_flags_stock(var, s_flags, ft_itoa_base(var->nb.u_sh, 8));
			else if (var->type == TYPE_OCTAL_MAJ)
				ft_flags_stock(var, s_flags, ft_ltoa_base(var->nb.u_l, 8));
			else
				ft_flags_stock(var, s_flags, ft_itoa(var->nb.u_sh));
		}
		else if ((s_flags->m & (1 << 2)))
		{
			if (var->type == TYPE_HEXA)
				ft_flags_stock(var, s_flags, ft_ltoa_base(var->nb.l, 16));
			else if (var->type == TYPE_HEXA_MAJ)
				ft_flags_stock(var, s_flags, ft_ltoa_base_maj(var->nb.l, 16));
			else if (var->type == TYPE_OCTAL)
				ft_flags_stock(var, s_flags, ft_ltoa_base(var->nb.l, 8));
			else if (var->type == TYPE_OCTAL_MAJ)
				ft_flags_stock(var, s_flags, ft_ltoa_base(var->nb.u_l, 8));
			else
				ft_flags_stock(var, s_flags, ft_ltoa(var->nb.u_l));
		}
		else if ((s_flags->m & (1 << 4)))
		{
			if (var->type == TYPE_HEXA)
				ft_flags_stock(var, s_flags, ft_ui_maxtoa_base(var->nb.ui_max, 16));
			else if (var->type == TYPE_HEXA_MAJ)
				ft_flags_stock(var, s_flags, ft_ui_maxtoa_base_maj(var->nb.ui_max, 16));
			else if (var->type == TYPE_OCTAL)
				ft_flags_stock(var, s_flags, ft_ui_maxtoa_base(var->nb.ui_max, 8));
			else if (var->type == TYPE_OCTAL_MAJ)
				ft_flags_stock(var, s_flags, ft_ltoa_base(var->nb.u_l, 8));
			else
				ft_flags_stock(var, s_flags, ft_ui_maxtoa(var->nb.ui_max));
		}
		else if ((s_flags->m & (1 << 5)))
		{
			if (var->type == TYPE_HEXA)
				ft_flags_stock(var, s_flags, ft_ltoa_base(var->nb.u_i, 16));
			else if (var->type == TYPE_HEXA_MAJ)
				ft_flags_stock(var, s_flags, ft_ltoa_base_maj(var->nb.u_i, 16));
			else if (var->type == TYPE_OCTAL)
				ft_flags_stock(var, s_flags, ft_ltoa_base(var->nb.u_i, 8));
			else if (var->type == TYPE_OCTAL_MAJ)
				ft_flags_stock(var, s_flags, ft_ltoa_base(var->nb.u_l, 8));
			else
				ft_flags_stock(var, s_flags, ft_ltoa(var->nb.u_i));
		}
		else
		{
			if (var->type == TYPE_HEXA)
				ft_flags_stock(var, s_flags, ft_ltoa_base(var->nb.l, 16));
			else if (var->type == TYPE_HEXA_MAJ)
				ft_flags_stock(var, s_flags, ft_ltoa_base_maj(var->nb.l, 16));
			else if (var->type == TYPE_OCTAL || var->type == TYPE_OCTAL_MAJ)
				ft_flags_stock(var, s_flags, ft_ltoa_base(var->nb.l, 8));
			else
				ft_flags_stock(var, s_flags, ft_ltoa(var->nb.l));
		}
	}
	return (1);
}
