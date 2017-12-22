/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags_buffer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 16:14:24 by elbenkri          #+#    #+#             */
/*   Updated: 2017/12/22 18:10:34 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static void	ft_flags_precision(t_var *var, t_flags *s_flags)
{
	int		i;

	i = 0;
	if (s_flags->largeur > s_flags->precision)
	{
		var->i_buf_tmp = (s_flags->c & (1 << 2)) ?
			0 : s_flags->largeur - s_flags->precision;
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
		while (i < var->i_buf_tmp)
			var->buf[var->i_buf++] = var->buf_tmp[i++];
		printf("lilililili :%s\n", var->buf_tmp);
	}
}

static void	ft_flags_largeur(t_var *var, t_flags *s_flags, int i)
{
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
	while (i < var->i_buf_tmp)
	{
		if ((s_flags->c & (1 << 2)))
			var->buf[var->i_buf++] = var->buf_tmp[i++];
		else
			var->buf[var->i_buf++] = var->buf_tmp[++i];
	}
	printf("lilililili :%s\n", var->buf_tmp);
}

int			ft_print_flags_buffer(t_var *var, t_flags *s_flags)
{
	if (var->type == TYPE_STRING)
	{
		var->i_buf_tmp = 0;
		if (s_flags->precision < (int)ft_strlen(var->res))
			ft_flags_precision(var, s_flags);
		else
			ft_flags_largeur(var, s_flags, 0);
	}
	else
	{
		;
	}
	return (1);
}
