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

	if (!var->res && var->type == TYPE_STRING)
		var->res = tab;
	else if (!s_flags->precision)
		s_flags->precision = (int)ft_strlen(var->res);
	var->i_buf_tmp = (s_flags->c & (1 << 2)) ?
	  0 : s_flags->largeur - s_flags->precision;
	if (var->res)
		(var->i_buf_tmp < 0) ? ft_memcpy(&var->buf_tmp[0], var->res, s_flags->precision)
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
	if (var->type == TYPE_CHAR && !var->nb.c && ft_strlen(var->buf_tmp))
		var->buf[var->i_buf - 1] = var->nb.c;
	else if (var->type == TYPE_CHAR && !var->nb.c && !ft_strlen(var->buf_tmp))
		var->buf[var->i_buf++] = var->nb.c;
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
	if (var->type == TYPE_CHAR && !var->nb.c && ft_strlen(var->buf_tmp))
		var->buf[var->i_buf - 1] = var->nb.c;
	else if (var->type == TYPE_CHAR && !var->nb.c && !ft_strlen(var->buf_tmp))
		var->buf[var->i_buf++] = var->nb.c;
}

static void		ft_conv_envoi(va_list ap, t_var *var, t_flags *s_flags, int base)
{
  if (var->type == TYPE_UNSIGNED_MAJ || var->type == TYPE_OCTAL_MAJ || var->type == TYPE_BITWISE)
      ft_flags_stock(var, s_flags, ft_lltoa_base(va_arg(ap, unsigned long), base));
  else if ((s_flags->m & (1 << 3)) || var->type == TYPE_SHORT_MAJ)
      ft_flags_stock(var, s_flags, ft_ltoa_base(va_arg(ap, long long), base));
  else if ((s_flags->m & (1 << 0)) && (var->type >= TYPE_UNSIGNED && var->type <= TYPE_HEXA_MAJ))
    ft_flags_stock(var, s_flags, ft_itoa_base((unsigned char)va_arg(ap, int), base));
  else if ((s_flags->m & (1 << 0)))
    ft_flags_stock(var, s_flags, ft_itoa_base((char)va_arg(ap, int), base));
  else if ((s_flags->m & (1 << 1)) && (var->type >= TYPE_UNSIGNED && var->type <= TYPE_HEXA_MAJ))
      ft_flags_stock(var, s_flags, ft_itoa_base((unsigned short)va_arg(ap, int), base));
  else if ((s_flags->m & (1 << 1)))
    ft_flags_stock(var, s_flags, ft_itoa_base((short)va_arg(ap, int), base));
  else if ((s_flags->m & (1 << 2)) && (var->type >= TYPE_UNSIGNED && var->type <= TYPE_HEXA_MAJ))
    ft_flags_stock(var, s_flags, ft_lltoa_base(va_arg(ap, long long), base));
  else if ((s_flags->m & (1 << 2)))
    ft_flags_stock(var, s_flags, ft_ltoa_base(va_arg(ap, long long), base));
  else if ((s_flags->m & (1 << 4)) && (var->type >= TYPE_UNSIGNED && var->type <= TYPE_HEXA_MAJ))
    ft_flags_stock(var, s_flags, ft_ui_maxtoa_base(va_arg(ap, uintmax_t), base));
  else if ((s_flags->m & (1 << 4)))
    ft_flags_stock(var, s_flags, ft_i_maxtoa_base(va_arg(ap, intmax_t), base));
  else if ((s_flags->m & (1 << 5)) && (var->type >= TYPE_UNSIGNED && var->type <= TYPE_HEXA_MAJ))
      ft_flags_stock(var, s_flags, ft_ui_maxtoa_base(va_arg(ap, ssize_t), base));
  else if ((s_flags->m & (1 << 5)))
    ft_flags_stock(var, s_flags, ft_ltoa_base(va_arg(ap, ssize_t), base));
  else
    {
      if (var->type <= TYPE_INT && s_flags->m == 0)
	ft_flags_stock(var, s_flags, ft_itoa_base(va_arg(ap, int), base));
      else
	ft_flags_stock(var, s_flags, ft_lltoa_base(va_arg(ap, unsigned int), base));
    }
}

static void		ft_conv_envoi_maj(va_list ap, t_var *var, t_flags *s_flags, int base)
{
  if ((s_flags->m & (1 << 3)))
    ft_flags_stock(var, s_flags, ft_ltoa_base_maj(va_arg(ap, long long), base));
  else if ((s_flags->m & (1 << 0)) && (var->type == TYPE_OCTAL_MAJ || var->type == TYPE_UNSIGNED_MAJ))
    ft_flags_stock(var, s_flags, ft_itoa_base_maj((unsigned short)va_arg(ap, int), base));
  else if ((s_flags->m & (1 << 0)) && (var->type >= TYPE_UNSIGNED && var->type <= TYPE_HEXA_MAJ))
    ft_flags_stock(var, s_flags, ft_itoa_base_maj((unsigned char)va_arg(ap, int), base));
  else if ((s_flags->m & (1 << 0)))
    ft_flags_stock(var, s_flags, ft_itoa_base_maj((char)va_arg(ap, int), base));
  else if ((s_flags->m & (1 << 1)) && (var->type >= TYPE_UNSIGNED && var->type <= TYPE_HEXA_MAJ))
      ft_flags_stock(var, s_flags, ft_itoa_base_maj((unsigned short)va_arg(ap, int), base));
  else if ((s_flags->m & (1 << 1)))
    ft_flags_stock(var, s_flags, ft_itoa_base_maj((short)va_arg(ap, int), base));
  else if ((s_flags->m & (1 << 2)) && (var->type >= TYPE_UNSIGNED && var->type <= TYPE_HEXA_MAJ))
    ft_flags_stock(var, s_flags, ft_lltoa_base_maj(va_arg(ap, long long), base));
  else if ((s_flags->m & (1 << 2)))
    ft_flags_stock(var, s_flags, ft_ltoa_base_maj(va_arg(ap, long), base));
  else if ((s_flags->m & (1 << 4)))
    ft_flags_stock(var, s_flags, ft_ui_maxtoa_base_maj(va_arg(ap, uintmax_t), base));
  else if ((s_flags->m & (1 << 5)) && (var->type >= TYPE_UNSIGNED && var->type <= TYPE_HEXA_MAJ))
      ft_flags_stock(var, s_flags, ft_ui_maxtoa_base_maj(va_arg(ap, ssize_t), base));
  else if ((s_flags->m & (1 << 5)))
    ft_flags_stock(var, s_flags, ft_ltoa_base_maj(va_arg(ap, size_t), base));
  else
    {
      if (var->type <= TYPE_INT && s_flags->m == 0)
	ft_flags_stock(var, s_flags, ft_itoa_base_maj(va_arg(ap, int), base));
      else
	ft_flags_stock(var, s_flags, ft_lltoa_base_maj(va_arg(ap, unsigned int), base));
    }
}

int			ft_print_flags_buffer(va_list ap, t_var *var, t_flags *s_flags)
{
  char	tab[] = "(null)";

  var->res = NULL;
  if (var->type == TYPE_STRING || var->type == TYPE_CHAR || var->type == TYPE_MODULO || var->type == TYPE_NON_CONNU)
    {
      var->i_buf_tmp = 0;
      if (var->type == TYPE_MODULO)
	{
	  var->nb.c = '%';
	  var->res = &var->nb.c;
	  var->res[1] = 0;
	}
      else if (var->type == TYPE_CHAR)
	{
	  var->nb.c = va_arg(ap, int);
	  var->res = &var->nb.c;
	  var->res[1] = 0;
	}
      else if (var->type == TYPE_STRING)
	var->res = va_arg(ap, char*);
      else if (var->type == TYPE_NON_CONNU)
      {
	  var->res = &var->nb.c;
	  var->res[1] = 0;
      }
      if (var->res)
	{
	  if (s_flags->precision < (int)ft_strlen(var->res))
	    ft_flags_precision(var, s_flags, 0);
	  else
	    ft_flags_largeur(var, s_flags, 0);
	}
      else
	{
	  var->res = (var->type == TYPE_STRING) ? tab : 0;
	  ft_flags_precision(var, s_flags, 0);
	}
    }
  else
    {
      if (var->type == TYPE_ADDRESS)
	  ft_flags_stock(var, s_flags, ft_lltoa_base(va_arg(ap, unsigned long), 16));
      else if (var->type == TYPE_HEXA)
	ft_conv_envoi(ap, var, s_flags, 16);
      else if (var->type == TYPE_HEXA_MAJ)
	ft_conv_envoi_maj(ap, var, s_flags, 16);
      else if (var->type == TYPE_OCTAL)
	ft_conv_envoi(ap, var, s_flags, 8);
      else if (var->type == TYPE_OCTAL_MAJ)
	ft_conv_envoi_maj(ap, var, s_flags, 8);
      else if (var->type == TYPE_BITWISE)
	ft_conv_envoi(ap, var, s_flags, 2);
      else
	ft_conv_envoi(ap, var, s_flags, 10);
    }
  return (1);
}
