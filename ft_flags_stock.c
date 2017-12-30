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

static int		ft_stock_buf_base(t_var *var, t_flags *s_flags, int res_strcmp, int len_str_hexa)
{
	int	i;

	i = 0;
	if (!res_strcmp && len_str_hexa == 1 && s_flags->m == 0 && s_flags->c >= 1 && s_flags->c <= 16 && (!var->i_buf || (var->type == TYPE_OCTAL || var->type == TYPE_OCTAL_MAJ)))
	  {
		if (var->i_plus)
		  var->buf[var->i_buf++] = '+';
		var->buf[var->i_buf++] = '0';
	  }
	else if ((s_flags->c & (1 << 4)) && (var->type >= TYPE_HEXA && var->type <= TYPE_HEXA_MAJ) && res_strcmp)
	{
		i = 2;
		if (var->type == TYPE_HEXA && len_str_hexa)
		{
			ft_memcpy(&var->buf_tmp[var->i_buf_tmp], "0x", i);
			var->i_buf_tmp += i;
		}
		else if (var->type == TYPE_HEXA_MAJ && len_str_hexa)
		{
			ft_memcpy(&var->buf_tmp[var->i_buf_tmp], "0X", i);
			var->i_buf_tmp += i;
		}
	}
	else if ((s_flags->c & (1 << 4)) && (var->type >= TYPE_OCTAL && var->type <= TYPE_OCTAL_MAJ) && res_strcmp)
	{
		i = 1;
		if (var->type == TYPE_OCTAL && len_str_hexa)
		{
			ft_memcpy(&var->buf_tmp[var->i_buf_tmp], "0", i);
			var->i_buf_tmp += i;
		}
		else if (var->type == TYPE_OCTAL_MAJ && len_str_hexa)
		{
			ft_memcpy(&var->buf_tmp[var->i_buf_tmp], "0", i);
			var->i_buf_tmp += i;
		}
	}
	return (i);
}

static int		ft_stock_moins(t_var *var, t_flags *s_flags, int len_str_hexa, char *str_hexa)
{
  len_str_hexa = 0;
  (void)s_flags;
  //&& s_flags->largeur >= s_flags->precision && s_flags->largeur > len_str_hexa
	if (str_hexa[0] == '-')
	{
		var->buf_tmp[var->i_buf_tmp++] = '-';
		return (1);
	}
	return (0);
}

static int		ft_stock_plus(t_var *var, t_flags *s_flags, char *str_hexa)
{
	if (str_hexa[0] != '-' && s_flags->c & (1 << 1) && var->type <= TYPE_INT)
	{
		var->buf_tmp[var->i_buf_tmp++] = '+';
		return (1);
	}
	return (0);
}

void		ft_flags_stock(t_var *var, t_flags *s_flags, char *str_hexa)
{
	int	k;
	int	len_str_hexa;
	int	res_strcmp;

	res_strcmp = ft_strcmp(str_hexa, "0");
	len_str_hexa = ft_strlen(str_hexa);
	var->i_buf_tmp = 0;
	if (s_flags->c == 8 && s_flags->m == 0 && !s_flags->largeur && !s_flags->precision && var->type == TYPE_SHORT && str_hexa[0] != '-')
	  var->buf[var->i_buf++] = ' ';
	if (s_flags->precision >= s_flags->largeur && s_flags->precision >= len_str_hexa)
	{
		var->i_moins = ft_stock_moins(var, s_flags, len_str_hexa, str_hexa);
		k = s_flags->precision - len_str_hexa + var->i_moins;
		ft_memset(&var->buf_tmp[var->i_buf_tmp], '0', k);
		var->i_buf_tmp += k;
		ft_memcpy(&var->buf_tmp[var->i_buf_tmp], &str_hexa[var->i_moins], len_str_hexa);
		ft_memcpy(&var->buf[var->i_buf], var->buf_tmp, var->i_buf_tmp + len_str_hexa);
		var->i_buf += var->i_buf_tmp + len_str_hexa - var->i_moins;
		(!len_str_hexa && !s_flags->precision && (var->type >= TYPE_OCTAL && var->type <= TYPE_HEXA_MAJ)) ? ft_memcpy(&var->buf[var->i_buf++], "0", 1) : 0;
	}
	else if (s_flags->largeur > s_flags->precision && s_flags->precision >= len_str_hexa)
	{
		if ((s_flags->c & (1 << 2)))
		{
			ft_stock_plus(var, s_flags, str_hexa);
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
			var->i_moins = ft_stock_moins(var, s_flags, len_str_hexa, str_hexa);
			var->i_plus = (s_flags->c & (1 << 1)) ? 1 : 0;
			k = ((var->type == TYPE_HEXA || var->type == TYPE_HEXA_MAJ) && len_str_hexa) ? s_flags->largeur - s_flags->precision - 2 : s_flags->largeur - s_flags->precision - var->i_moins - var->i_plus;
 			ft_memset(&var->buf_tmp[0], ' ', k);
			var->i_buf_tmp += k;
			ft_stock_plus(var, s_flags, str_hexa);
			(var->type == TYPE_HEXA && len_str_hexa) ? ft_memcpy(&var->buf_tmp[var->i_buf_tmp - 2], "0x", 2) : 0;
			(var->type == TYPE_HEXA_MAJ && len_str_hexa) ? ft_memcpy(&var->buf_tmp[var->i_buf_tmp - 2], "0X", 2) : 0;
			k = s_flags->precision - len_str_hexa + var->i_moins;
			ft_memset(&var->buf_tmp[var->i_buf_tmp], '0', k);
			var->i_buf_tmp += k;
			ft_memcpy(&var->buf_tmp[var->i_buf_tmp], &str_hexa[var->i_moins], len_str_hexa);
			var->i_buf_tmp += len_str_hexa;
			ft_memcpy(&var->buf[var->i_buf], var->buf_tmp, var->i_buf_tmp + len_str_hexa);
			var->i_buf += s_flags->largeur;
			(!len_str_hexa && (var->type >= TYPE_OCTAL && var->type <= TYPE_HEXA_MAJ)) ? ft_memcpy(&var->buf[var->i_buf - 1], "0", 1) : 0;
		}
	}
	else if (s_flags->largeur < len_str_hexa)
	{
		var->i_plus = ft_stock_plus(var, s_flags, str_hexa);
		ft_stock_buf_base(var, s_flags, res_strcmp, len_str_hexa);
		if (!res_strcmp && len_str_hexa == 1 && s_flags->m == 0 && s_flags->c <= 16)
			return ;
		ft_memcpy(&var->buf_tmp[var->i_buf_tmp], str_hexa, len_str_hexa);
		ft_memcpy(&var->buf[var->i_buf], var->buf_tmp, var->i_buf_tmp + len_str_hexa);
		var->i_buf += var->i_buf_tmp + len_str_hexa;
	}
	else if (s_flags->largeur >= s_flags->precision)
	{
		if ((s_flags->c & (1 << 2)))
		{
			ft_stock_buf_base(var, s_flags, res_strcmp, len_str_hexa);
			ft_memcpy(&var->buf_tmp[var->i_buf_tmp], str_hexa, len_str_hexa);
			var->i_buf_tmp += len_str_hexa;
			k = (len_str_hexa) ? s_flags->largeur - s_flags->precision - len_str_hexa : s_flags->largeur - s_flags->precision;
			ft_memset(&var->buf_tmp[var->i_buf_tmp], ' ', k);
			var->i_buf_tmp += k;
			ft_memcpy(&var->buf[var->i_buf], var->buf_tmp, var->i_buf_tmp + len_str_hexa);
			var->i_buf += s_flags->largeur;
		}
		else if ((s_flags->c & (1 << 0)))
		{
			  var->i_moins = ft_stock_moins(var, s_flags, len_str_hexa, str_hexa);
			  var->i_plus = ft_stock_plus(var, s_flags, str_hexa);
			  k = (len_str_hexa) ? s_flags->largeur - s_flags->precision - len_str_hexa - ft_stock_buf_base(var, s_flags, res_strcmp, len_str_hexa) - var->i_plus : s_flags->largeur - s_flags->precision;
			  ft_memset(&var->buf_tmp[var->i_buf_tmp], '0', k);
			  var->i_buf_tmp += k;
			  ft_memcpy(&var->buf_tmp[var->i_buf_tmp], &str_hexa[var->i_moins], len_str_hexa);
			  var->i_buf_tmp += len_str_hexa;
			  ft_memcpy(&var->buf[var->i_buf], var->buf_tmp, var->i_buf_tmp + len_str_hexa);
			  var->i_buf += s_flags->largeur;
		}
		else if ((s_flags->c & (1 << 4)))
		{
			k = s_flags->largeur - len_str_hexa - ft_stock_buf_base(var, s_flags, res_strcmp, len_str_hexa);
			ft_memset(&var->buf_tmp[0], ' ', k);
			var->i_buf_tmp = k;
			ft_stock_buf_base(var, s_flags, res_strcmp, len_str_hexa);
			ft_memcpy(&var->buf_tmp[var->i_buf_tmp], str_hexa, len_str_hexa);
			var->i_buf_tmp += len_str_hexa;
			ft_memcpy(&var->buf[var->i_buf], var->buf_tmp, var->i_buf_tmp + len_str_hexa);
			var->i_buf += s_flags->largeur;
		}
		else
		{
			if(s_flags->largeur >= s_flags->precision + len_str_hexa && res_strcmp)
				k = s_flags->largeur - s_flags->precision - len_str_hexa;
			else if (s_flags->precision < len_str_hexa && res_strcmp)
				k = s_flags->largeur - len_str_hexa;
			else
				k = s_flags->largeur - s_flags->precision;
			ft_memset(&var->buf_tmp[var->i_buf_tmp], ' ', k);
			var->i_buf_tmp += k;
			if (!(!res_strcmp && len_str_hexa == 1 && s_flags->m == 0))
			{
				ft_memcpy(&var->buf_tmp[var->i_buf_tmp], str_hexa, len_str_hexa);
				var->i_buf_tmp += len_str_hexa;
			}
			ft_memcpy(&var->buf[var->i_buf], var->buf_tmp, var->i_buf_tmp + len_str_hexa);
			var->i_buf += s_flags->largeur;
		}
	}
}
