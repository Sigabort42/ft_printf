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
		ft_memcpy(&var->buf_tmp[var->i_buf_tmp], var->res, s_flags->precision);
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
		;
	}
	return (1);
}
